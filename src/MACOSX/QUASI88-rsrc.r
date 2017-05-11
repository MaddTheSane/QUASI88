#import <Carbon/Carbon.r>

resource 'MENU' (128) {
	128,
	textMenuProc,
	allEnabled,
	enabled,
	apple,
	{	/* array: 1 elements */
		/* [1] */
		"About QUASI88...", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (131) {
	131,
	textMenuProc,
	0x7FFFFFFB,
	enabled,
	"Disk",
	{	/* array: 5 elements */
		/* [1] */
		"Drive 1:", noIcon, hierarchicalMenu, "è", plain,
		/* [2] */
		"Drive 2:", noIcon, hierarchicalMenu, "ê", plain,
		/* [3] */
		"-", noIcon, noKey, noMark, plain,
		/* [4] */
		"Set ...", noIcon, noKey, noMark, plain,
		/* [5] */
		"Unset", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (130) {
	130,
	textMenuProc,
	0x7FFFBDF7,
	enabled,
	"Setting",
	{	/* array: 17 elements */
		/* [1] */
		"Speed", noIcon, hierarchicalMenu, "Ü", plain,
		/* [2] */
		"Sub-CPU", noIcon, hierarchicalMenu, "á", plain,
		/* [3] */
		"Use FDC-Wait", noIcon, noKey, check, plain,
		/* [4] */
		"-", noIcon, noKey, noMark, plain,
		/* [5] */
		"Refresh Rate", noIcon, hierarchicalMenu, "à", plain,
		/* [6] */
		"Interlace", noIcon, hierarchicalMenu, "â", plain,
		/* [7] */
		"Screen Size", noIcon, hierarchicalMenu, "ä", plain,
		/* [8] */
		"Full Screen", noIcon, noKey, check, plain,
		/* [9] */
		"Use PCG-8100", noIcon, noKey, check, plain,
		/* [10] */
		"-", noIcon, noKey, noMark, plain,
		/* [11] */
		"Mouse", noIcon, hierarchicalMenu, "ã", plain,
		/* [12] */
		"Cursor Key", noIcon, hierarchicalMenu, "å", plain,
		/* [13] */
		"Software Numlock", noIcon, noKey, check, plain,
		/* [14] */
		"Kana (Romaji)", noIcon, noKey, check, plain,
		/* [15] */
		"-", noIcon, noKey, noMark, plain,
		/* [16] */
		"FM Generator", noIcon, hierarchicalMenu, "ç", plain,
		/* [17] */
		"Sample Frequency", noIcon, hierarchicalMenu, "é", plain
	}
};

resource 'MENU' (129) {
	129,
	textMenuProc,
	0x7FFFFEBB,
	enabled,
	"System",
	{	/* array: 11 elements */
		/* [1] */
		"Reset", noIcon, "R", noMark, plain,
		/* [2] */
		"Mode", noIcon, hierarchicalMenu, "Ö", plain,
		/* [3] */
		"-", noIcon, noKey, noMark, plain,
		/* [4] */
		"V2 mode", noIcon, noKey, noMark, plain,
		/* [5] */
		"V1H mode", noIcon, noKey, noMark, plain,
		/* [6] */
		"V1S mode", noIcon, noKey, noMark, plain,
		/* [7] */
		"-", noIcon, noKey, noMark, plain,
		/* [8] */
		"Menu", noIcon, "M", noMark, plain,
		/* [9] */
		"-", noIcon, noKey, noMark, plain,
		/* [10] */
		"Save Config", noIcon, noKey, noMark, plain,
		/* [11] */
		"Exit", noIcon, "Q", noMark, plain
	}
};

resource 'MENU' (133, "Mode") {
	133,
	textMenuProc,
	0x7FFFFF6F,
	enabled,
	"Mode",
	{	/* array: 10 elements */
		/* [1] */
		"V2", noIcon, noKey, check, plain,
		/* [2] */
		"V1H", noIcon, noKey, check, plain,
		/* [3] */
		"V1S", noIcon, noKey, check, plain,
		/* [4] */
		"N", noIcon, noKey, check, plain,
		/* [5] */
		"-", noIcon, noKey, noMark, plain,
		/* [6] */
		"4MHz", noIcon, noKey, check, plain,
		/* [7] */
		"8MHz", noIcon, noKey, check, plain,
		/* [8] */
		"-", noIcon, noKey, noMark, plain,
		/* [9] */
		"Sound Board", noIcon, noKey, check, plain,
		/* [10] */
		"Sound Board II", noIcon, noKey, check, plain
	}
};

resource 'MENU' (134, "Speed") {
	134,
	textMenuProc,
	0x7FFFFFDF,
	enabled,
	"Speed",
	{	/* array: 7 elements */
		/* [1] */
		"\?25%", noIcon, noKey, check, plain,
		/* [2] */
		"50%", noIcon, noKey, check, plain,
		/* [3] */
		"100%", noIcon, noKey, check, plain,
		/* [4] */
		"200%", noIcon, noKey, check, plain,
		/* [5] */
		"400%", noIcon, noKey, check, plain,
		/* [6] */
		"-", noIcon, noKey, noMark, plain,
		/* [7] */
		"No wait", noIcon, noKey, check, plain
	}
};

resource 'MENU' (135, "Sub-CPU") {
	135,
	textMenuProc,
	allEnabled,
	enabled,
	"Sub-CPU",
	{	/* array: 3 elements */
		/* [1] */
		"Run sometimes", noIcon, noKey, check, plain,
		/* [2] */
		"Run often", noIcon, noKey, check, plain,
		/* [3] */
		"Run always", noIcon, noKey, check, plain
	}
};

resource 'MENU' (136, "Refresh Rate") {
	136,
	textMenuProc,
	allEnabled,
	enabled,
	"Refresh Rate",
	{	/* array: 4 elements */
		/* [1] */
		"60fps", noIcon, noKey, check, plain,
		/* [2] */
		"30fps", noIcon, noKey, check, plain,
		/* [3] */
		"20fps", noIcon, noKey, check, plain,
		/* [4] */
		"15fps", noIcon, noKey, check, plain
	}
};

resource 'MENU' (137, "Interlace") {
	137,
	textMenuProc,
	allEnabled,
	enabled,
	"Interlace",
	{	/* array: 3 elements */
		/* [1] */
		"No Interlace", noIcon, noKey, check, plain,
		/* [2] */
		"Skip Line", noIcon, noKey, check, plain,
		/* [3] */
		"Interlace", noIcon, noKey, check, plain
	}
};

resource 'MENU' (138, "Screen Size") {
	138,
	textMenuProc,
	allEnabled,
	enabled,
	"Screen Size",
	{	/* array: 2 elements */
		/* [1] */
		"Normal size", noIcon, noKey, check, plain,
		/* [2] */
		"Half size", noIcon, noKey, check, plain
	}
};

resource 'MENU' (139, "Mouse") {
	139,
	textMenuProc,
	allEnabled,
	enabled,
	"Mouse",
	{	/* array: 3 elements */
		/* [1] */
		"Nothing", noIcon, noKey, check, plain,
		/* [2] */
		"Mouse", noIcon, noKey, check, plain,
		/* [3] */
		"Mouse as joy", noIcon, noKey, check, plain
	}
};

resource 'MENU' (140, "Cursor Key") {
	140,
	textMenuProc,
	allEnabled,
	enabled,
	"Cursor Key",
	{	/* array: 2 elements */
		/* [1] */
		"Default", noIcon, noKey, check, plain,
		/* [2] */
		"as Ten-key", noIcon, noKey, check, plain
	}
};

resource 'MENU' (141, "FM Generator") {
	141,
	textMenuProc,
	allEnabled,
	enabled,
	"FM Generator",
	{	/* array: 2 elements */
		/* [1] */
		"MAME embedded", noIcon, noKey, check, plain,
		/* [2] */
		"fmgen", noIcon, noKey, check, plain
	}
};

resource 'MENU' (143, "Drive 1:") {
	143,
	textMenuProc,
	0x7FFFFBFF,
	enabled,
	"Drive 1:",
	{	/* array: 12 elements */
		/* [1] */
		"1", noIcon, noKey, check, plain,
		/* [2] */
		"2", noIcon, noKey, check, plain,
		/* [3] */
		"3", noIcon, noKey, check, plain,
		/* [4] */
		"4", noIcon, noKey, check, plain,
		/* [5] */
		"5", noIcon, noKey, check, plain,
		/* [6] */
		"6", noIcon, noKey, check, plain,
		/* [7] */
		"7", noIcon, noKey, check, plain,
		/* [8] */
		"8", noIcon, noKey, check, plain,
		/* [9] */
		"9", noIcon, noKey, check, plain,
		/* [10] */
		"<No Disk>", noIcon, noKey, check, plain,
		/* [11] */
		"-", noIcon, noKey, noMark, plain,
		/* [12] */
		"Change ...", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (144, "Drive 2:") {
	144,
	textMenuProc,
	0x7FFFFBFF,
	enabled,
	"Drive 2:",
	{	/* array: 12 elements */
		/* [1] */
		"1", noIcon, noKey, check, plain,
		/* [2] */
		"2", noIcon, noKey, check, plain,
		/* [3] */
		"3", noIcon, noKey, check, plain,
		/* [4] */
		"4", noIcon, noKey, check, plain,
		/* [5] */
		"5", noIcon, noKey, check, plain,
		/* [6] */
		"6", noIcon, noKey, check, plain,
		/* [7] */
		"7", noIcon, noKey, check, plain,
		/* [8] */
		"8", noIcon, noKey, check, plain,
		/* [9] */
		"9", noIcon, noKey, check, plain,
		/* [10] */
		"<No Disk>", noIcon, noKey, check, plain,
		/* [11] */
		"-", noIcon, noKey, noMark, plain,
		/* [12] */
		"Change ...", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (132) {
	132,
	textMenuProc,
	0x7FFFFF6F,
	enabled,
	"Misc",
	{	/* array: 9 elements */
		/* [1] */
		"Screen Capture", noIcon, noKey, noMark, plain,
		/* [2] */
		"Sound Record", noIcon, noKey, check, plain,
		/* [3] */
		"Tape-Image [Load]", noIcon, hierarchicalMenu, "ë", plain,
		/* [4] */
		"Tape-Image [Save]", noIcon, hierarchicalMenu, "í", plain,
		/* [5] */
		"-", noIcon, noKey, noMark, plain,
		/* [6] */
		"State-Load", noIcon, hierarchicalMenu, "ì", plain,
		/* [7] */
		"State-Save", noIcon, hierarchicalMenu, "î", plain,
		/* [8] */
		"-", noIcon, noKey, noMark, plain,
		/* [9] */
		"Show Status", noIcon, noKey, check, plain
	}
};

resource 'MENU' (145, "Speed") {
	145,
	textMenuProc,
	allEnabled,
	enabled,
	"Tape-Image [Load]",
	{	/* array: 2 elements */
		/* [1] */
		"Set ...", noIcon, noKey, noMark, plain,
		/* [2] */
		"Unset", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (146, "Refresh Rate") {
	146,
	textMenuProc,
	allEnabled,
	enabled,
	"Tape-Image [Save]",
	{	/* array: 2 elements */
		/* [1] */
		"Set ...", noIcon, noKey, noMark, plain,
		/* [2] */
		"Unset", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (147, "Load Snapshot") {
	147,
	textMenuProc,
	allEnabled,
	enabled,
	"State-Load",
	{	/* array: 9 elements */
		/* [1] */
		"1", noIcon, noKey, noMark, plain,
		/* [2] */
		"2", noIcon, noKey, noMark, plain,
		/* [3] */
		"3", noIcon, noKey, noMark, plain,
		/* [4] */
		"4", noIcon, noKey, noMark, plain,
		/* [5] */
		"5", noIcon, noKey, noMark, plain,
		/* [6] */
		"6", noIcon, noKey, noMark, plain,
		/* [7] */
		"7", noIcon, noKey, noMark, plain,
		/* [8] */
		"8", noIcon, noKey, noMark, plain,
		/* [9] */
		"9", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (148, "Save Snapshot") {
	148,
	textMenuProc,
	allEnabled,
	enabled,
	"State-Save",
	{	/* array: 9 elements */
		/* [1] */
		"1", noIcon, noKey, noMark, plain,
		/* [2] */
		"2", noIcon, noKey, noMark, plain,
		/* [3] */
		"3", noIcon, noKey, noMark, plain,
		/* [4] */
		"4", noIcon, noKey, noMark, plain,
		/* [5] */
		"5", noIcon, noKey, noMark, plain,
		/* [6] */
		"6", noIcon, noKey, noMark, plain,
		/* [7] */
		"7", noIcon, noKey, noMark, plain,
		/* [8] */
		"8", noIcon, noKey, noMark, plain,
		/* [9] */
		"9", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (142, "Sample Frequency") {
	142,
	textMenuProc,
	allEnabled,
	enabled,
	"Sample Frequency",
	{	/* array: 4 elements */
		/* [1] */
		"44100Hz", noIcon, noKey, check, plain,
		/* [2] */
		"22050Hz", noIcon, noKey, check, plain,
		/* [3] */
		"11025Hz", noIcon, noKey, check, plain,
		/* [4] */
		"  8000Hz", noIcon, noKey, check, plain
	}
};

resource 'DLOG' (129) {
	{40, 40, 202, 248},
	dBoxProc,
	visible,
	goAway,
	0x0,
	129,
	"",
	alertPositionMainScreen
};

resource 'DLOG' (128) {
	{40, 40, 168, 285},
	altDBoxProc,
	visible,
	goAway,
	0x0,
	128,
	"",
	alertPositionMainScreen
};

resource 'DITL' (129) {
	{	/* array DITLarray: 2 elements */
		/* [1] */
		{130, 140, 150, 198},
		Button {
			enabled,
			"OK"
		},
		/* [2] */
		{10, 10, 120, 198},
		StaticText {
			disabled,
			"Message for you"
		}
	}
};

resource 'DITL' (128) {
	{	/* array DITLarray: 2 elements */
		/* [1] */
		{90, 170, 110, 228},
		Button {
			enabled,
			"OK"
		},
		/* [2] */
		{13, 12, 78, 232},
		StaticText {
			disabled,
			"Version info"
		}
	}
};

resource 'SIZE' (-1) {
	reserved,
	ignoreSuspendResumeEvents,
	reserved,
	canBackground,
	notMultiFinderAware,
	backgroundAndForeground,
	dontGetFrontClicks,
	ignoreChildDiedEvents,
	is32BitCompatible,
	notHighLevelEventAware,
	onlyLocalHLEvents,
	notStationeryAware,
	dontUseTextEditServices,
	notDisplayManagerAware,
	reserved,
	reserved,
	10485760,
	10485760
};

data 'Q8cl' (0, "Owner resource") {
	$"00"                                                 /* . */
};

resource 'BNDL' (128) {
	'Q8cl',
	0,
	{	/* array TypeArray: 2 elements */
		/* [1] */
		'FREF',
		{	/* array IDArray: 1 elements */
			/* [1] */
			0, 128
		},
		/* [2] */
		'ICN#',
		{	/* array IDArray: 1 elements */
			/* [1] */
			0, 128
		}
	}
};

resource 'FREF' (128) {
	'APPL',
	0,
	""
};

resource 'MBAR' (128) {
	{	/* array MenuArray: 5 elements */
		/* [1] */
		128,
		/* [2] */
		129,
		/* [3] */
		130,
		/* [4] */
		131,
		/* [5] */
		132
	}
};

