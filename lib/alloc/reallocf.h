// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: BSD-3-Clause


#ifndef SHADOW_INCLUDE_LIB_ALLOC_REALLOCF_H_
#define SHADOW_INCLUDE_LIB_ALLOC_REALLOCF_H_


#include "config.h"

#include <stddef.h>
#include <stdlib.h>

#include "attr.h"

#include <Optional.h>


#define REALLOCF(p, n, type)                                                  \
(                                                                             \
	_Generic(p, _Optional typeof(type) *:                                 \
		(_Optional typeof(type) *) reallocarrayf(p, (n) ?: 1, sizeof(type)) \
	)                                                                     \
)


ATTR_ALLOC_SIZE(2, 3)
ATTR_MALLOC(free)
inline _Optional void *reallocarrayf(_Optional void *p, size_t nmemb, size_t size);


inline _Optional void *
reallocarrayf(_Optional void *p, size_t nmemb, size_t size)
{
	_Optional void  *q;

	q = reallocarray(p, nmemb ?: 1, size ?: 1);

	if (q == NULL)
		free(p);
	return q;
}


#endif  // include guard
