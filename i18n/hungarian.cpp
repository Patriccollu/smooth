 /* The SMOOTH Windowing Toolkit
  * Copyright (C) 1998-2002 Robert Kausch <robert.kausch@gmx.net>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the "Artistic License".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#ifndef __OBJSMOOTH_HUNGARIAN_
#define __OBJSMOOTH_HUNGARIAN_

#include <smooth/i18n/hungarian.h>
#include <smooth/i18n.h>

void ActivateHungarianLanguage()
{
	TXT_ERROR = _TEXT("Hiba");

	TXT_OK = _TEXT("Vazhi");
	TXT_CANCEL = _TEXT("M�gsem");
	TXT_YES = _TEXT("Igen");
	TXT_NO = _TEXT("Nem");
	TXT_RETRY = _TEXT("Ism�t");
	TXT_ABORT = _TEXT("Elvet");
	TXT_IGNORE = _TEXT("Kihagy");

	TXT_SMOOTHAPPLICATION = _TEXT("SMOOTH alkalmaz�s");
	TXT_LAYER = _TEXT("F�lia");

	TXT_COLORSELECTION = _TEXT("Sz�nv�laszt�s");
	TXT_HTMLCODE = _TEXT("HTML k�d:");
	TXT_REDSHORT = _TEXT("V");
	TXT_GREENSHORT = _TEXT("Z");
	TXT_BLUESHORT = _TEXT("K");
	TXT_HUESHORT = _TEXT("�");
	TXT_SATURATIONSHORT = _TEXT("T");
	TXT_VALUESHORT = _TEXT("�");

	TXT_OPENFILE = _TEXT("F�jl megnyit�sa");
	TXT_SAVEFILE = _TEXT("F�jl ment�se");
	TXT_SAVEFILEAS = _TEXT("A f�jl ment�se m�sk�nt");

	TXT_SELECTDIR = _TEXT("K�nyvt�r kiv�laszt�sa:");
	TXT_SELECTFONT = _TEXT("Bet�t�pusv�laszt�s");

	TXT_SPLASHSCREEN = _TEXT("�dv�zl� k�perny�");
}

#endif
