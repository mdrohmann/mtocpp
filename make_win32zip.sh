#!/bin/bash
tmpdir=mtoc++_$1
mkdir $tmpdir
cp -r tools License.txt INSTALL win32/* $tmpdir
zip -r mtoc++_win32_$1.zip $tmpdir
rm -rf $tmpdir