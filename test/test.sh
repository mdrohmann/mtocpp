#!/bin/sh

FILES=*.m

for MFILE in $FILES
do
    echo "Checking $MFILE ..."
    CCFILE="${MFILE%.m}.cc"
    CCREFFILE="${MFILE%.m}_ref.cc"
    ../mtoc $MFILE 0 conf > $CCFILE
    if diff -u $CCFILE $CCREFFILE > $MFILE.diff
    then
        echo " (passed)"
        rm $MFILE.diff
    else
        echo " (failed)"
    fi
done

