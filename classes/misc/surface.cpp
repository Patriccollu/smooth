 /* The smooth Class Library
  * Copyright (C) 1998-2003 Robert Kausch <robert.kausch@gmx.net>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the "Artistic License".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#include <smooth/surface.h>
#include <smooth/color.h>
#include <picture.h>

S::GUI::Surface::Surface()
{
	size.cx	= 0;
	size.cy	= 0;
}

S::GUI::Surface::~Surface()
{
}

S::Size S::GUI::Surface::GetSize()
{
	return size;
}

S::Int S::GUI::Surface::SetPixel(Int x, Int y, Int color)
{
	return Success;
}

S::Int S::GUI::Surface::GetPixel(Int x, Int y)
{
	return 0;
}

S::Int S::GUI::Surface::Line(Point pos1, Point pos2, Int color)
{
	return Success;
}

S::Int S::GUI::Surface::Frame(Rect rect, Int style)
{
	return Success;
}

S::Int S::GUI::Surface::Box(Rect rect, Int color, Int style)
{
	return Success;
}

S::Int S::GUI::Surface::SetText(String string, Rect rect, String font, Int size, Int color, Int weight, Int flags)
{
	return Success;
}

S::Int S::GUI::Surface::SetShadowedText(String string, Rect rect, String font, Int size, Int color, Int weight)
{
	if (string == NIL) return Error;

	rect.left += 2;
	rect.top += 2;
	rect.right += 2;
	rect.bottom += 2;

	SetText(string, rect, font, size, CombineColor(((Float) GetRed(Setup::BackgroundColor)) / 3 * 2, ((Float) GetGreen(Setup::BackgroundColor)) / 3 * 2, ((Float) GetBlue(Setup::BackgroundColor)) / 3 * 2), weight);

	rect.left -= 2;
	rect.top -= 2;
	rect.right -= 2;
	rect.bottom -= 2;

	SetText(string, rect, font, size, color, weight);

	return Success;
}

S::Int S::GUI::Surface::Gradient(Rect rect, Int color1, Int color2, Int style)
{
	Float	 red1	= GetRed(color1);
	Float	 green1	= GetGreen(color1);
	Float	 blue1	= GetBlue(color1);
	Float	 red2	= GetRed(color2);
	Float	 green2	= GetGreen(color2);
	Float	 blue2	= GetBlue(color2);
	Int	 xmax	= rect.right - rect.left;
	Int	 ymax	= rect.bottom - rect.top;
	picture	*pic	= new picture(rect.right - rect.left, rect.bottom - rect.top, 24);

	switch (style)
	{
		case OR_HORZ:
		{
			Float	 biasr = (red2 - red1) / xmax;
			Float	 biasg = (green2 - green1) / xmax;
			Float	 biasb = (blue2 - blue1) / xmax;

			for (Int x = 0; x < xmax; x++)
			{
				red1	= red1 + biasr;
				green1	= green1 + biasg;
				blue1	= blue1 + biasb;

				for (Int y = 0; y < ymax; y++) pic->SetPixel(x, y, CombineColor(red1, green1, blue1));
			}
		}
		break;

		case OR_VERT:
		{
			Float	 biasr = (red2 - red1) / ymax;
			Float	 biasg = (green2 - green1) / ymax;
			Float	 biasb = (blue2 - blue1) / ymax;

			for (Int y = 0; y < ymax; y++)
			{
				red1	= red1 + biasr;
				green1	= green1 + biasg;
				blue1	= blue1 + biasb;

				for (Int x = 0; x < xmax; x++) pic->SetPixel(x, y, CombineColor(red1, green1, blue1));
			}
		}
		break;
	}

	Rect	 srect;

	srect.left	= 0;
	srect.top	= 0;
	srect.right	= rect.right - rect.left;
	srect.bottom	= rect.bottom - rect.top;

	BlitFromBitmap(pic->GetBitmap(), srect, rect);

	delete pic;
}

S::Int S::GUI::Surface::Bar(Point p1, Point p2, Int orientation)
{
	if (orientation == OR_HORZ)
	{
		Line(p1, p2, RGB(max(GetRed(Setup::BackgroundColor) - 64, 0), max(GetGreen(Setup::BackgroundColor) - 64, 0), max(GetBlue(Setup::BackgroundColor) - 64, 0)));
		SetPixel(p2.x, p2.y, RGB(min(GetRed(Setup::BackgroundColor) + 64, 255), min(GetGreen(Setup::BackgroundColor) + 64, 255), min(GetBlue(Setup::BackgroundColor) + 64, 255)));
		p1.y++;
		p2.y++;
		p2.x++;
		Line(p1, p2, RGB(min(GetRed(Setup::BackgroundColor) + 64, 255), min(GetGreen(Setup::BackgroundColor) + 64, 255), min(GetBlue(Setup::BackgroundColor) + 64, 255)));
	}
	else if (orientation == OR_VERT)
	{
		p2.y++;
		Line(p1, p2, RGB(max(GetRed(Setup::BackgroundColor) - 64, 0), max(GetGreen(Setup::BackgroundColor) - 64, 0), max(GetBlue(Setup::BackgroundColor) - 64, 0)));
		p1.x++;
		p2.x++;
		Line(p1, p2, RGB(min(GetRed(Setup::BackgroundColor) + 64, 255), min(GetGreen(Setup::BackgroundColor) + 64, 255), min(GetBlue(Setup::BackgroundColor) + 64, 255)));
	}

	return Success;
}

S::Int S::GUI::Surface::BlitFromBitmap(HBITMAP bitmap, Rect srcRect, Rect destRect)
{
	return Success;
}

S::Int S::GUI::Surface::BlitToBitmap(Rect srcRect, HBITMAP bitmap, Rect destRect)
{
	return Success;
}