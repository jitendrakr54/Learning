#until loops

#! /bin/bash

# Syntax:
# until [ condition ]
# do
#     command1
#     command2
#     ...
#     ....
#     commandn
# done

n=1

# until [ $n -ge 10 ]
# until [ $n -gt 10 ]
until (( $n > 10 ))
do
    echo $n
    # n=$(( n+1 ))
    # (( n++ ))
    (( ++n ))
done