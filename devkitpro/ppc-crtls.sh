#!/bin/sh

export DEVKITPRO=/opt/radiofreedom
export DEVKITPPC=/opt/radiofreedom/ppc

GNUBase=/opt/radiofreedom/ppc
GNUTarget=powerpc-gnu-eabi

#export PATH=$PATH:$GNUBase/bin
#export PATH=$PATH:/opt/radiofreedom/ppc/bin

. $(pwd)/versions.iii.inc

#---------------------------------------------------------------------------------
# Install and build the wii crt
#---------------------------------------------------------------------------------

cp -v crtls/ppc/* $GNUBase/$GNUTarget/lib/

sh ./buildtool.sh general-tools/$GENERAL_TOOLS_VER ppc
sh ./buildtool.sh gamecube-tools/$GAMECUBE_TOOLS_VER ppc
sh ./buildtool.sh wiiload/$WIILOAD_VER ppc

sh ./buildlib.sh libogc/$LIBOGC_VER
sh ./buildfatlib.sh libfat/$LIBFAT_VER/libogc

