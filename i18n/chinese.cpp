 /* The SMOOTH Windowing Toolkit
  * Copyright (C) 1998-2002 Robert Kausch <robert.kausch@gmx.net>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the "Artistic License".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#ifndef __OBJSMOOTH_CHINESE_
#define __OBJSMOOTH_CHINESE_

#include <smooth/i18n/chinese.h>
#include <smooth/i18n.h>

void ActivateChineseLanguage()
{
	TXT_ERROR = _TEXT("��+�");

	TXT_OK = _TEXT("+�¿");
	TXT_CANCEL = _TEXT("+�");
	TXT_YES = _TEXT("-�");
	TXT_NO = _TEXT("��");
	TXT_RETRY = _TEXT("��-�");
	TXT_ABORT = _TEXT("�˳�");
	TXT_IGNORE = _TEXT("��-�");
}

#endif
