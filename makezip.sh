#!/bin/bash
tmpdir=mtoc++_$1
mkdir $tmpdir
cp -r tools src cmake License.txt CMakeLists.txt INSTALL test $tmpdir
zip -r mtoc++_$1.zip $tmpdir
rm -rf $tmpdir
