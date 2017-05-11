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
	/* 一部の初期値を改変 (いいやり方はないかな…) */
	romaji_type = 1;			/* ローマ字変換の規則を MS-IME風に */
	
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
 * ステートロード／ステートセーブ
 ************************************************************************/

/*	他の情報すべてがロード or セーブされた後に呼び出される。
 *	必要に応じて、システム固有の情報を付加してもいいかと。
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
 * メニュー画面に表示する、システム固有メッセージ
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
		"速度に関する設定は変更できません\n"
		"マウス、ジョイスティックは使用できません\n"
		"マウスカーソルの表示制御はサポートされていません\n"
		"ソフトウェア NumLock はサポートされていません\n"
		"キー設定ファイルの読み込みはサポートされていません\n"
	};
	
	
	*result_code = -1;				/* 文字コード指定なし */
	
	if (req_japanese == FALSE) {
		*message = about_en;
	} else {
		*message = about_jp;
	}
	
	return TRUE;
}
