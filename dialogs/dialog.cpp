 /* The smooth Class Library
  * Copyright (C) 1998-2003 Robert Kausch <robert.kausch@gmx.net>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the "Artistic License".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#include <smooth/dialog.h>
#include <smooth/stk.h>

S::Dialog::Dialog()
{
	parentWindow = NIL;
}

S::Dialog::~Dialog()
{
}

S::Int S::Dialog::SetCaption(String newCaption)
{
	caption = newCaption;

	return Success;
}

S::Int S::Dialog::SetParentWindow(GUI::Window *newParent)
{
	parentWindow = newParent;

	return Success;
}