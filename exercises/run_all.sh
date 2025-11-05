#!/bin/bash

export CC=gcc
for dn in */solution
do
    printf "=%.0s" $(seq 80)
    echo
    echo $dn
    cd $dn
    exe=$(dirname $dn)
    exe=${exe:3}
    make clean
    make
    if [ -f input.txt ];
    then
        ./${exe} < input.txt
    else
        ./${exe}
    fi
    cd ../../
done
