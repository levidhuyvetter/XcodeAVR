#ifndef GCC_TM_H
#define GCC_TM_H
#ifndef LIBC_GLIBC
# define LIBC_GLIBC 1
#endif
#ifndef LIBC_UCLIBC
# define LIBC_UCLIBC 2
#endif
#ifndef LIBC_BIONIC
# define LIBC_BIONIC 3
#endif
#ifndef LIBC_MUSL
# define LIBC_MUSL 4
#endif
#ifndef WITH_AVRLIBC
# define WITH_AVRLIBC
#endif
#ifndef WITH_LIBF7_LIBGCC
# define WITH_LIBF7_LIBGCC
#endif
#ifndef WITH_LIBF7_MATH
# define WITH_LIBF7_MATH
#endif
#ifndef WITH_LIBF7_MATH_SYMBOLS
# define WITH_LIBF7_MATH_SYMBOLS
#endif
#ifndef WITH_DOUBLE_COMPARISON
# define WITH_DOUBLE_COMPARISON 2
#endif
#ifndef HAVE_DOUBLE32
# define HAVE_DOUBLE32
#endif
#ifndef HAVE_DOUBLE64
# define HAVE_DOUBLE64
#endif
#ifndef HAVE_DOUBLE_MULTILIB
# define HAVE_DOUBLE_MULTILIB
#endif
#ifndef HAVE_LONG_DOUBLE32
# define HAVE_LONG_DOUBLE32
#endif
#ifndef HAVE_LONG_DOUBLE64
# define HAVE_LONG_DOUBLE64
#endif
#ifndef HAVE_LONG_DOUBLE_MULTILIB
# define HAVE_LONG_DOUBLE_MULTILIB
#endif
#ifndef WITH_DOUBLE32
# define WITH_DOUBLE32
#endif
#ifndef WITH_LONG_DOUBLE64
# define WITH_LONG_DOUBLE64
#endif
#ifdef IN_GCC
# include "options.h"
# include "insn-constants.h"
# include "config/elfos.h"
# include "config/avr/elf.h"
# include "config/avr/avr-arch.h"
# include "config/avr/avr.h"
# include "config/avr/specs.h"
# include "config/dbxelf.h"
# include "config/avr/avr-stdint.h"
# include "config/avr/avrlibc.h"
# include "config/initfini-array.h"
#endif
#if defined IN_GCC && !defined GENERATOR_FILE && !defined USED_FOR_TARGET
# include "insn-flags.h"
#endif
#if defined IN_GCC && !defined GENERATOR_FILE
# include "insn-modes.h"
#endif
# include "defaults.h"
#endif /* GCC_TM_H */
