// SPDX-FileCopyrightText: 2024-2025, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: BSD-3-Clause


#ifndef SHADOW_INCLUDE_LIB_FS_CREAT_FMCREAT_H_
#define SHADOW_INCLUDE_LIB_FS_CREAT_FMCREAT_H_


#include <config.h>

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include "fs/mkstemp/mkomstemp.h"


inline FILE *fmcreat(const char *restrict path, mode_t m)


// FILE mode_t creat(2)
inline FILE *
fmcreat(const char *restrict path, mode_t m)
{
	int   fd;
	FILE  *fp;

	fd = creat(path, m);
	if (fd == -1)
		return NULL;

	fp = fdopen(fd, "w");
	if (fp == NULL)
		goto fail;

	return fp;
fail:
	close(fd);
	unlink(path);
	return NULL;
}


#endif  // include guard
