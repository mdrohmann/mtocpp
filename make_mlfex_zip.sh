#!/bin/bash
tmpdir=mtoc++_$1
mkdir $tmpdir
cp -r tools src cmake CMakeLists.txt INSTALL test win32 $tmpdir
zip -r mtoc++_mlfex_$1.zip $tmpdir
rm -rf $tmpdir
