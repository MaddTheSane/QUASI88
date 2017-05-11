//
//  graph.m
//  Quasi88
//
//  Created by C.W. Betts on 5/2/17.
//  Copyright (c) 2017 C.W. Betts. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#include <CoreGraphics/CoreGraphics.h>

#include "quasi88.h"
#include "graph.h"
#include "device.h"
#include "getconf.h"


static	T_GRAPH_SPEC	graph_spec;		/* 基本情報		*/

static	int		graph_exist;		/* 真で、画面生成済み	*/
static	T_GRAPH_INFO	graph_info;		/* その時の、画面情報	*/
static int	nr_color_used;

const T_GRAPH_INFO	*graph_setup(int width, int height,
				     int fullscreen, double aspect)
{
	T_GRAPH_INFO *info = &graph_info;
	
	NSBitmapImageRep *imgRep = [[NSBitmapImageRep alloc] initWithBitmapDataPlanes:NULL pixelsWide:width pixelsHigh:height bitsPerSample:8 samplesPerPixel:4 hasAlpha:YES isPlanar:NO colorSpaceName:NSDeviceRGBColorSpace bytesPerRow:width * 4 bitsPerPixel:32];
	
	info->fullscreen    = FALSE;
	info->width         = width;
	info->height        = height;
	info->byte_per_pixel = 4;
	info->buffer		= imgRep.bitmapData;
	Quasi88ApplicationDelegate *appDel = [NSApp delegate];
	appDel.imgBase = imgRep;
	[imgRep release];


	return info;
}

const T_GRAPH_SPEC *graph_init(void)
{
	@autoreleasepool {
	int	win_w, win_h;
	int	ful_w, ful_h;
		NSScreen *ourScreen;
	
	if (verbose_proc) {
		printf("Initializing Graphic System ... \n");
	}
	
		ourScreen = [NSScreen mainScreen];
	/* 画面サイズを取得する方法は? */
	win_w = 10000;
	win_h = 10000;
	ful_w = ourScreen.frame.size.width;
	ful_h = ourScreen.frame.size.height;
	
	graph_spec.window_max_width      = win_w;
	graph_spec.window_max_height     = win_h;
	graph_spec.fullscreen_max_width  = ful_w;
	graph_spec.fullscreen_max_height = ful_h;
	graph_spec.forbid_status         = FALSE;
	graph_spec.forbid_half           = FALSE;
	
		if (verbose_proc) {
		//printf("  INFO: %dbpp->%dbpp(%dbyte), Maxsize=win(%d,%d),full(%d,%d)\n",
		//	   (int)displayOrigDepth, (int)displayDepth, (int)displayDepth/8,
		//	   win_w, win_h, ful_w, ful_h);
		}
	
	// to get key up event
	//SetEventMask(everyEvent);
	
	/* パレットを初期化する */
	if (verbose_proc) printf("  Color Initialized\n");
	//InitColor();
	
	return &graph_spec;
	}
}

void graph_remove_color(int nr_pixel, unsigned long pixel[])
{
	nr_color_used -= nr_pixel;
}

void graph_add_color(const PC88_PALETTE_T color[],
					 int nr_color, unsigned long pixel[])
{
	
}

void graph_update(int nr_rect, T_GRAPH_RECT rect[])
{
	
}

static int storedMouseShow, storedGrab, storedKeyRepeatOn;

void graph_set_attribute(int mouse_show, int grab, int keyrepeat_on)
{
	if (mouse_show != storedMouseShow) {
		if (mouse_show) {
			[NSCursor unhide];
		} else {
			[NSCursor hide];
		}
		storedMouseShow = mouse_show;
	}
	/* 設定の仕方がわからない… */
	(void)grab;
	(void)keyrepeat_on;
}

void graph_exit(void)
{
	[NSApp terminate:nil];
}

void graph_set_window_title(const char *title)
{
	@autoreleasepool {
		NSStringEncoding ourEncoding;
		switch (file_coding) {
			case 0:
				ourEncoding = NSJapaneseEUCStringEncoding;
				break;
				
			case 1:
				ourEncoding = NSShiftJISStringEncoding;
				break;
				
			case 2:
				ourEncoding = NSUTF8StringEncoding;
				break;
				
			default:
				// unknown encoding, use MacRoman to spit out gibberish
				ourEncoding = NSMacOSRomanStringEncoding;
				break;
		}
		
		NSString *nsTitle = [[NSString alloc] initWithCString:title encoding:ourEncoding];
		
		Quasi88ApplicationDelegate *appDel = [NSApp delegate];
		appDel.mainWindow.title = nsTitle;
		[nsTitle release];
	}
}

