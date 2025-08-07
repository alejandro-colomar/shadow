// SPDX-FileCopyrightText: 2022-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: BSD-3-Clause


#include "config.h"

#include "string/strcpy/stpecpy.h"


#if !defined(HAVE_STPECPY)
extern inline _Optional char *stpecpy(_Optional char *dst, char *end, const char *restrict src);
#endif
