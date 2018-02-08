#!/usr/bin/sh
dir=$(pwd)
cd $1
make ogc-release && make ogc-install && make ogc-clean
cd $dir