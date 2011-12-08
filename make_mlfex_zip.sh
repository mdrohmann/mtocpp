#!/bin/bash
echo "Creating MatLab File Exchange export version..."
tmpdir=mtoc++_$1
mkdir $tmpdir
cp -r tools src cmake CMakeLists.txt INSTALL test $tmpdir
zip -r mtoc++_mlfex_$1.zip $tmpdir
rm -rf $tmpdir
wbins=mtoc++_win32bins_$1.zip
echo "Packing current windows binaries from win32 into $wbins..."
zip $wbins win32/*
mv $wbins ~/aghwww/MoRePaS/software/mtocpp
