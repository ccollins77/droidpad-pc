#
# This file is part of DroidPad.
# DroidPad lets you use an Android mobile to control a joystick or mouse
# on a Windows or Linux computer.
#
# DroidPad is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# DroidPad is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with DroidPad, in the file COPYING.
# If not, see <http://www.gnu.org/licenses/>.
#
SUBDIRS = lib
bin_PROGRAMS = droidpad # tlstest

SRC_IF_GUI = \
		   if-gui/droidFrame.cpp	if-gui/droidFrame.hpp	\
		   if-gui/droidApp.cpp		if-gui/droidApp.hpp	\
		   if-gui/customHost.cpp	if-gui/customHost.hpp	\
		   if-gui/about.cpp		if-gui/about.hpp	\
		   if-gui/axisTweak.cpp		if-gui/axisTweak.hpp	\
		   if-gui/pageSizer.cpp		if-gui/pageSizer.hpp	\
		   if-gui/wxImagePanel.cpp	if-gui/wxImagePanel.hpp	\
		   if-gui/qrPanel.cpp		if-gui/qrPanel.hpp	\
		   if-gui/reorderDialog.cpp	if-gui/reorderDialog.hpp\
		   if-gui/preferences.cpp	if-gui/preferences.hpp	\
		   if-gui/devicePair.cpp	if-gui/devicePair.hpp	\
		   if-gui/setup.cpp		if-gui/setup.hpp	\
		   if-gui/help.cpp		if-gui/help.hpp
droidpad_SOURCES =

if IF_GUI
  droidpad_SOURCES += $(SRC_IF_GUI)
  droidpad_LDADD = @WXLIBS@ @OPENSSL_LIBS@ -lqrencode
  droidpad_CXXFLAGS = @WXCPPFLAGS@ @OPENSSL_INCLUDES@
else
  droidpad_LDADD = @WXBASELIBS@ @OPENSSL_LIBS@
  droidpad_CXXFLAGS = @WXBASECPPFLAGS@ @OPENSSL_INCLUDES@
endif

droidpad_CXXFLAGS += -Ilib
droidpad_LDADD += lib/libdroidpad.la


AM_CPPFLAGS = -DPREFIX='"$(prefix)"'

if OS_WIN32
if OS_64BIT
droidpad_LDFLAGS = -Wl,--enable-auto-import
else
droidpad_LDFLAGS = -Wl,--enable-auto-import --enable-stdcall-fixup
endif
droidpad_LDADD += -lws2_32 lib/ext/win32/libjs.la -luuid
droidpad_CXXFLAGS += -Ilib/msw


# Currently just update UI
droidpad_SOURCES +=	\
		if-gui/updateDisplay.cpp	if-gui/updateDisplay.hpp

# Test mode
if MSW_TESTMODE
droidpad_SOURCES +=	if-gui/driverChoice.cpp	if-gui/driverChoice.hpp
endif

if IF_GUI
# http://www.gnu.org/software/hello/manual/automake/Options.html
pkg_verbose = $(pkg_verbose_$(V))
pkg_verbose_ = $(pkg_verbose_$(AM_DEFAULT_VERBOSITY))
pkg_verbose_0 = @echo "  RES    $@";

droidpad_res_CFLAGS = @WXCPPFLAGS@ -I..

if-gui/droidpad.res: if-gui/droidpad.rc
	$(pkg_verbose)${host_alias}-windres $(droidpad_res_CFLAGS) if-gui/droidpad.rc -O coff -o if-gui/droidpad.res

clean-local:
	-rm -f if-gui/droidpad.res

droidpad_LDADD += if-gui/droidpad.res -lws2_32 ${prefix}/lib/libsetupapi.a

EXTRA_DIST = if-gui/droidpad.rc
CLEANFILES = if-gui/droidpad.res
endif

if OS_64BIT
# droidpad_LDFLAGS += -static-libgcc
AM_CPPFLAGS += -DOS_64BIT
endif

endif

# For all unices
if OS_UNIX
AM_CPPFLAGS += -DOS_UNIX
endif
if OS_LINUX
AM_CPPFLAGS += -DOS_LINUX
endif
if OS_WIN32
AM_CPPFLAGS += -DOS_WIN32
endif

# TLS test
# tlstest_SOURCES = tlsTest.c	tlsTest.h
# tlstest_LDADD = @OPENSSL_LIBS@
# if OS_WIN32
# tlstest_LDADD += -lsetupapi -lws2_32 -lgdi32
# endif
