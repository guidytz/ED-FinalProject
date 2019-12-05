#!/bin/bash

echo "Running tests for trees"
echo -n "Type the tree you want to test: "
read treeName

if [[ "$treeName" == "RN" ]] 
then
    cd RN
    make all
    cd ..
    for file in "test_files/texts"/*
    do
        result=${file##*/}
        result=${result[@]//.txt/-RN.txt}
        result=results/$result
        RN/contador $file test_files/operations/op_1.txt $result
    done
elif [[ "$treeName" == "Splay" ]] 
then
    cd Splay
    make all
    cd ..
    for file in "test_files/texts"/*
    do
        result=${file##*/}
        result=${result[@]//.txt/-Splay.txt}
        result=results/$result
        RN/contador $file test_files/operations/op_1.txt $result
    done
else 
    echo "Not a valid tree"
    echo "Possible: RN or Splay"
fi