#! /bin/bash

# The break statement is used to exit the current loop before its normal ending.
# The continue statement resumes iteration of an enclosing for, while, until or select loop.

# for (( i=0; i<=10; i++ ))
# do
#     if [ $i -gt 5 ]
#     then
#         break
#     fi
#     echo "$i"
# done

for (( i=0; i<=10; i++ ))
do
    # if [ $i -eq 5 -o $i -eq 6 ]
    if [[ $i -eq 5 || $i -eq 6 ]]
    then
        continue
    fi
    echo "$i"
done