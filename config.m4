#
# K2HDKC PHP Extension library
# 
# Copyright 2023 Yahoo Japan Corporation.
# 
# K2HDKC is k2hash based distributed KVS cluster.
# K2HDKC uses K2HASH, CHMPX, FULLOCK libraries. K2HDKC supports
# distributed KVS cluster server program and client libraries.
# 
# For the full copyright and license information, please view
# the license file that was distributed with this source code.
#
# AUTHOR:   Hirotaka Wakabayashi
# CREATE:   Tue, Feb 22 2022
# REVISION:
#

#
# Set k2hdkc php extension name
#
AC_SUBST([PHP_SO_NAME], "k2hdkcpx")
AC_SUBST([PHP_PECL_BASE_NAME], "pecl-k2hdkc")

#
# Load customizable variables
#
AC_CHECK_FILE([configure.custom],
	[
		configure_custom_file="configure.custom"
		custom_git_domain="$(grep '^\s*GIT_DOMAIN\s*=' configure.custom | sed -e 's|^\s*GIT_DOMAIN\s*=\s*||g' -e 's|^\s*||g' -e 's|\s*$||g')"
		custom_git_org="$(grep '^\s*GIT_ORG\s*=' configure.custom | sed -e 's|^\s*GIT_ORG\s*=\s*||g' -e 's|^\s*||g' -e 's|\s*$||g')"
		custom_git_repo="$(grep '^\s*GIT_REPO\s*=' configure.custom | sed -e 's|^\s*GIT_REPO\s*=\s*||g' -e 's|^\s*||g' -e 's|\s*$||g')"
		custom_dev_email="$(grep '^\s*DEV_EMAIL\s*=' configure.custom | sed -e 's|^\s*DEV_EMAIL\s*=\s*||g' -e 's|^\s*||g' -e 's|\s*$||g')"
		custom_dev_name="$(grep '^\s*DEB_NAME\s*=' configure.custom | sed -e 's|^\s*DEB_NAME\s*=\s*||g' -e 's|^\s*||g' -e 's|\s*$||g')"
	],
	[
		configure_custom_file=""
		custom_git_domain="github.com"
		custom_git_org="yahoojapan"
		custom_git_repo="k2hdkc_phpext"
		custom_dev_email="ml-antpickax-support@lycorp.co.jp"
		custom_dev_name="K2HASH_DEVELOPER"
	]
)

#
# Common variables
#
AC_SUBST([CONFIGURECUSTOM], "${configure_custom_file}")
AC_SUBST([GIT_DOMAIN], "${custom_git_domain}")
AC_SUBST([GIT_ORG], "${custom_git_org}")
AC_SUBST([GIT_REPO], "${custom_git_repo}")
AC_SUBST([DEV_EMAIL], "$(echo ${DEBEMAIL:-"${custom_dev_email}"})")
AC_SUBST([DEV_NAME], "$(echo ${DEBFULLNAME:-"${custom_dev_name}"})")

AC_SUBST([HOME_PAGE],  "https://php.k2hdkc.antpick.ax/")
AC_SUBST([PKGLICENSE], [$(grep License LICENSE | sed -e 's/ License//g')])
AC_SUBST([DEBLICENSER],[$(grep Copyright LICENSE | sed -e 's/ *(c)//g')])
AC_SUBST([DEBCOPYING], [$(sed -e 's/^$/./g' -e 's/^/ /g' LICENSE)])

#
# Enable for this extension
#
PHP_ARG_ENABLE([k2hdkcpx], [whether to enable k2hdkc support], [AS_HELP_STRING([--enable-k2hdkcpx], [Enable k2hdkcpx support])], [no])

#
# For PHP Extension
#
if test "$PHP_K2HASH" != "no"; then
	PHP_EVAL_INCLINE($LIBK2HDKC_CFLAGS)
	PHP_EVAL_LIBLINE($LIBK2HDKC_LIBS, K2HDKCPX_SHARED_LIBADD)

	AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
	AC_MSG_CHECKING(for libk2hdkcpx)

	if test -x "$PKG_CONFIG" && $PKG_CONFIG --exists libk2hdkc; then
		K2HDKCPX_INCDIR=`$PKG_CONFIG libk2hdkc --variable=includedir`
		K2HDKCPX_LIBDIR=`$PKG_CONFIG libk2hdkc --variable=libdir`
		K2HDKCPX_VERSION=`$PKG_CONFIG libk2hdkc --modversion`

		AC_MSG_RESULT(from pkgconfig: version $K2HDKCPX_VERSION found in $K2HDKCPX_LIBDIR)
	fi

	if test -z "$K2HDKCPX_LIBDIR"; then
		AC_MSG_RESULT([not found])
		AC_MSG_ERROR([Please install the libk2dkc distribution])
	fi

	PHP_ADD_INCLUDE($K2HDKCPX_INCDIR/k2hdkc)
	PHP_ADD_LIBRARY_WITH_PATH(k2hdkc, $K2HDKCPX_LIBDIR, K2HDKCPX_SHARED_LIBADD)
	PHP_SUBST(K2HDKCPX_SHARED_LIBADD)

	AC_DEFINE(HAVE_K2HDKCPX, 1, [ Have k2hdkcpx support ])

	#
	# Source codes
	#
	PHP_NEW_EXTENSION(k2hdkcpx, k2hdkcpx_func.c k2hdkcpx.c, $ext_shared)
fi

AC_CHECK_PROG(K2HDKCPX_HAVE_PHP_BINARY, [php --version], [yes], [no])

#
# Make PHP version variables
#
if test "${K2HDKCPX_HAVE_PHP_BINARY}" = "yes"; then
	AC_SUBST([K2HDKCPX_PHP_VERSION],       [$(php -r 'echo "".PHP_MAJOR_VERSION.".".PHP_MINOR_VERSION;')])
	AC_SUBST([K2HDKCPX_PHP_RAW_VERSION],   [$(php -r 'echo "".PHP_MAJOR_VERSION."".PHP_MINOR_VERSION;')])
	AC_SUBST([K2HDKCPX_PHP_MAJOR_VERSION], [$(php -r 'echo "".PHP_MAJOR_VERSION."";')])
	AC_SUBST([K2HDKCPX_PHP_MINOR_VERSION], [$(php -r 'echo "".PHP_MINOR_VERSION."";')])
	AC_SUBST([K2HDKCPX_EXT_PKGNAME],       [$(head -n 1 $(pwd)/ChangeLog | awk '{print $1}')])
	AC_SUBST([K2HDKCPX_EXT_VERSION],       [$(head -n 1 $(pwd)/ChangeLog | sed -e 's/[(]//g' -e 's/[)]//g' | awk '{print $2}' | sed -e 's/-.*$//g')])

	AC_DEFINE_UNQUOTED(PHP_K2HDKCPX_VERSION, ["$(head -n 1 $(pwd)/ChangeLog | sed -e 's/[(]//g' -e 's/[)]//g' | awk '{print $2}' | sed -e 's/-.*$//g')"], [ PHP Extension version ])
else
	AC_SUBST([K2HDKCPX_PHP_VERSION],       "0.0")
	AC_SUBST([K2HDKCPX_PHP_RAW_VERSION],   "00")
	AC_SUBST([K2HDKCPX_PHP_MAJOR_VERSION], "0")
	AC_SUBST([K2HDKCPX_PHP_MINOR_VERSION], "0")
	AC_SUBST([K2HDKCPX_EXT_PKGNAME],       "php-pecl-k2hdkc")
	AC_SUBST([K2HDKCPX_EXT_VERSION],       "0.0.0")

	AC_DEFINE(PHP_K2HDKCPX_VERSION,     "0.0.0", [ PHP Extension version ])
fi

#
# AC Macros for checking dependencies, etc
#
# [NOTE]
# The macros below are the macros that were output when I ran autoscan manually.
#
AC_CHECK_FUNCS([strncasecmp])
AC_CHECK_HEADERS([fcntl.h])
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_FUNC_MALLOC
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_RANLIB
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

#
# Make changelog strings for rpm
#
if test -f $(pwd)/buildutils/make_rpm_changelog.sh; then
	AC_SUBST([K2HDKCPX_RPMCHANGELOG], [$($(pwd)/buildutils/make_rpm_changelog.sh $(pwd)/ChangeLog)])
fi

#
# Set input files
#
if test -d buildutils; then
	AC_CONFIG_FILES([
		$(pwd)/buildutils/php-pecl-k2hdkc.spec
		$(pwd)/buildutils/k2hdkcpx.ini
		$(pwd)/buildutils/rules
		$(pwd)/buildutils/control.in
		$(pwd)/buildutils/copyright
		$(pwd)/buildutils/watch
		$(pwd)/buildutils/upstream/metadata
		$(pwd)/buildutils/APKBUILD.templ
	])
fi

#
# Local variables:
# tab-width: 4
# c-basic-offset: 4
# End:
# vim600: noexpandtab sw=4 ts=4 fdm=marker
# vim<600: noexpandtab sw=4 ts=4
#
