// SPDX-FileCopyrightText: 2024-2025, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: BSD-3-Clause


#include <config.h>

#include "fs/open/fmcreat.h"

#include <stdio.h>
#include <sys/types.h>


extern inline FILE *fmcreat(const char *restrict path, mode_t m);
