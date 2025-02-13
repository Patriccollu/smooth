 /* The smooth Class Library
  * Copyright (C) 1998-2019 Robert Kausch <robert.kausch@gmx.net>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of "The Artistic License, Version 2.0".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#include "../definitions.h"

#ifndef H_OBJSMOOTH_STRING
#define H_OBJSMOOTH_STRING

namespace smooth
{
	class String;

	namespace Threads
	{
		class Thread;
	};
};

#include "../templates/array.h"
#include "../templates/buffer.h"

namespace smooth
{
	class SMOOTHAPI String
	{
		friend class Threads::Thread;

		private:
			Buffer<wchar_t>		 wString;

			static Void		 AddTemporaryBuffer(char *);
			static Void		 DeleteTemporaryBuffers(Bool = False);
		public:
			class InputFormat;
			class OutputFormat;

			static Int		 Initialize();
			static Int		 Free();

						 String(const int = NIL);
						 String(const char *);
						 String(const wchar_t *);
						 String(const String &);

						~String();

			Void			 Clean();

			static Bool		 IsANSI(const String &);
			static Bool		 IsUnicode(const String &);

			static const char	*GetDefaultEncoding();

			static const char	*GetInputFormat();
			static const char	*SetInputFormat(const char *);

			static const char	*GetOutputFormat();
			static const char	*SetOutputFormat(const char *);

			static const char	*GetInternalFormat();

			Int			 ImportFrom(const char *, const char *);
			char			*ConvertTo(const char *) const;

			UnsignedInt32		 ComputeCRC32() const;
			UnsignedInt64		 ComputeCRC64() const;

			String			 EncodeBase64() const;
			String			 DecodeBase64() const;

			Int			 Find(const String &) const;
			Int			 FindLast(const String &) const;

			String			&Append(const String &);
			String			 Append(const String &) const;

			String			&Replace(const String &, const String &);
			String			 Replace(const String &, const String &) const;

			String			&Copy(const String &);
			String			&CopyN(const String &, const Int);

			Bool			 Contains(const String &) const;

			Int			 Compare(const String &) const;
			Int			 CompareN(const String &, const Int) const;

			Bool			 StartsWith(const String &) const;
			Bool			 EndsWith(const String &) const;

			String			 SubString(Int, Int) const;

			String			 Head(Int) const;
			String			 Tail(Int) const;

			String			 Trim() const;

			String			&Fill(const Int);
			String			&FillN(const Int, const Int);

			Int			 Length() const;

			Int64			 ToInt() const;
			Float			 ToFloat() const;

			static String		 FromInt(const Int64);
			static String		 FromFloat(const Float);

			/* Case conversion routines for lower, upper and title case
			 * (implemented in generated string_case.cpp)
			 */
			String			 ToLower() const;
			String			 ToUpper() const;
			String			 ToTitle() const;

			Array<String>		 Explode(const String &) const;
			static String		 Implode(const Array<String> &, const String & = String());

			wchar_t &operator	 [](const int);
			wchar_t operator	 [](const int) const;

			operator		 char *() const;
			operator		 wchar_t *() const;

			String &operator	 =(const int);
			String &operator	 =(const char *);
			String &operator	 =(const wchar_t *);
			String &operator	 =(const String &);

			Bool operator		 ==(const int) const;
			Bool operator		 ==(const char *) const;
			Bool operator		 ==(const wchar_t *) const;
			Bool operator		 ==(const String &) const;

			Bool operator		 !=(const int) const;
			Bool operator		 !=(const char *) const;
			Bool operator		 !=(const wchar_t *) const;
			Bool operator		 !=(const String &) const;
	};

	/* Scoped input and output format.
	 */
	class SMOOTHAPI String::InputFormat
	{
		private:
			String	 previousFormat;
		public:
				 InputFormat(const char *inputFormat)	{ previousFormat.ImportFrom(GetDefaultEncoding(), SetInputFormat(inputFormat)); }
				~InputFormat()				{ SetInputFormat(previousFormat.ConvertTo(GetDefaultEncoding())); }
	};

	class SMOOTHAPI String::OutputFormat
	{
		private:
			String	 previousFormat;
		public:
				 OutputFormat(const char *outputFormat)	{ previousFormat.ImportFrom(GetDefaultEncoding(), SetOutputFormat(outputFormat)); }
				~OutputFormat()				{ SetOutputFormat(previousFormat.ConvertTo(GetDefaultEncoding())); }
	};
};

#endif
