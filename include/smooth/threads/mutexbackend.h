 /* The smooth Class Library
  * Copyright (C) 1998-2004 Robert Kausch <robert.kausch@gmx.net>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of "The Artistic License, Version 2.0".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#ifndef _H_OBJSMOOTH_MUTEXBACKEND_
#define _H_OBJSMOOTH_MUTEXBACKEND_

namespace smooth
{
	namespace Threads
	{
		class MutexBackend;
	};
};

#include "../definitions.h"

namespace smooth
{
	namespace Threads
	{
		const Int	 MUTEX_NONE = 0;

		class MutexBackend
		{
			protected:
				Int		 type;
			public:
						 MutexBackend(Void * = NIL);
				virtual		~MutexBackend();

				Int		 GetMutexType();

				virtual Void	*GetSystemMutex();

				virtual Int	 Lock();
				virtual Int	 Release();
		};
	};
};

#endif