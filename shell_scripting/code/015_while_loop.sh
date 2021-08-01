#!/bin/bash

# Syntax
# while [ condition ]
# do
#     command1
#     command2
#     command3
# done

n=1
# while [ $n -le 10 ]
while (( $n <= 10 ))
do
    echo "$n"
    # n=$(( n+1 ))
    # (( n++ ))
    (( ++n ))
done