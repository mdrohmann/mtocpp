#!/bin/bash
wbins=mtoc++_win32bins_$1.zip
echo "Packing current windows binaries from win32 into $wbins..."
zip $wbins win32/*
mv $wbins ~/aghwww/MoRePaS/software/mtocpp
