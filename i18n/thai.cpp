 /* The SMOOTH Windowing Toolkit
  * Copyright (C) 1998-2002 Robert Kausch <robert.kausch@gmx.net>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the "Artistic License".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#ifndef __OBJSMOOTH_THAI_
#define __OBJSMOOTH_THAI_

#include <smooth/i18n/thai.h>
#include <smooth/i18n.h>

void ActivateThaiLanguage()
{
	SMOOTHString::SetInputFormat(SIF_UTF8);

	TXT_ERROR = "��ͼԴ��Ҵ";

	TXT_OK = "��ŧ";
	TXT_CANCEL = "¡��ԡ";
	TXT_YES = "��";
	TXT_NO = "���";
	TXT_ABORT = "¡��ԡ";
	TXT_IGNORE = "���ʹ�";

	TXT_SMOOTHAPPLICATION = "SMOOTH �Ԩ����";

	TXT_COLORSELECTION = "���͡��";

	TXT_OPENFILE = "�Դ ���";
	TXT_SAVEFILE = "�ѹ�֡��������";
	TXT_SAVEFILEAS = "�ѹ�֡㹪���";

	TXT_SELECTDIR = "���硷�������:";
	TXT_SELECTFONT = "���͡��͹��";

	SMOOTHString::SetInputFormat(SIF_PREVIOUS);
}

#endif
