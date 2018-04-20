/***********************************************************************
 * ��������Ĵ������ (�����ƥ��¸)
 *
 *      �ܺ٤ϡ� wait.h ����
 ************************************************************************/

#include "quasi88.h"
#include "device.h"
#include "wait.h"

#include <CoreServices/CoreServices.h>
#include <mach/mach_time.h>


/*---------------------------------------------------------------------------*/
static	int	wait_counter = 0;		/* Ϣ³������֥����С�������*/
static	int	wait_count_max = 10;		/* ����ʾ�Ϣ³�����С�������
						   ��ö,����Ĵ������������ */

/* �������Ȥ˻��Ѥ�����֤�����ɽ���ϡ� usñ�̤Ȥ��롣 (ms�������٤��㤤�Τ�) 

   ToolBox �λ�������ؿ� TickCount() �� 1/60s ñ�̤��ͤ��֤���
   ��������� us ���Ѵ����ƻ��Ѥ��뤳�Ȥˤ��롣
   ����ɽ���� long ���ˤ���ȡ�71ʬ�Ƿ夢�դ�(wrap)�򵯤����Ƥ��ޤ������νִ֤�
   �������ʤ�Τˤʤ� (�������Ȼ��֤��Ѥˤʤ�) ��
   �Ǥ���� 64bit��(long long)�ˤ��������ɡ��ɤ����������Ƥʤ� ? */

typedef	uint64_t T_WAIT_TICK;

static	T_WAIT_TICK	next_time;		/* ���ե졼��λ��� */
static	T_WAIT_TICK	delta_time;		/* 1 �ե졼��λ��� */
static mach_timebase_info_data_t tbInfo;



/* ---- ���߻����������� (usecñ��) ---- */

#define	GET_TICK()	( (T_WAIT_TICK)mach_absolute_time() )





/****************************************************************************
 * ��������Ĵ�������ν��������λ
 *****************************************************************************/
int	wait_vsync_init(void)
{
	mach_timebase_info(&tbInfo);

    return TRUE;
}

void	wait_vsync_exit(void)
{
}



/****************************************************************************
 * ��������Ĵ������������
 *****************************************************************************/
void	wait_vsync_setup(long vsync_cycle_us, int do_sleep)
{
    wait_counter = 0;


    delta_time = (T_WAIT_TICK)(1000000.0 / 60.0);	/* 1�ե졼����� */
    next_time  = GET_TICK() + delta_time;		/* ���ե졼����� */


    /* ���� vsync_cycle_us, do_sleep ��̵�뤹�� */
}



/****************************************************************************
 * ��������Ĵ�������μ¹�
 *****************************************************************************/
int	wait_vsync_update(void)
{
    bool on_time = FALSE;
    T_WAIT_TICK diff_us;


    diff_us = next_time - GET_TICK();

	if (diff_us > 0) {			/* �٤�Ƥʤ�(���֤�;�äƤ���)�ʤ� */
		
#if 0					/* �ӥ����������Ȥ���Ȥ����롩  */
		while (GET_TICK() <= next_time)
			;
		
#else					/* Delay ���Ƥߤ롦���� */
		diff_us = diff_us * 60 / 1000000 * tbInfo.numer / tbInfo.denom;
		if (diff_us) {
			mach_wait_until(diff_us);
		}
#endif
		
		on_time = TRUE;
	}


    /* ���ե졼�����򻻽� */
    next_time += delta_time;


    if (on_time) {			/* ������˽����Ǥ��� */
	wait_counter = 0;
    } else {				/* ������˽����Ǥ��Ƥ��ʤ� */
	wait_counter ++;
	if (wait_counter >= wait_count_max) {	/* �٤줬�Ҥɤ����� */
	    wait_vsync_setup(0,0);		/* �������Ȥ�����   */
	}
    }

    if (on_time) return WAIT_JUST;
    else         return WAIT_OVER;
}
