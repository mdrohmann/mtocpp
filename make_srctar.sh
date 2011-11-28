#!/bin/bash
tmpdir=mtoc++_$1
mkdir $tmpdir
cp -r tools src cmake License.txt CMakeLists.txt INSTALL test $tmpdir
tar -czf mtoc++_src_$1.tar.gz $tmpdir
rm -rf $tmpdir