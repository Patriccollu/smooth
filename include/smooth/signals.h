 /* The smooth Class Library
  * Copyright (C) 1998-2004 Robert Kausch <robert.kausch@gmx.net>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of "The Artistic License, Version 2.0".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#ifndef _H_SIGNALS_
#define _H_SIGNALS_

#define SIGNALS_SIGNAL_ZERO
#define SIGNALS_SIGNAL_CLASS_NAME	Signal0
#define SIGNALS_INSTANCE_CLASS_NAME	Instance0
#define SIGNALS_CONDITIONAL_COMMA
#define SIGNALS_ARGUMENT_LIST
#define SIGNALS_ARGUMENT_TYPES
#define SIGNALS_ARGUMENT_PARAMETER_LIST
#define SIGNALS_ARGUMENT_PARAMETERS
#define SIGNALS_ARGUMENT_INV_PARAMETERS
#define SIGNALS_VA_ARGUMENTS

#include "templates/signals/signaln.h"

#undef SIGNALS_SIGNAL_ZERO
#undef SIGNALS_SIGNAL_CLASS_NAME
#undef SIGNALS_INSTANCE_CLASS_NAME
#undef SIGNALS_CONDITIONAL_COMMA
#undef SIGNALS_ARGUMENT_LIST
#undef SIGNALS_ARGUMENT_TYPES
#undef SIGNALS_ARGUMENT_PARAMETER_LIST
#undef SIGNALS_ARGUMENT_PARAMETERS
#undef SIGNALS_ARGUMENT_INV_PARAMETERS
#undef SIGNALS_VA_ARGUMENTS

#define SIGNALS_SIGNAL_CLASS_NAME	Signal1
#define SIGNALS_INSTANCE_CLASS_NAME	Instance1
#define SIGNALS_CONDITIONAL_COMMA	,
#define SIGNALS_ARGUMENT_LIST		class pt1
#define SIGNALS_ARGUMENT_TYPES		pt1
#define SIGNALS_ARGUMENT_PARAMETER_LIST	pt1 p1
#define SIGNALS_ARGUMENT_PARAMETERS	p1
#define SIGNALS_ARGUMENT_INV_PARAMETERS	p1
#define SIGNALS_VA_ARGUMENTS		va_arg(ap, pt1)

#include "templates/signals/signaln.h"

#undef SIGNALS_SIGNAL_CLASS_NAME
#undef SIGNALS_INSTANCE_CLASS_NAME
#undef SIGNALS_CONDITIONAL_COMMA
#undef SIGNALS_ARGUMENT_LIST
#undef SIGNALS_ARGUMENT_TYPES
#undef SIGNALS_ARGUMENT_PARAMETER_LIST
#undef SIGNALS_ARGUMENT_PARAMETERS
#undef SIGNALS_ARGUMENT_INV_PARAMETERS
#undef SIGNALS_VA_ARGUMENTS

#define SIGNALS_SIGNAL_CLASS_NAME	Signal2
#define SIGNALS_INSTANCE_CLASS_NAME	Instance2
#define SIGNALS_CONDITIONAL_COMMA	,
#define SIGNALS_ARGUMENT_LIST		class pt1, class pt2
#define SIGNALS_ARGUMENT_TYPES		pt1, pt2
#define SIGNALS_ARGUMENT_PARAMETER_LIST	pt1 p1, pt2 p2
#define SIGNALS_ARGUMENT_PARAMETERS	p1, p2
#define SIGNALS_ARGUMENT_INV_PARAMETERS	p2, p1
#define SIGNALS_VA_ARGUMENTS		va_arg(ap, pt1), va_arg(ap, pt2)

#include "templates/signals/signaln.h"

#undef SIGNALS_SIGNAL_CLASS_NAME
#undef SIGNALS_INSTANCE_CLASS_NAME
#undef SIGNALS_CONDITIONAL_COMMA
#undef SIGNALS_ARGUMENT_LIST
#undef SIGNALS_ARGUMENT_TYPES
#undef SIGNALS_ARGUMENT_PARAMETER_LIST
#undef SIGNALS_ARGUMENT_PARAMETERS
#undef SIGNALS_ARGUMENT_INV_PARAMETERS
#undef SIGNALS_VA_ARGUMENTS

#define SIGNALS_SIGNAL_CLASS_NAME	Signal3
#define SIGNALS_INSTANCE_CLASS_NAME	Instance3
#define SIGNALS_CONDITIONAL_COMMA	,
#define SIGNALS_ARGUMENT_LIST		class pt1, class pt2, class pt3
#define SIGNALS_ARGUMENT_TYPES		pt1, pt2, pt3
#define SIGNALS_ARGUMENT_PARAMETER_LIST	pt1 p1, pt2 p2, pt3 p3
#define SIGNALS_ARGUMENT_PARAMETERS	p1, p2, p3
#define SIGNALS_ARGUMENT_INV_PARAMETERS	p3, p2, p1
#define SIGNALS_VA_ARGUMENTS		va_arg(ap, pt1), va_arg(ap, pt2), va_arg(ap, pt3)

#include "templates/signals/signaln.h"

#undef SIGNALS_SIGNAL_CLASS_NAME
#undef SIGNALS_INSTANCE_CLASS_NAME
#undef SIGNALS_CONDITIONAL_COMMA
#undef SIGNALS_ARGUMENT_LIST
#undef SIGNALS_ARGUMENT_TYPES
#undef SIGNALS_ARGUMENT_PARAMETER_LIST
#undef SIGNALS_ARGUMENT_PARAMETERS
#undef SIGNALS_ARGUMENT_INV_PARAMETERS
#undef SIGNALS_VA_ARGUMENTS

#define SIGNALS_SIGNAL_CLASS_NAME	Signal4
#define SIGNALS_INSTANCE_CLASS_NAME	Instance4
#define SIGNALS_CONDITIONAL_COMMA	,
#define SIGNALS_ARGUMENT_LIST		class pt1, class pt2, class pt3, class pt4
#define SIGNALS_ARGUMENT_TYPES		pt1, pt2, pt3, pt4
#define SIGNALS_ARGUMENT_PARAMETER_LIST	pt1 p1, pt2 p2, pt3 p3, pt4 p4
#define SIGNALS_ARGUMENT_PARAMETERS	p1, p2, p3, p4
#define SIGNALS_ARGUMENT_INV_PARAMETERS	p4, p3, p2, p1
#define SIGNALS_VA_ARGUMENTS		va_arg(ap, pt1), va_arg(ap, pt2), va_arg(ap, pt3), va_arg(ap, pt4)

#include "templates/signals/signaln.h"

#undef SIGNALS_SIGNAL_CLASS_NAME
#undef SIGNALS_INSTANCE_CLASS_NAME
#undef SIGNALS_CONDITIONAL_COMMA
#undef SIGNALS_ARGUMENT_LIST
#undef SIGNALS_ARGUMENT_TYPES
#undef SIGNALS_ARGUMENT_PARAMETER_LIST
#undef SIGNALS_ARGUMENT_PARAMETERS
#undef SIGNALS_ARGUMENT_INV_PARAMETERS
#undef SIGNALS_VA_ARGUMENTS

#define SIGNALS_SIGNAL_CLASS_NAME	Signal5
#define SIGNALS_INSTANCE_CLASS_NAME	Instance5
#define SIGNALS_CONDITIONAL_COMMA	,
#define SIGNALS_ARGUMENT_LIST		class pt1, class pt2, class pt3, class pt4, class pt5
#define SIGNALS_ARGUMENT_TYPES		pt1, pt2, pt3, pt4, pt5
#define SIGNALS_ARGUMENT_PARAMETER_LIST	pt1 p1, pt2 p2, pt3 p3, pt4 p4, pt5 p5
#define SIGNALS_ARGUMENT_PARAMETERS	p1, p2, p3, p4, p5
#define SIGNALS_ARGUMENT_INV_PARAMETERS	p5, p4, p3, p2, p1
#define SIGNALS_VA_ARGUMENTS		va_arg(ap, pt1), va_arg(ap, pt2), va_arg(ap, pt3), va_arg(ap, pt4), va_arg(ap, pt5)

#include "templates/signals/signaln.h"

#undef SIGNALS_SIGNAL_CLASS_NAME
#undef SIGNALS_INSTANCE_CLASS_NAME
#undef SIGNALS_CONDITIONAL_COMMA
#undef SIGNALS_ARGUMENT_LIST
#undef SIGNALS_ARGUMENT_TYPES
#undef SIGNALS_ARGUMENT_PARAMETER_LIST
#undef SIGNALS_ARGUMENT_PARAMETERS
#undef SIGNALS_ARGUMENT_INV_PARAMETERS
#undef SIGNALS_VA_ARGUMENTS

#define SIGNALS_SIGNAL_CLASS_NAME	Signal6
#define SIGNALS_INSTANCE_CLASS_NAME	Instance6
#define SIGNALS_CONDITIONAL_COMMA	,
#define SIGNALS_ARGUMENT_LIST		class pt1, class pt2, class pt3, class pt4, class pt5, class pt6
#define SIGNALS_ARGUMENT_TYPES		pt1, pt2, pt3, pt4, pt5, pt6
#define SIGNALS_ARGUMENT_PARAMETER_LIST	pt1 p1, pt2 p2, pt3 p3, pt4 p4, pt5 p5, pt6 p6
#define SIGNALS_ARGUMENT_PARAMETERS	p1, p2, p3, p4, p5, p6
#define SIGNALS_ARGUMENT_INV_PARAMETERS	p6, p5, p4, p3, p2, p1
#define SIGNALS_VA_ARGUMENTS		va_arg(ap, pt1), va_arg(ap, pt2), va_arg(ap, pt3), va_arg(ap, pt4), va_arg(ap, pt5), va_arg(ap, pt6)

#include "templates/signals/signaln.h"

#undef SIGNALS_SIGNAL_CLASS_NAME
#undef SIGNALS_INSTANCE_CLASS_NAME
#undef SIGNALS_CONDITIONAL_COMMA
#undef SIGNALS_ARGUMENT_LIST
#undef SIGNALS_ARGUMENT_TYPES
#undef SIGNALS_ARGUMENT_PARAMETER_LIST
#undef SIGNALS_ARGUMENT_PARAMETERS
#undef SIGNALS_ARGUMENT_INV_PARAMETERS
#undef SIGNALS_VA_ARGUMENTS

#define SIGNALS_SIGNAL_CLASS_NAME	Signal7
#define SIGNALS_INSTANCE_CLASS_NAME	Instance7
#define SIGNALS_CONDITIONAL_COMMA	,
#define SIGNALS_ARGUMENT_LIST		class pt1, class pt2, class pt3, class pt4, class pt5, class pt6, class pt7
#define SIGNALS_ARGUMENT_TYPES		pt1, pt2, pt3, pt4, pt5, pt6, pt7
#define SIGNALS_ARGUMENT_PARAMETER_LIST	pt1 p1, pt2 p2, pt3 p3, pt4 p4, pt5 p5, pt6 p6, pt7 p7
#define SIGNALS_ARGUMENT_PARAMETERS	p1, p2, p3, p4, p5, p6, p7
#define SIGNALS_ARGUMENT_INV_PARAMETERS	p7, p6, p5, p4, p3, p2, p1
#define SIGNALS_VA_ARGUMENTS		va_arg(ap, pt1), va_arg(ap, pt2), va_arg(ap, pt3), va_arg(ap, pt4), va_arg(ap, pt5), va_arg(ap, pt6), va_arg(ap, pt7)

#include "templates/signals/signaln.h"

#undef SIGNALS_SIGNAL_CLASS_NAME
#undef SIGNALS_INSTANCE_CLASS_NAME
#undef SIGNALS_CONDITIONAL_COMMA
#undef SIGNALS_ARGUMENT_LIST
#undef SIGNALS_ARGUMENT_TYPES
#undef SIGNALS_ARGUMENT_PARAMETER_LIST
#undef SIGNALS_ARGUMENT_PARAMETERS
#undef SIGNALS_ARGUMENT_INV_PARAMETERS
#undef SIGNALS_VA_ARGUMENTS

#define SIGNALS_SIGNAL_CLASS_NAME	Signal8
#define SIGNALS_INSTANCE_CLASS_NAME	Instance8
#define SIGNALS_CONDITIONAL_COMMA	,
#define SIGNALS_ARGUMENT_LIST		class pt1, class pt2, class pt3, class pt4, class pt5, class pt6, class pt7, class pt8
#define SIGNALS_ARGUMENT_TYPES		pt1, pt2, pt3, pt4, pt5, pt6, pt7, pt8
#define SIGNALS_ARGUMENT_PARAMETER_LIST	pt1 p1, pt2 p2, pt3 p3, pt4 p4, pt5 p5, pt6 p6, pt7 p7, pt8 p8
#define SIGNALS_ARGUMENT_PARAMETERS	p1, p2, p3, p4, p5, p6, p7, p8
#define SIGNALS_ARGUMENT_INV_PARAMETERS	p8, p7, p6, p5, p4, p3, p2, p1
#define SIGNALS_VA_ARGUMENTS		va_arg(ap, pt1), va_arg(ap, pt2), va_arg(ap, pt3), va_arg(ap, pt4), va_arg(ap, pt5), va_arg(ap, pt6), va_arg(ap, pt7), va_arg(ap, pt8)

#include "templates/signals/signaln.h"

#undef SIGNALS_SIGNAL_CLASS_NAME
#undef SIGNALS_INSTANCE_CLASS_NAME
#undef SIGNALS_CONDITIONAL_COMMA
#undef SIGNALS_ARGUMENT_LIST
#undef SIGNALS_ARGUMENT_TYPES
#undef SIGNALS_ARGUMENT_PARAMETER_LIST
#undef SIGNALS_ARGUMENT_PARAMETERS
#undef SIGNALS_ARGUMENT_INV_PARAMETERS
#undef SIGNALS_VA_ARGUMENTS

#endif
