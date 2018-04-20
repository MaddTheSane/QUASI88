//
//  event-IOKit.c
//  Quasi88
//
//  Created by C.W. Betts on 4/19/18.
//  Copyright © 2018 C.W. Betts. All rights reserved.
//

/***********************************************************************
 * イベント処理 (システム依存)
 *
 *	詳細は、 event.h 参照
 ************************************************************************/

#include "quasi88.h"
#include "device.h"

#include "event.h"
#include "keyboard.h"
#include <IOKit/IOKitLib.h>
#include <CoreGraphics/CoreGraphics.h>




/******************************************************************************
 * イベントハンドリング
 *
 *	1/60毎に呼び出される。
 *****************************************************************************/

/*
 * これは 起動時に1回だけ呼ばれる
 */
void	event_init(void)
{
}



/*
 * 約 1/60 毎に呼ばれる
 */
void	event_update(void)
{
	bool loop = true;
	while (loop) {
		
	}
	
}

/*
 * これは 終了時に1回だけ呼ばれる
 */
void	event_exit(void)
{
}




/***********************************************************************
 * 現在のマウス座標取得関数
 *
 ************************************************************************/

void	event_get_mouse_pos(int *x, int *y)
{
	*x = 0;
	*y = 0;
}


/******************************************************************************
 * ソフトウェア NumLock 有効／無効
 *
 *****************************************************************************/

int	event_numlock_on (void)
{
	return FALSE;
}
void	event_numlock_off(void)
{
}



/******************************************************************************
 * エミュレート／メニュー／ポーズ／モニターモード の 開始時の処理
 *
 *****************************************************************************/

void	event_switch(void)
{
}



/******************************************************************************
 * ジョイスティック
 *
 *****************************************************************************/

int	event_get_joystick_num(void)
{
	return 0;
}
