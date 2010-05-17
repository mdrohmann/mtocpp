#!/bin/sh

FILES="test/+grid/+rect/@rectgrid/*.m test/+grid/+rect/doxygen_in_namespace.m ./*.m"

for MFILE in $FILES
do
    echo "Checking $MFILE ..."
    MBFILE=`basename $MFILE`
    CCFILE="${MBFILE%.m}.cc"
    CCREFFILE="${MBFILE%.m}_ref.cc"
    ../mtoc $MFILE 0 conf > $CCFILE
    if diff -u $CCFILE $CCREFFILE > $MBFILE.diff
    then
        echo " (passed)"
        rm $MBFILE.diff
    else
        echo " (failed)"
    fi
done

