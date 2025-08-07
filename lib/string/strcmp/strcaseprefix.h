// SPDX-FileCopyrightText: 2024-2025, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: BSD-3-Clause


#ifndef SHADOW_INCLUDE_LIB_STRING_STRCMP_STRCASEPREFIX_H_
#define SHADOW_INCLUDE_LIB_STRING_STRCMP_STRCASEPREFIX_H_


#include "config.h"

#include <stddef.h>
#include <string.h>

#include "attr.h"
#include "cast.h"

#include <Optional.h>


// string case-insensitive prefix
#define strcaseprefix(s, prefix)                                      \
({                                                                    \
	_Optional const char  *p_;                                    \
	                                                              \
	p_ = strcaseprefix_(s, prefix);                               \
	                                                              \
	_Generic(s,                                                   \
		const char *:                              p_,        \
		const void *:                              p_,        \
		char *:        const_cast(_Optional char *, p_),      \
		void *:        const_cast(_Optional char *, p_)       \
	);                                                            \
})


ATTR_STRING(1) ATTR_STRING(2)
inline _Optional const char *strcaseprefix_(const char *s, const char *prefix);


// strprefix_(), but case-insensitive.
inline _Optional const char *
strcaseprefix_(const char *s, const char *prefix)
{
	if (strncasecmp(s, prefix, strlen(prefix)) != 0)
		return NULL;

	return s + strlen(prefix);
}


#endif  // include guard
