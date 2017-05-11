//
//  main.m
//  Quasi88
//
//  Created by C.W. Betts on 5/2/17.
//  Copyright (c) 2017 C.W. Betts. All rights reserved.
//

#import <AppKit/NSApplication.h>

#include "quasi88.h"
#include "device.h"

#include "getconf.h"	/* config_init */
#include "keyboard.h"	/* romaji_type */
#include "suspend.h"	/* stateload_system */
#include "menu.h"	/* menu_about_osd_msg */

#include "intr.h"
#include "screen.h"

int main(int argc, const char * argv[]) {
	/* �����ν���ͤ���� (����������Ϥʤ����ʡ�) */
	romaji_type = 1;			/* ���޻��Ѵ��ε�§�� MS-IME���� */
	
	return NSApplicationMain(argc, argv);
}

@implementation Quasi88ApplicationDelegate
@synthesize mainWindow;
@synthesize imgBase;

- (void)applicationDidFinishLaunching:(NSNotification *)notification
{
	quasi88();
}

- (void)applicationWillTerminate:(NSNotification *)notification
{
	config_exit();
}

@end

/***********************************************************************
 * ���ơ��ȥ��ɡ����ơ��ȥ�����
 ************************************************************************/

/*	¾�ξ��󤹤٤Ƥ����� or �����֤��줿��˸ƤӽФ���롣
 *	ɬ�פ˱����ơ������ƥ��ͭ�ξ�����ղä��Ƥ⤤�����ȡ�
 */

int	stateload_system( void )
{
	return TRUE;
}
int	statesave_system( void )
{
	return TRUE;
}

/***********************************************************************
 * ��˥塼���̤�ɽ�����롢�����ƥ��ͭ��å�����
 ************************************************************************/

int	menu_about_osd_msg(int        req_japanese,
					   int        *result_code,
					   const char *message[])
{
	static const char *about_en =
	{
		"Mouse and joystick are not supported.\n"
		"\n"
		"Many many menu items are not available.\n"
	};
	
	static const char *about_jp =
	{
		"®�٤˴ؤ���������ѹ��Ǥ��ޤ���\n"
		"�ޥ��������祤���ƥ��å��ϻ��ѤǤ��ޤ���\n"
		"�ޥ������������ɽ������ϥ��ݡ��Ȥ���Ƥ��ޤ���\n"
		"���եȥ����� NumLock �ϥ��ݡ��Ȥ���Ƥ��ޤ���\n"
		"��������ե�������ɤ߹��ߤϥ��ݡ��Ȥ���Ƥ��ޤ���\n"
	};
	
	
	*result_code = -1;				/* ʸ�������ɻ���ʤ� */
	
	if (req_japanese == FALSE) {
		*message = about_en;
	} else {
		*message = about_jp;
	}
	
	return TRUE;
}
