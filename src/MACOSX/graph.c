/***********************************************************************
 * ����ե��å����� (�����ƥ��¸)
 *
 *	�ܺ٤ϡ� graph.h ����
 ************************************************************************/

/*----------------------------------------------------------------------*
 * Classic�С������Υ����������ɤ�����ʬ�ϡ�                          *
 * Koichi NISHIDA ��� Classic iP6 PC-6001/mk2/6601 emulator �Υ������� *
 * ���ͤˤ����Ƥ��������ޤ�����                                         *
 *                                                   (c) Koichi NISHIDA *
 *----------------------------------------------------------------------*/

#include <stdio.h>

#include "quasi88.h"
#include "graph.h"
#include "device.h"
#include "OldCarbHeaders.h"

#ifdef	SUPPORT_DOUBLE
//#error !
#endif

#ifndef __MOVIES__

extern OSErr EndFullScreen(Ptr, long);
extern OSErr BeginFullScreen(Ptr *, GDHandle, short *, short *, WindowRef *, RGBColor *, long);

enum {
	fullScreenHideCursor          = 1L << 0,
	fullScreenAllowEvents         = 1L << 1,
	fullScreenDontChangeMenuBar   = 1L << 2,
	fullScreenPreflightSize       = 1L << 3
};

#endif

/********************** �������Х��ѿ� **********************/

// main window & graphic world
WindowRef	macWin;
GWorldPtr	macGw;

//QDGlobals	macQd;

int		mac_8bpp = TRUE;	/* ͥ��Ū�ˡ�256���⡼�ɤ�ư����� */


/************************************************************************/
/* ���ɽ�����֡������餷�� */
#define WIN_X 20
#define WIN_Y 60

/* ��������ο�����Ȥ� */
#define	ALL_COLORS	(24)

// default palette
static PaletteHandle defPalette;
static int	nr_color_used;

static void InitColor(void);


static	T_GRAPH_SPEC	graph_spec;		/* ���ܾ���		*/

static	int		graph_exist;		/* ���ǡ����������Ѥ�	*/
static	T_GRAPH_INFO	graph_info;		/* ���λ��Ρ����̾���	*/


/************************************************************************
 *	CLASSIC�ν����
 *	CLASSIC�ν�λ
 ************************************************************************/
static unsigned long displayOrigDepth;
static unsigned long displayDepth;
static unsigned long chkSysDepth(void);

void	mac_init(void)
{
    //SysEnvRec sys;

    // initialize
    //InitGraf((Ptr) &macQd.thePort);
    //InitFonts();
    //InitWindows();
    //InitMenus();
    //TEInit();
    //InitDialogs(NULL);
    //InitCursor();

    // color QD check
    //SysEnvirons(1, &sys);
    //if (! sys.hasColorQD) ExitToShell();

    // depth check
#if 0
#ifdef	SUPPORT_16BPP
    if (mac_8bpp) displayDepth = 8;	/* 256���⡼��  ������˥����å����� */
    else          displayDepth = 16;	/* 32000���⡼�ɤ�����˥����å����� */
    if (! HasDepth(GetMainDevice(), displayDepth, 1, 1)) {
	if (displayDepth == 8) displayDepth = 16;
	else                   displayDepth = 8;
	if (! HasDepth(GetMainDevice(), displayDepth, 1, 1)) {
	    mac_error_dialog( "Sorry, 256 or 32000 Color mode only!" );
	    ExitToShell();
	}
    }
#else
    displayDepth = 8;
    if (! HasDepth(GetMainDevice(), displayDepth, 1, 1)) {
	mac_error_dialog( "Sorry, 256 Color mode only!" );
	ExitToShell();
    }
#endif
#else
	displayDepth = 32;
#endif

    // change depth
    displayOrigDepth = chkSysDepth();
    SetDepth(GetMainDevice(), displayDepth, 1, 1);

    // menu resource
#if 0
    {
	Handle menuBar;
	menuBar = GetNewMBar(128);
	if (! menuBar) ExitToShell();
	SetMenuBar(menuBar);
	DisposeHandle(menuBar);
	AppendResMenu(GetMenuHandle(128),'DRVR');
	DrawMenuBar();
    }
#else
	if (! mac_create_menubar()) ExitToShell();
#endif

    /*�������Ϥ�Roman��*/
    KeyScript(smKeyRoman);
}

/************************************************************************/

void	mac_exit(void)
{
    /*�������Ϥ򸵤��᤹*/
    KeyScript(smKeySwapScript);

    SetDepth(GetMainDevice(), displayOrigDepth, 1, 1);
    ExitToShell();
}

/*----------------------------------------------------------------------*/
// get depth of main device
static unsigned long chkSysDepth(void)
{
    GDHandle ghd;
    PixMapHandle phd;
    int depth = 1;
	
    ghd = GetMainDevice();
    phd = (*ghd)->gdPMap;
    if (!(depth = (*phd)->pixelSize))
	depth = 1;
    return depth;
}


/************************************************************************
 *	����ե��å������ν����
 *	����ե��å�������ư��
 *	����ե��å������ν�λ
 ************************************************************************/

const T_GRAPH_SPEC	*graph_init(void)
{
    int	win_w, win_h;
    int	ful_w, ful_h;

    if (verbose_proc) {
	printf("Initializing Graphic System ... \n");
    }


    /* ���̥����������������ˡ��? */
    win_w = 10000;
    win_h = 10000;
    ful_w = 640;
    ful_h = 480;

    graph_spec.window_max_width      = win_w;
    graph_spec.window_max_height     = win_h;
    graph_spec.fullscreen_max_width  = ful_w;
    graph_spec.fullscreen_max_height = ful_h;
    graph_spec.forbid_status         = FALSE;
    graph_spec.forbid_half           = FALSE;

    if (verbose_proc)
	printf("  INFO: %dbpp->%dbpp(%dbyte), Maxsize=win(%d,%d),full(%d,%d)\n",
	       (int)displayOrigDepth, (int)displayDepth, (int)displayDepth/8,
	       win_w, win_h, ful_w, ful_h);

    // to get key up event
    SetEventMask(everyEvent);

    /* �ѥ�åȤ��������� */
    if (verbose_proc) printf("  Color Initialized\n");
    InitColor();

    return &graph_spec;
}

/************************************************************************/

static void createWindow(int width, int height);
static void toWindowMode(void);
static void toFullscreenMode(int width, int height);


const T_GRAPH_INFO	*graph_setup(int width, int height,
				     int fullscreen, double aspect)
{
    T_GRAPH_INFO *info = &graph_info;

    /* aspect ��̤���� */

    if (verbose_proc){
	if (graph_exist) printf("Re-Initializing Graphic System ... \n");
	if (fullscreen) printf("  Trying full screen mode <%dx%d> ... ",
			       width, height);
	else            printf("  Opening window ... ");
    }

    if (graph_exist == FALSE) {			/* ��� */
	createWindow(width, height);
	if (fullscreen) {
	    toFullscreenMode(width, height);
	}
    } else {					/* 2���ܰʹ� */
	if (info->fullscreen) {
	    if (fullscreen) {				/* FULL �� FULL */

		toWindowMode();
		createWindow(width, height);
		toFullscreenMode(width, height);

	    } else {					/* FULL �� WIN */
		toWindowMode();
		/* ��������ľ���� toFullscreenMode �Τ�Ʊ���ʤ�������ס� */
		createWindow(width, height);
	    }

	} else {
	    if (fullscreen) {				/* WIN �� FULL */

		/* ��������ľ���� createWindow �Τ�Ʊ���ʤ�������ס� */
		createWindow(width, height);
		toFullscreenMode(width, height);

	    } else {					/* WIN �� WIN */
		createWindow(width, height);
	    }
	}
    }

    if (verbose_proc) printf("OK (%dx%d)\n", info->width, info->height);

    graph_exist = TRUE;

    info->byte_per_pixel = displayDepth / 8;
    info->nr_color	 = ALL_COLORS;
    info->write_only	 = FALSE;
    info->broken_mouse	 = (info->fullscreen) ? TRUE : FALSE;
    info->draw_start	 = NULL;
    info->draw_finish	 = NULL;
    info->dont_frameskip = FALSE;

    /* ���������١����ѺѤߤο��������ͤ��᤹ */
    nr_color_used = 1;
    return info;
}

/*======================================================================*/

static void createWindow(int width, int height)
{
    T_GRAPH_INFO *info = &graph_info;

    Rect rect;
    PixMapHandle pmh;	


    SetRect(&rect, WIN_X, WIN_Y, WIN_X + width, WIN_Y + height);
    // re-size window
    if (macWin) DisposeWindow(macWin);
    macWin = NewCWindow(NULL, &rect, "\p", true, documentProc, (WindowRef)-1L, false, 0);


    // re-create off screen
    if (macGw) {
	pmh = GetGWorldPixMap(macGw);
	UnlockPixels(pmh);
	DisposeGWorld(macGw);
    }
    SetRect(&rect, 0, 0, width, height);
    NewGWorld(&macGw, displayDepth, &rect, NULL, NULL, 0);
    pmh = GetGWorldPixMap(macGw);
    LockPixels(pmh);


    info->fullscreen    = FALSE;
    info->width         = width;
    info->height        = height;
    info->byte_per_line = ((**pmh).rowBytes & 0x3fff);
    info->buffer        = GetPixBaseAddr(pmh);

    //memset(info->buffer, 0x00, info->byte_per_line * info->height);

    if (displayDepth == 8) {
	PixMapHandle pixmap;
	CTabHandle ctab;
	GDHandle mainhd;
	RGBColor rgb;
	int i;

	NSetPalette(macWin, defPalette, pmAllUpdates);
	ActivatePalette(macWin);

	pixmap = GetGWorldPixMap(macGw);
	ctab = (*pixmap)->pmTable;
	mainhd = GetMainDevice();

	for (i=0; i<ALL_COLORS + 1; i++) {
	    GetEntryColor(defPalette, i, &rgb);
	    (*ctab)->ctTable[i].rgb = rgb;
	    (*ctab)->ctTable[i].value = i;
	}
	(*ctab)->ctSeed = (*(*(*mainhd)->gdPMap)->pmTable)->ctSeed;
    }
}


// for full screen
static Ptr screenRestore;
static WindowRef macWinRestore;


// change to window mode
static void toWindowMode(void)
{
    T_GRAPH_INFO *info = &graph_info;

    PixMapHandle pmh;

    if (displayDepth == 8) {
	macWin = macWinRestore;
    }

    EndFullScreen(screenRestore, 0);
    SetDepth(GetMainDevice(), displayDepth, 1, 1);	
    pmh = GetGWorldPixMap(macGw);

    info->fullscreen    = FALSE;
    /* info->width      = ;	toFullscreenMode ��	*/
    /* info->height     = ;	���ꤷ���������ˤʤ�	*/
    info->byte_per_line = ((**pmh).rowBytes & 0x3fff);
    info->buffer        = GetPixBaseAddr(pmh);

    if (displayDepth == 8) {
	NSetPalette(macWin, defPalette, pmAllUpdates);
	ActivatePalette(macWin);
    }
}

// change to full screen mode
static void toFullscreenMode(int width, int height)
{
    T_GRAPH_INFO *info = &graph_info;

    GDHandle mainDevice = GetMainDevice();
    PixMapHandle pmh;
    RGBColor black = {0, 0, 0};
    short screenWidth  = width;
    short screenHeight = height;


    if (displayDepth == 8) {
	macWinRestore = macWin;

	if (BeginFullScreen(&screenRestore, mainDevice, &screenWidth, &screenHeight,
			    &macWin, &black, fullScreenHideCursor) != noErr) return;
    } else {
	if (BeginFullScreen(&screenRestore, mainDevice, &screenWidth, &screenHeight,
			    NULL,    &black, fullScreenHideCursor) != noErr) return;
    }

    pmh = (**mainDevice).gdPMap;

    info->fullscreen    = TRUE;
    info->width         = screenWidth;
    info->height        = screenHeight;
    info->byte_per_line = ((**pmh).rowBytes & 0x3fff);
    info->buffer        = GetPixBaseAddr(pmh);

    //memset(info->buffer, 0x00, info->byte_per_line * info->height);

    if (displayDepth == 8) {
	NSetPalette(macWin, defPalette, pmAllUpdates);
	ActivatePalette(macWin);
    }
}


/************************************************************************/

void	graph_exit(void)
{
    if (graph_exist) {
	if (graph_info.fullscreen) toWindowMode();
	DisposeWindow(macWin);
    }
}



int	mac_is_fullscreen(void)
{
    if (graph_exist) {
	if (graph_info.fullscreen) return TRUE;
    }
    return FALSE;
}



/************************************************************************
 *	���γ���
 *	���β���
 ************************************************************************/

void	graph_add_color(const PC88_PALETTE_T color[],
			int nr_color, unsigned long pixel[])
{
    if (displayDepth == 8) {
	PixMapHandle pixmap;
	CTabHandle ctab;
	GDHandle mainhd;
	RGBColor rgb;
	int i;

	for (i=0; i<nr_color; i++) {
	    rgb.red   = (unsigned short)color[i].red   << 8;
	    rgb.green = (unsigned short)color[i].green << 8;
	    rgb.blue  = (unsigned short)color[i].blue  << 8;
	    SetEntryColor (defPalette, nr_color_used + i, &rgb);

	    pixel[i] = nr_color_used + i;
	}
	nr_color_used += nr_color;


	/* ���ν��������ɬ�פʤΤ��� �ե륹���꡼��Ǥ����פʤΡ� */
	if (graph_exist &&
	    graph_info.fullscreen == FALSE) {

	    pixmap = GetGWorldPixMap(macGw);
	    ctab = (*pixmap)->pmTable;
	    mainhd = GetMainDevice();
		
	    for (i=0; i<ALL_COLORS + 1; i++) {
		GetEntryColor(defPalette, i, &rgb);
		(*ctab)->ctTable[i].rgb = rgb;
		(*ctab)->ctTable[i].value = i;
	    }
	    (*ctab)->ctSeed = (*(*(*mainhd)->gdPMap)->pmTable)->ctSeed;
	}

	/* �����ɬ�ܤΤ褦���������̤�����Ĥ������� */
	ActivatePalette(macWin);

    } else {
	int i;
	for (i=0; i<nr_color; i++) {
	    pixel[i] = ( ((unsigned short)(color[i].red   >> 3) << 10) |
			 ((unsigned short)(color[i].green >> 3) <<  5) |
			 ((unsigned short)(color[i].blue  >> 3)) );
	}
    }
}

/************************************************************************/

void	graph_remove_color(int nr_pixel, unsigned long pixel[])
{
    nr_color_used -= nr_pixel;
}

/*======================================================================*/

/* set up coltable, alind8? etc. */
static void InitColor(void)
{
    if (displayDepth == 8) {
	RGBColor rgb;
	int i;
	const int param[ALL_COLORS][3] = // {R,G,B}
	{
	    { 0x0000, 0x0000, 0x0000 },		/* ���� ���ǽ���� */
	};

	defPalette = NewPalette(ALL_COLORS + 1, NULL, pmTolerant | pmExplicit, 0);

	// 0 is preserved by Mac	
	rgb.red = rgb.green = rgb.blue = 255;
	SetEntryColor(defPalette, 0, &rgb);		

	/* �Ȥꤢ�������ǥե���Ȥο������ */
	for (i=0; i<ALL_COLORS; i++) {
	    rgb.red   = param[i][0];
	    rgb.green = param[i][1];
	    rgb.blue  = param[i][2];
	    SetEntryColor(defPalette, i + 1, &rgb);
	}
    }
}

/************************************************************************
 *	����ե��å��ι���
 ************************************************************************/

static void draw(int x0, int y0, int x1, int y1);

void	graph_update(int nr_rect, T_GRAPH_RECT rect[])
{
    int i;

    if (graph_info.fullscreen == FALSE) {
	for (i=0; i<nr_rect; i++) {
	    draw(rect[i].x,
		 rect[i].y,
		 rect[i].x + rect[i].width,
		 rect[i].y + rect[i].height);
	}
    }
}

/*======================================================================*/
// draw
static void draw(int x0, int y0, int x1, int y1)
{
    CGrafPtr port;
    GWorldPtr gptr;
    GDHandle ghd;
    Rect rect;
	const BitMap* portBits;
	
    // blit !
    GetGWorld(&gptr, &ghd);
    port = GetWindowPort(macWin);
    SetGWorld(port, NULL);
    SetRect(&rect, x0, y0, x1, y1);
    //SetRect(&rect, 0, 0, graph_info.width, graph_info.height);
	portBits = GetPortBitMapForCopyBits(port);
    CopyBits(GetPortBitMapForCopyBits(macGw), portBits, &rect, &rect,
	     srcCopy, NULL);
    SetGWorld(gptr, ghd);
}



void	mac_draw_immidiate(void)
{
    if (graph_info.fullscreen == FALSE) {
	draw(0, 0, graph_info.width, graph_info.height);
    }
}



/************************************************************************
 *	�����ȥ������
 *	°��������
 ************************************************************************/
// Window title strings
static Str255 wtitle;

void	graph_set_window_title(const char *title)
{
    wtitle[0] = strlen(title);
    memcpy(wtitle+1, title, wtitle[0]);

    if (macWin) {
	SetWTitle(macWin, wtitle);
    }
}

/************************************************************************/

void	graph_set_attribute(int mouse_show, int grab, int keyrepeat_on)
{
    /* ����λ������狼��ʤ��� */
    (void)mouse_show;
    (void)grab;
    (void)keyrepeat_on;
}