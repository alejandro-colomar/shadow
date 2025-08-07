// SPDX-FileCopyrightText: 2022-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: BSD-3-Clause


#include "config.h"

#include "string/sprintf/stpeprintf.h"

#include <stdarg.h>


#if !defined(HAVE_STPEPRINTF)
extern inline _Optional char *stpeprintf(_Optional char *dst, char *end, const char *restrict fmt,
    ...);
extern inline _Optional char *vstpeprintf(_Optional char *dst, char *end, const char *restrict fmt,
    va_list ap);
#endif
