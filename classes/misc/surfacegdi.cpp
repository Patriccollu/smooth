 /* The smooth Class Library
  * Copyright (C) 1998-2003 Robert Kausch <robert.kausch@gmx.net>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the "Artistic License".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#include <smooth/surfacegdi.h>
#include <smooth/stk.h>
#include <smooth/toolkit.h>
#include <smooth/color.h>

S::GUI::SurfaceGDI::SurfaceGDI(HDC iDc)
{
	gdi_dc = iDc;
	real_dc = iDc;

	size.cx	= 0;
	size.cy	= 0;
}

S::GUI::SurfaceGDI::~SurfaceGDI()
{
}

S::Int S::GUI::SurfaceGDI::StartPaint()
{
	if (!painting)
	{
		HBITMAP	 bitmap = CreateBitmap(GetDeviceCaps(gdi_dc, HORZRES), GetDeviceCaps(gdi_dc, VERTRES), GetDeviceCaps(gdi_dc, PLANES), GetDeviceCaps(gdi_dc, BITSPIXEL), NIL);
		Rect	 bmpRect;

		bmpRect.left = 0;
		bmpRect.top = 0;
		bmpRect.right = GetDeviceCaps(gdi_dc, HORZRES);
		bmpRect.bottom = GetDeviceCaps(gdi_dc, VERTRES);

		BlitToBitmap(bmpRect, bitmap, bmpRect);

		gdi_dc = CreateCompatibleDC(real_dc);

		cDc_bitmap = (HBITMAP) SelectObject(gdi_dc, bitmap);
	}

	painting++;

	return Success;
}

S::Int S::GUI::SurfaceGDI::EndPaint()
{
	if (!painting) return Error;

	if (painting == 1)
	{
		HBITMAP	 bitmap = (HBITMAP) SelectObject(gdi_dc, cDc_bitmap);
		Rect	 bmpRect;

		bmpRect.left = 0;
		bmpRect.top = 0;
		bmpRect.right = GetDeviceCaps(gdi_dc, HORZRES);
		bmpRect.bottom = GetDeviceCaps(gdi_dc, VERTRES);

		DeleteDC(gdi_dc);

		gdi_dc = real_dc;

		BlitFromBitmap(bitmap, bmpRect, bmpRect);

		DestroyBitmap(bitmap);
	}

	painting--;

	return Success;
}

HDC S::GUI::SurfaceGDI::GetContext()
{
	return gdi_dc;
}

S::Int S::GUI::SurfaceGDI::SetPixel(Int x, Int y, Int color)
{
	::SetPixel(gdi_dc, x, y, color);

	return Success;
}

S::Int S::GUI::SurfaceGDI::GetPixel(Int x, Int y)
{
	return ::GetPixel(gdi_dc, x, y);
}

S::Int S::GUI::SurfaceGDI::Line(Point pos1, Point pos2, Int color)
{
	HPEN	 hPen = CreatePen(PS_SOLID, 1, color);
	HPEN	 hOldPen = (HPEN) SelectObject(gdi_dc, hPen);

	MoveToEx(gdi_dc, pos1.x, pos1.y, NIL);
	LineTo(gdi_dc, pos2.x, pos2.y);

	hPen = (HPEN) SelectObject(gdi_dc, hOldPen);
	DeleteObject(hPen);

	return Success;
}

S::Int S::GUI::SurfaceGDI::Frame(Rect rect, Int style)
{
	Long	 color1 = 0;
	Long	 color2 = 0;
	Point	 p1;
	Point	 p2;
	Point	 p3;
	Point	 p4;

	p1.x = rect.left;
	p1.y = rect.top;
	p2.x = rect.right;
	p2.y = rect.top;
	p3.x = rect.left;
	p3.y = rect.bottom;
	p4.x = rect.right;
	p4.y = rect.bottom;

	switch (style)
	{
		case FRAME_UP: // up
		{
			color1 = RGB(min(GetRed(Setup::BackgroundColor) + 64, 255), min(GetGreen(Setup::BackgroundColor) + 64, 255), min(GetBlue(Setup::BackgroundColor) + 64, 255));
			color2 = RGB(max(GetRed(Setup::BackgroundColor) - 64, 0), max(GetGreen(Setup::BackgroundColor) - 64, 0), max(GetBlue(Setup::BackgroundColor) - 64, 0));
		}
		break;

		case FRAME_DOWN: // down
		{
			color1 = RGB(max(GetRed(Setup::BackgroundColor) - 64, 0), max(GetGreen(Setup::BackgroundColor) - 64, 0), max(GetBlue(Setup::BackgroundColor) - 64, 0));
			color2 = RGB(min(GetRed(Setup::BackgroundColor) + 64, 255), min(GetGreen(Setup::BackgroundColor) + 64, 255), min(GetBlue(Setup::BackgroundColor) + 64, 255));
		}
		break;
	}

	Line(p1, p2, color1);
	Line(p1, p3, color1);
	Line(p2, p4, color2);
	p4.x++;
	Line(p3, p4, color2);

	return Success;
}

S::Int S::GUI::SurfaceGDI::Box(Rect rect, Int color, Int style)
{
	HBRUSH	 brush = CreateSolidBrush(color);
	RECT	 wRect = rect;

	if (style == FILLED)		FillRect(gdi_dc, &wRect, brush);
	else if (style == OUTLINED)	FrameRect(gdi_dc, &wRect, brush);
	else
	{
		Bool	 dot = False;
		Int	 x;
		Int	 y = rect.top;

		for (x = rect.left; x < rect.right - 1; x++)
		{
			if (dot == True)
			{
				::SetPixel(gdi_dc, x, y, color);
				dot = False;
			}
			else dot = True;
		}

		x = rect.right - 1;

		for (y = rect.top; y < rect.bottom; y++)
		{
			if (dot == True)
			{
				::SetPixel(gdi_dc, x, y, color);
				dot = False;
			}
			else dot = True;
		}

		y = rect.bottom - 1;

		for (x = rect.right - 2; x >= rect.left; x--)
		{
			if (dot == True)
			{
				::SetPixel(gdi_dc, x, y, color);
				dot = False;
			}
			else dot = True;
		}

		x = rect.left;

		for (y = rect.bottom - 2; y >= rect.top; y--)
		{
			if (dot == True)
			{
				::SetPixel(gdi_dc, x, y, color);
				dot = False;
			}
			else dot = True;
		}
	}

	DeleteObject(brush);

	return Success;
}

S::Int S::GUI::SurfaceGDI::SetText(String string, Rect rect, String font, Int size, Int color, Int weight, Int flags)
{
	if (string == NIL) return Error;

	HFONT	 hfont;
	HFONT	 holdfont;
	int	 lines = 1;
	int	 offset = 0;
	int	 origoffset;
	int	 height = GetLineSizeY(string, font, size, weight) + 3;
	int	 txtsize = string.Length();
	int	 i;
	String	 line;

	for (i = 0; i < txtsize; i++) if (string[i] == 10) lines++;

	SetBkMode(gdi_dc, TRANSPARENT);
	SetTextColor(gdi_dc, color);

	if (Setup::enableUnicode)	hfont = CreateFontW(size, 0, 0, 0, weight, flags & TF_ITALIC, flags & TF_UNDERLINE, flags & TF_STRIKEOUT, ANSI_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, FF_ROMAN, font);
	else				hfont = CreateFontA(size, 0, 0, 0, weight, flags & TF_ITALIC, flags & TF_UNDERLINE, flags & TF_STRIKEOUT, ANSI_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, FF_ROMAN, font);

	holdfont = (HFONT) SelectObject(gdi_dc, hfont);

	for (i = 0; i < lines; i++)
	{
		origoffset = offset;

		for (int j = 0; j <= txtsize; j++)
		{
			if (j + origoffset == txtsize)
			{
				line[j] = 0;
				break;
			}

			if (string[j + origoffset] == 10 || string[j + origoffset] == 0)
			{
				offset++;
				line[j] = 0;
				break;
			}
			else
			{
				offset++;
				line[j] = string[j + origoffset];
			}
		}

		RECT	 Rect = rect;

		if (Setup::enableUnicode)	DrawTextExW(gdi_dc, line, -1, &Rect, DT_LEFT | DT_EXPANDTABS, NIL);
		else				DrawTextExA(gdi_dc, line, -1, &Rect, DT_LEFT | DT_EXPANDTABS, NIL);

		rect.top += height;
	}

	SelectObject(gdi_dc, holdfont);
	DeleteObject(hfont);

	return Success;
}

S::Int S::GUI::SurfaceGDI::BlitFromBitmap(HBITMAP bitmap, Rect srcRect, Rect destRect)
{
	HDC	 cdc = CreateCompatibleDC(gdi_dc);
	HBITMAP	 backup = (HBITMAP) SelectObject(cdc, bitmap);

	if ((destRect.right - destRect.left == srcRect.right - srcRect.left) && (destRect.bottom - destRect.top == srcRect.bottom - srcRect.top))
	{
		BitBlt(gdi_dc, destRect.left, destRect.top, destRect.right - destRect.left, destRect.bottom - destRect.top, cdc, srcRect.left, srcRect.top, SRCCOPY);
	}
	else
	{
		StretchBlt(gdi_dc, destRect.left, destRect.top, destRect.right - destRect.left, destRect.bottom - destRect.top, cdc, srcRect.left, srcRect.top, srcRect.right - srcRect.left, srcRect.bottom - srcRect.top, SRCCOPY);
	}

	bitmap = (HBITMAP) SelectObject(cdc, backup);

	DeleteDC(cdc);
	DestroyBitmap(backup);

	return Success;
}

S::Int S::GUI::SurfaceGDI::BlitToBitmap(Rect srcRect, HBITMAP bitmap, Rect destRect)
{
	HDC	 cdc = CreateCompatibleDC(gdi_dc);
	HBITMAP	 backup = (HBITMAP) SelectObject(cdc, bitmap);

	if ((destRect.right - destRect.left == srcRect.right - srcRect.left) && (destRect.bottom - destRect.top == srcRect.bottom - srcRect.top))
	{
		BitBlt(cdc, destRect.left, destRect.top, destRect.right - destRect.left, destRect.bottom - destRect.top, gdi_dc, srcRect.left, srcRect.top, SRCCOPY);
	}
	else
	{
		StretchBlt(cdc, destRect.left, destRect.top, destRect.right - destRect.left, destRect.bottom - destRect.top, gdi_dc, srcRect.left, srcRect.top, srcRect.right - srcRect.left, srcRect.bottom - srcRect.top, SRCCOPY);
	}

	bitmap = (HBITMAP) SelectObject(cdc, backup);

	DeleteDC(cdc);
	DestroyBitmap(backup);

	return Success;
}
