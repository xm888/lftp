/*
 * lftp and utils
 *
 * Copyright (c) 1996-1997 by Alexander V. Lukyanov (lav@yars.free.net)
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
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef CONFIG_H
#define CONFIG_H
@TOP@

/* the name of package */
#undef PACKAGE

/* the version of package */
#undef VERSION

/* Define if inline functions a la GCC are available.  */
#undef HAVE_INLINE

/* Define as __inline if that's what the C compiler calls it.  */
#undef c_inline

#ifndef __cplusplus
# ifdef c_inline
#  define inline c_inline
# endif
#endif

/* Define if sysinfo is available.  */
#undef HAVE_SYSINFO

/* Define if __NR_sysinfo is available.  */
#undef HAVE_NRSYSINFO

/* Define if ???.  */
#undef HAVE_ALPHASORT_DECLARATION

/* Define if function attributes a la GCC 2.5 and higher are available.  */
#undef HAVE_GNUC25_ATTRIB

/* Define if constant functions a la GCC 2.5 and higher are available.  */
#undef HAVE_GNUC25_CONST

/* Define if nonreturning functions a la GCC 2.5 and higher are available.  */
#undef HAVE_GNUC25_NORETURN

/* Define if printf-format argument lists a la GCC are available.  */
#undef HAVE_GNUC25_PRINTFFORMAT

/* Set this to the canonical Debian architecture string for this CPU type. */
#undef ARCHITECTURE

/* Set this to 1 to build new archives by default. */
#define BUILDOLDPKGFORMAT 0

/* Set this string to append something to the version number. */
#define ARCHBINFMT ""

/* Define to 1 if NLS is requested.  */
#undef ENABLE_NLS

/* Define as 1 if you have catgets and don't want to use GNU gettext.  */
#undef HAVE_CATGETS

/* Define as 1 if you have gettext and don't want to use GNU gettext.  */
#undef HAVE_GETTEXT

/* Define if your locale.h file contains LC_MESSAGES.  */
#undef HAVE_LC_MESSAGES

/* Define as 1 if you have the stpcpy function.  */
#undef HAVE_STPCPY

#undef HAVE_SYS_ERRLIST_DECL

#undef HAVE_HSTRERROR_DECL

#undef HAVE_H_ERRLIST_DECL

#undef HAVE_H_ERRNO

#undef HAVE_H_ERRNO_DECL

#undef NEED_YYWRAP

#undef HAVE_POLL

#undef HAVE_STRERROR

#undef HAVE_HSTRERROR

#undef HAVE_DLOPEN

#undef HAVE_RES_SEARCH

#undef HAVE_RES_SEARCH_DECL

#undef HAVE_RES_GETHOSTBYNAME2_DECL

#undef HAVE_VSNPRINTF_DECL

#undef HAVE_STRCASECMP_DECL

#undef HAVE_STRPTIME_DECL

#undef HAVE_RANDOM_DECL

#undef HAVE_INET_ATON_DECL

/* Define to `int' if <sys/socket.h> doesn't define.  */
#undef socklen_t

/* define if you are building with SOCKS support */
#undef SOCKS4

/* define if you are building with SOCKSv5 support */
#undef SOCKS5

/* define if you are building with SOCKS-Dante support */
#undef SOCKS_DANTE

/* build modular lftp */
#undef WITH_MODULES

/* md5 support is present in libc or libcrypt */
#undef HAVE_MD5

@BOTTOM@

#if !defined(HAVE_LSTAT)
# define lstat(file,stp)     stat((file),(stp))
#endif

#if !defined(HAVE_SETPGID) && !defined(SETPGRP_VOID)
# define setpgid(pid, pgrp)  setpgrp((pid),(pgrp))
#endif

#ifdef __cplusplus
# define CDECL extern "C"
# define CDECL_BEGIN CDECL {
# define CDECL_END   }
#else
# define CDECL
# define CDECL_BEGIN
# define CDECL_END
#endif

#ifndef HAVE_STRERROR
/* there is substitute in lib/ */
CDECL const char *strerror(int);
#endif

#ifndef HAVE_SETLOCALE
# define setlocale(Category, Locale)
#endif

#if ENABLE_NLS
# ifndef HAVE_LIBINTL_H
#  define HAVE_LIBINTL_H 1
# endif
# include <libintl.h>
# define _(Text) gettext (Text)
#else
# define bindtextdomain(Domain, Directory)
# define textdomain(Domain)
# define _(Text) Text
# define gettext(z) z
# define dgettext(d,z) z
# define dcgettext(d,z,c) z
#endif
#define N_(Text) Text

#ifndef PARAMS
# ifdef __STDC__
#  define PARAMS(x) x
# else
#  define PARAMS(x) ()
# endif
#endif

#define INET6 (defined(AF_INET6) \
	       && defined(HAVE_GETNAMEINFO) \
	       && defined(HAVE_GETADDRINFO))

#if defined(SOCKS4) || defined(SOCKS_DANTE)
# define connect     Rconnect
# define getsockname Rgetsockname
# define bind	     Rbind
# define accept	     Raccept
# define listen	     Rlisten
/* select, poll ? */
CDECL void SOCKSinit(const char *);
#endif
#ifdef SOCKS_DANTE
# define rresvport Rrresvport
# define bindresvport Rbindresvport
# define gethostbyname Rgethostbyname
# define gethostbyname2 Rgethostbyname2
# define sendto Rsendto
# define recvfrom Rrecvfrom
# define recvfrom Rrecvfrom
# define write Rwrite
# define writev Rwritev
# define send Rsend
# define sendmsg Rsendmsg
# define read Rread
# define readv Rreadv
# define recv Rrecv
# define recvmsg Rrecvmsg
#endif

#ifdef SOCKS5
# define SOCKS
# include <socks.h>
#endif

#if defined __MSDOS__ || defined __CYGWIN32__
# define NATIVE_CRLF 1
#endif

#define E_RETRY(e) ((e)==EAGAIN || (e)==EWOULDBLOCK || (e)==EINTR)
#define E_LOCK_IGNORE(e) ((e)==EINVAL || (e)==ENOLCK)

#ifndef HAVE_RANDOM
#define srandom(x) srand((x))
#define random() ((long)(rand()/(RAND_MAX+1.0)*2147483648.0))
#endif

#ifndef HAVE_INET_ATON
# define inet_aton(host,addr) (((addr)->s_addr=inet_addr(host))!=-1)
#endif

/* Tell the compiler when a conditional or integer expression is
   almost always true or almost always false.  */
#ifndef HAVE_BUILTIN_EXPECT
# define __builtin_expect(expr, val) (expr)
#endif

#if defined(__cplusplus) && !defined(HAVE_CXX_BOOL)
typedef unsigned _bool;
#define bool   _bool
#define false  0U
#define true   1U
#endif

#ifdef __GNUC__
# define PRINTF_LIKE(n,m) __attribute__((format(printf,n,m)))
#else
# define PRINTF_LIKE(n,m)
#endif

#ifndef VA_COPY
# define VA_COPY(to,from) (memcpy(&(to),&(from),sizeof((to))))
#endif

#endif /* CONFIG_H */
