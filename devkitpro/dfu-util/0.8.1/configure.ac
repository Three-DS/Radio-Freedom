#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT([dfu-util],[0.8.1],[dfu-util@lists.gnumonks.org],,[http://dfu-util.gnumonks.org])
AC_CONFIG_AUX_DIR(m4)
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_HEADERS([config.h])

AC_DEFUN([PKG_CHECK_MODULES_STATIC],
[AC_REQUIRE([PKG_PROG_PKG_CONFIG])dnl
_save_PKG_CONFIG=$PKG_CONFIG
PKG_CONFIG="$PKG_CONFIG --static"
PKG_CHECK_MODULES([$1], [$2], [$3], [$4], [$5])
PKG_CONFIG=$_save_PKG_CONFIG[]dnl
])

# Test for new silent rules and enable only if they are available
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
# On FreeBSD the libusb-1.0 is called libusb and resides in system location
AC_CHECK_LIB([usb], [libusb_init],, [native_libusb=no],)
AS_IF([test x$native_libusb = xno], [
    PKG_CHECK_MODULES_STATIC([USB], [libusb-1.0 >= 1.0.0],,
        AC_MSG_ERROR([*** Required libusb-1.0 >= 1.0.0 not installed ***]))
])
AC_CHECK_LIB([usbpath],[usb_path2devnum],,,-lusb)

LIBS="$LIBS $USB_LIBS"
CFLAGS="$CFLAGS $USB_CFLAGS"

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([usbpath.h windows.h sysexits.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MEMCMP
AC_CHECK_FUNCS([ftruncate getpagesize nanosleep err])

AC_CONFIG_FILES(Makefile src/Makefile doc/Makefile)
AC_OUTPUT
