 /* The smooth Class Library
  * Copyright (C) 1998-2004 Robert Kausch <robert.kausch@gmx.net>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of "The Artistic License, Version 2.0".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#ifndef _H_OBJSMOOTH_RECT_
#define _H_OBJSMOOTH_RECT_

namespace smooth
{
	namespace GUI
	{
		class Rect;
	};
};

#include "form.h"
#include "point.h"
#include "size.h"

namespace smooth
{
	namespace GUI
	{
		class SMOOTHAPI Rect : public Form
		{
			public:
#ifdef __WIN32__
				operator	 RECT();
				Rect &operator	 =(const RECT &);
#endif
				Int		 left;
				Int		 top;
				Int		 right;
				Int		 bottom;

						 Rect();
						 Rect(const Point &, const Size &);

				Rect operator	 *(const Float);
				Rect operator	 /(const Float);

				Bool operator	 ==(const Rect &);
				Bool operator	 !=(const Rect &);

				static Bool	 DoRectsOverlap(const Rect &, const Rect &);
				static Rect	 OverlapRect(const Rect &, const Rect&);
		};
	};
};

#endif