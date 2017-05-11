#ifndef DEVICE_H_INCLUDED
#define DEVICE_H_INCLUDED


#include <CoreGraphics/CoreGraphics.h>
#include <Carbon/Carbon.h>

#ifdef __OBJC__
#import <Cocoa/Cocoa.h>


@interface Quasi88ApplicationDelegate : NSObject <NSApplicationDelegate>
{
	NSWindow *mainWindow;
	NSBitmapImageRep *imgBase;
}
@property (assign) IBOutlet NSWindow *mainWindow;
@property (retain) NSBitmapImageRep *imgBase;

@end

#endif

//#include <QuickTime.h>


/*
 *	src/CLASSIC/ �ʲ��ǤΥ����Х��ѿ�
 */
extern	WindowRef	macWin;
extern	GWorldPtr	macGw;

//extern	QDGlobals	macQd;



/*
 *	src/CLASSIC/ �ʲ��ǤΥ����Х��ѿ� (���ץ���������ǽ���ѿ�)
 */
extern	int		mac_8bpp;	/* ͥ��Ū�ˡ�256���⡼�ɤ�ư����� */



void	mac_init(void);
void	mac_exit(void);

Boolean mac_create_menubar(void);
void	menubar_setup(int active);
void	doMenuCommand(long menuResult);
void	mac_error_dialog(const char *message);

int	mac_is_fullscreen(void);
void	mac_draw_immidiate(void);


#endif	/* DEVICE_H_INCLUDED */
