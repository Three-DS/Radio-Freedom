#!/usr/bin/sh
dir=$(pwd)
cd $1
make && make install && make clean
cd $dir