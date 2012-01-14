#!/bin/bash
echo "Creating MatLab File Exchange export version..."
tmpdir=mtoc++_$1
mkdir $tmpdir
cp -r tools src cmake CMakeLists.txt License.txt INSTALL test $tmpdir
zip -r mtoc++_mlfex_$1.zip $tmpdir
rm -rf $tmpdir
# Also create the windows binaries only
make_win32binszip.sh $1
