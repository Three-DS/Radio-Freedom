#!/bin/sh

export DEVKITPRO=/opt/radiofreedom
export DEVKITARM=/opt/radiofreedom/arm

GNUBase=/opt/radiofreedom/arm
GNUTarget=arm-gnu-eabi

#export PATH=$PATH:$GNUBase/bin
#export PATH=$PATH:/opt/radiofreedom/arm/bin

. $(pwd)/versions.iii.inc

srcdir=$(pwd)

#---------------------------------------------------------------------------------
# Install and build the gba crt
#---------------------------------------------------------------------------------

cp -v crtls/arm/* $GNUBase/$GNUTarget/lib/
cd $GNUBase/$GNUTarget/lib/
sh build-crt.sh

cd $srcdir

sh ./buildtool.sh dstools/$DSTOOL_VER arm
sh ./buildtool.sh ndstool/$NDSTOOL_VER arm
sh ./buildtool.sh dlditool/$DLDITOOL_VER arm
sh ./buildtool.sh dfu-util/$DFU_UTIL_VER arm
sh ./buildtool.sh mmutil/$MMUTIL_VER arm
sh ./buildtool.sh gbatools/$GBATOOLS_VER arm
sh ./buildtool.sh gp32tools/$GP32_TOOLS_VER arm
sh ./buildtool.sh 3dstools/$TOOLS3DS_VER arm
sh ./buildtool.sh 3dslink/$LINK3DS_VER arm
sh ./buildtool.sh grit/$GRIT_VER arm
sh ./buildtool.sh general-tools/$GENERAL_TOOLS_VER arm
sh ./buildtool.sh picasso/$PICASSO_VER arm
sh ./buildtool.sh makerom arm
sh ./buildtool.sh bannertool arm

sh ./buildlib.sh libgba/$LIBGBA_VER
sh ./buildlib.sh libnds/$LIBNDS_VER
sh ./buildlib.sh dswifi/$DSWIFI_VER
sh ./buildlib.sh maxmod/$MAXMOD_VER
sh ./buildlib.sh default_arm7/$DEFAULT_ARM7_VER
sh ./buildlib.sh libfat/$LIBFAT_VER/nds
sh ./buildlib.sh libmirko/$LIBMIRKO_VER
sh ./buildlib.sh libfilesystem/$FILESYSTEM_VER
sh ./buildlib.sh libctru/$LIBCTRU_VER
sh ./buildlib.sh libcitro3d/$CITRO3D_VER

#rm -r $GNUBase/$GNUTarget/sys-include/*
#rmdir $GNUBase/$GNUTarget/sys-include

#mxml-2.6 complains over this
#rename $GNUBase/$GNUTarget/include/pthread.h $GNUBase/$GNUTarget/include/_pthread.h