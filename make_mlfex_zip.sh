#!/bin/bash
tmpdir=mtoc++_$1
mkdir $tmpdir
cp -r tools src cmake CMakeLists.txt INSTALL test $tmpdir
zip -r mtoc++_mlfex_$1.zip $tmpdir
rm -rf $tmpdir
wbins=mtoc++_win32bins_$1.zip
zip $wbins win32/*
mv $wbins ~/aghwww/MoRePaS/software/mtocpp
