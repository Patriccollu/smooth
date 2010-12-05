 /* The smooth Class Library
  * Copyright (C) 1998-2009 Robert Kausch <robert.kausch@gmx.net>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of "The Artistic License, Version 2.0".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#include <smooth/system/cpu.h>

#include <libcpuid.h>

S::Int	 S::System::CPU::numCores	= 1;
S::Int	 S::System::CPU::numLogicalCPUs	= 1;

S::Bool	 S::System::CPU::hasMMX		= False;
S::Bool	 S::System::CPU::hasMMXExt	= False;

S::Bool	 S::System::CPU::hasSSE		= False;
S::Bool	 S::System::CPU::hasSSE2	= False;
S::Bool	 S::System::CPU::hasSSE3	= False;
S::Bool	 S::System::CPU::hasSSSE3	= False;
S::Bool	 S::System::CPU::hasSSE4_1	= False;
S::Bool	 S::System::CPU::hasSSE4_2	= False;
S::Bool	 S::System::CPU::hasSSE4a	= False;
S::Bool	 S::System::CPU::hasSSE5	= False;

S::Bool	 S::System::CPU::hasAVX		= False;

S::Bool	 S::System::CPU::has3DNow	= False;
S::Bool	 S::System::CPU::has3DNowExt	= False;

S::Bool	 S::System::CPU::hasHT		= False;
S::Bool	 S::System::CPU::hasNX		= False;

S::Bool	 S::System::CPU::hasVMX		= False;
S::Bool	 S::System::CPU::hasSVM		= False;

S::System::CPU::CPU()
{
	GetCPUID();
}

S::Errors::Error S::System::CPU::GetCPUID()
{
	static Bool	 initialized = False;
	static Bool	 failed	     = False;

	/* Return if we are already initialized or failed before.
	 */
	if (initialized) return Success();
	if (failed)	 return Error();

	/* Fail if CPUID is not available.
	 */
	failed	    = True;

	if (!cpuid_present()) return Error();

	/* Get actual CPUID data.
	 */
	cpu_raw_data_t	 raw;
	cpu_id_t	 data;

	if (cpuid_get_raw_data(&raw)  < 0) return Error();
	if (cpu_identify(&raw, &data) < 0) return Error();

	/* OK, set to initialized.
	 */
	initialized = True;
	failed	    = False;

	/* Set number of cores and log CPUs.
	 */
	numCores       = data.num_cores;
	numLogicalCPUs = data.num_logical_cpus;

	/* Set feature flags.
	 */
	hasMMX	    = data.flags[CPU_FEATURE_MMX];
	hasMMXExt   = data.flags[CPU_FEATURE_MMXEXT];

	hasSSE	    = data.flags[CPU_FEATURE_SSE];
	hasSSE2	    = data.flags[CPU_FEATURE_SSE2];
	hasSSE3	    = data.flags[CPU_FEATURE_PNI];
	hasSSSE3    = data.flags[CPU_FEATURE_SSSE3];
	hasSSE4_1   = data.flags[CPU_FEATURE_SSE4_1];
	hasSSE4_2   = data.flags[CPU_FEATURE_SSE4_2];
	hasSSE4a    = data.flags[CPU_FEATURE_SSE4A];
	hasSSE5	    = data.flags[CPU_FEATURE_SSE5];

	hasAVX	    = data.flags[CPU_FEATURE_AVX];

	has3DNow    = data.flags[CPU_FEATURE_3DNOW];
	has3DNowExt = data.flags[CPU_FEATURE_3DNOWEXT];

	hasHT	    = data.flags[CPU_FEATURE_HT];
	hasNX	    = data.flags[CPU_FEATURE_NX];

	hasVMX	    = data.flags[CPU_FEATURE_VMX];
	hasSVM	    = data.flags[CPU_FEATURE_SVM];

	return Success();
}