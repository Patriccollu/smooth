 /* The smooth Class Library
  * Copyright (C) 1998-2004 Robert Kausch <robert.kausch@gmx.net>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of "The Artistic License, Version 2.0".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#ifndef _H_OBJSMOOTH_METRICS_
#define _H_OBJSMOOTH_METRICS_

#include "system.h"

namespace smooth
{
	const int	 SMT_UNITS = 0;
	const int	 SMT_PIXELS = 1;

#ifdef __SMOOTH_DLL__
	extern int	 METRIC_TITLEBARHEIGHT;
	extern int	 METRIC_TBBUTTONBOXOFFSETX;
	extern int	 METRIC_TBBUTTONBOXOFFSETY;
	extern int	 METRIC_TBBUTTONBOXWIDTH;
	extern int	 METRIC_TBBUTTONBOXHEIGHT;
	extern int	 METRIC_TBBUTTONSIZE;
	extern int	 METRIC_TBBUTTONOFFSETX;
	extern int	 METRIC_TBBUTTONOFFSETY;
	extern int	 METRIC_TBTEXTOFFSETX;
	extern int	 METRIC_TBTEXTOFFSETY;
	extern int	 METRIC_TBICONSIZE;
	extern int	 METRIC_TBICONOFFSET;

	extern int	 METRIC_MENUBARHEIGHT;
	extern int	 METRIC_MBTEXTOFFSETX;
	extern int	 METRIC_MBTEXTOFFSETY;
	extern int	 METRIC_MBENTRYSPACING;
	extern int	 METRIC_MBENTRYHEIGHT;

	extern int	 METRIC_IBICONOFFSETX;
	extern int	 METRIC_IBICONOFFSETY;
	extern int	 METRIC_IBICONSIZE;
	extern int	 METRIC_IBENTRYSPACING;
	extern int	 METRIC_IBARROWSIZEX;
	extern int	 METRIC_IBARROWSIZEY;

	extern int	 METRIC_STATUSBARHEIGHT;
	extern int	 METRIC_SBTEXTOFFSETX;
	extern int	 METRIC_SBTEXTOFFSETY;

	extern int	 METRIC_PBTEXTOFFSETY;

	extern int	 METRIC_GBTEXTOFFSETY;

	extern int	 METRIC_POPUPENTRYSIZE;
	extern int	 METRIC_POPUPARROWOFFSETY;

	extern int	 METRIC_CHECKBOXOFFSETXY;
	extern int	 METRIC_CHECKBOXTEXTOFFSETY;

	extern int	 METRIC_OPTBOXOFFSETXY;
	extern int	 METRIC_OPTBOXTEXTOFFSETY;

	extern int	 METRIC_EDITBOXLINEHEIGHT;

	extern int	 METRIC_COMBOBOXOFFSETX;
	extern int	 METRIC_COMBOBOXARROWOFFSETY;
	extern int	 METRIC_COMBOBOXARROWOFFSETX;
	extern int	 METRIC_COMBOBOXTEXTOFFSETXY;

	extern int	 METRIC_REGISTEROFFSETY;
	extern int	 METRIC_REGISTERTEXTOFFSETX;
	extern int	 METRIC_REGISTERTEXTOFFSETY;

	extern int	 METRIC_TREEVIEWENTRYHEIGHT;

	extern int	 METRIC_SLIDERAREAWIDTH;
	extern int	 METRIC_SLIDERAREAHEIGHT;
	extern int	 METRIC_SLIDERAREAOFFSETX;
	extern int	 METRIC_SLIDERAREAOFFSETY;

	extern int	 METRIC_LISTBOXENTRYHEIGHT;
	extern int	 METRIC_LISTBOXTEXTOFFSETXY;
	extern int	 METRIC_LISTBOXSBOFFSET;

	void SetMetrics();
#endif

	SMOOTHAPI void SetMeasurement(int);
};

#endif
