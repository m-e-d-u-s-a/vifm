/* vifm
 * Copyright (C) 2013 xaizek.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef VIFM__IO__IOC_H__
#define VIFM__IO__IOC_H__

#include <sys/types.h> /* gid_t mode_t uid_t */

#include "ioe.h"

/* ioc - I/O common - Input/Output common */

typedef struct
{
	io_err_cb errors_cb;
	io_errlst_t errors;
}
io_result_t;

typedef struct
{
	union
	{
		const char *path;
		const char *src;
	}
	arg1;

	union
	{
		const char *dst;
		const char *target;
	}
	arg2;

	union
	{
		/* Whether operation should consider parent elements of path. */
		int process_parents;
		int overwrite;
		mode_t mode;
#ifndef _WIN32
		uid_t uid;
		gid_t gid;
#endif
	}
	arg3;

	int cancellable;

	io_result_t result;
}
io_args_t;

#endif /* VIFM__IO__IOC_H__ */

/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 noexpandtab cinoptions-=(0 : */
/* vim: set cinoptions+=t0 : */