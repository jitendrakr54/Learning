# using sleep and open terminal with WHILE Loops

#! /bin/bash

# n=1
# while (( $n <= 10 ))
# do
#     echo "$n"
#     # n=$(( n+1 ))
#     # (( n++ ))
#     (( ++n ))
#     sleep 1
# done

# n=1
# while [ $n -le 3 ]
# do
#     (( ++n ))
#     gnome-terminal &    # to open gnome terminal
# done

n=1
while [ $n -le 3 ]
do
    (( ++n ))
    xterm &    # to open gnome terminal
done