#ifndef	CONFIG_H_INCLUDED
#define	CONFIG_H_INCLUDED


/*----------------------------------------------------------------------*/
/* Classic�˴ؤ������							*/
/*----------------------------------------------------------------------*/

#include <MacTypes.h>


/* Classic�� QUASI88 �Τ���μ����� */

//#ifndef	QUASI88_CLASSIC
//#define	QUASI88_CLASSIC
//#endif


#ifndef USE_SOUND
#define USE_SOUND
#endif

/* ����ǥ�����ͥ� */

#if __BIG_ENDIAN__
#undef	LSB_FIRST
#else
#define	LSB_FIRST
#endif

/* ��˥塼�Υ����ȥ롿�С������ɽ���ˤ��ɲä�ɽ��������� (Ǥ�դ�ʸ����) */

#define	Q_COMMENT	"Carbon port"



/* Classic�Ǥ� 8bpp(bit per pixel) ����Ȥ��� */
/* 16bpp ��¸���� */
#ifndef	SUPPORT_8BPP
#define	SUPPORT_8BPP
#endif
#ifndef	SUPPORT_16BPP
#define	SUPPORT_16BPP
#endif
#ifndef	SUPPORT_32BPP
#define	SUPPORT_32BPP
#endif



/*
  MAME/XMAME �Υ�����ɤ��Ȥ߹����硢
	USE_SOUND
  ��������Ƥ�����

  FMGEN ���Ȥ߹�����ϡ�
	USE_FMGEN
  ��������Ƥ�����

  �嵭�ϡ�����ѥ�����˰ʲ��Τ褦�ˤ���������롣
  gcc  �ξ�硢����ѥ���˥��ץ���� -DUSE_SOUND   �ʤɤȻ��ꤹ�롣
  VC++ �ξ�硢����ѥ���˥��ץ���� /D"USE_SOUND" �ʤɤȻ��ꤹ�롣
  MPW  �ξ�硢����ѥ���˥��ץ���� -d USE_SOUND  �ʤɤȻ��ꤹ�롣
*/




/*
 *	SC depend
 */

#ifdef	macintosh 

/* ������ɥɥ饤���Ѥˡ�PI(��)��M_PI(��)����� ��  SC�Ǥ�ɬ��? */
#ifndef PI
#define PI 3.14159265358979323846
#endif
#ifndef	M_PI
#define	M_PI	PI
#endif

#endif

#define CLIB_DECL

#endif	/* CONFIG_H_INCLUDED */
