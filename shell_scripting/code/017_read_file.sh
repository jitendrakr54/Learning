# How do I read a text file line by line under a Linux or UNIX-like system using BASH shell?
# You can use while..do..done bash loop to read file line by line on a Linux, OSX, or Unix-like system.
# There are basically three ways to read file content using bash.
# 1a: While loop: Single line at a time: Input redirection.
# 1b: While loop: Single line at a time:
# Open the file, read from a file descriptor (in this case file descriptor #4).
# 2: While loop:  Read file into single variable and parse.

#! /bin/bash

# while read p
# do
#     echo $p
# done < 016_sleep.sh

# output of cat is input to the pipe means write output of cat to pipe
# then read from pipe
# cat 016_sleep.sh | while read p
# do
#     echo $p
# done

# while IFS=' ' read -r line
# do
#     echo $line
# done < 016_sleep.sh

while IFS=' ' read -r line
do
    echo $line
done < /etc/host.conf