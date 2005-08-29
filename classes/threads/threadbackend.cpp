 /* The smooth Class Library
  * Copyright (C) 1998-2004 Robert Kausch <robert.kausch@gmx.net>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of "The Artistic License, Version 2.0".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#include <smooth/threads/threadbackend.h>

S::Threads::ThreadBackend *CreateThreadBackend(S::Void *iThread)
{
	return new S::Threads::ThreadBackend(iThread);
}

S::Int	 threadBackendTmp = S::Threads::ThreadBackend::AddBackend(&CreateThreadBackend);

S::Array<S::Threads::ThreadBackend *(*)(S::Void *)>	*S::Threads::ThreadBackend::backend_creators = NIL;

S::Int S::Threads::ThreadBackend::AddBackend(ThreadBackend *(*backend)(Void *))
{
	if (backend == NIL) return Failure;

	if (backend_creators == NIL) backend_creators = new Array<ThreadBackend *(*)(Void *)>;

	backend_creators->AddEntry(backend);

	return Success;
}

S::Threads::ThreadBackend *S::Threads::ThreadBackend::CreateBackendInstance(Void *iThread)
{
	if (backend_creators->GetFirstEntry() != &CreateThreadBackend)	return backend_creators->GetFirstEntry()(iThread);
	else								return backend_creators->GetLastEntry()(iThread);
}

S::Threads::ThreadBackend::ThreadBackend(Void *iThread)
{
	type = THREAD_NONE;
}

S::Threads::ThreadBackend::~ThreadBackend()
{
}

S::Int S::Threads::ThreadBackend::GetThreadType()
{
	return type;
}

S::Void *S::Threads::ThreadBackend::GetSystemThread()
{
	return NIL;
}

S::Int S::Threads::ThreadBackend::GetThreadID()
{
	return -1;
}

S::Int S::Threads::ThreadBackend::Start(Void (*threadProc)(Void *), Void *threadParam)
{
	return Failure;
}

S::Int S::Threads::ThreadBackend::Stop()
{
	return Failure;
}

S::Void S::Threads::ThreadBackend::Exit()
{
}

S::Void *S::Threads::ThreadBackend::Self()
{
	return NIL;
}
