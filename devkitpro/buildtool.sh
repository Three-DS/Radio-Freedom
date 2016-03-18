#!/usr/bin/sh
dir=$(pwd)
cd $1
sh ./configure --prefix=/opt/radiofreedom/$2
make && make install && make clean
cd $dir