 /* The SMOOTH Windowing Toolkit
  * Copyright (C) 1998-2002 Robert Kausch <robert.kausch@gmx.net>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the "Artistic License".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#ifndef __OBJSMOOTH_HEBREW_
#define __OBJSMOOTH_HEBREW_

#include <smooth/i18n/hebrew.h>
#include <smooth/i18n.h>

void ActivateHebrewLanguage()
{
	TXT_ERROR = _TEXT("�����");

	TXT_OK = _TEXT("�����");
	TXT_CANCEL = _TEXT("�����");
	TXT_YES = _TEXT("��");
	TXT_NO = _TEXT("��");
	TXT_RETRY = _TEXT("���� ���");
	TXT_ABORT = _TEXT("�����");
	TXT_IGNORE = _TEXT("�����");

	TXT_SMOOTHAPPLICATION = _TEXT("SMOOTH ����ή����");

	TXT_COLORSELECTION = _TEXT("����Ϊ ο����");

	TXT_OPENFILE = _TEXT("������κ ��ά��");
	TXT_SAVEFILE = _TEXT("������κ ο����ή");
	TXT_SAVEFILEAS = _TEXT("��ή�� ������κ ο����ή");

	TXT_SELECTDIR = _TEXT("����ο���� ο����:");
	TXT_SELECTFONT = _TEXT("΃������ ο����");
}

#endif
