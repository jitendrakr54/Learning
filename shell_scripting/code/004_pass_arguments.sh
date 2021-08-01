# Pass Arguments to a Bash-Script
# 0th will contain script name
# ./004_pass_arguments.sh Jit kum gup
# "$@" stores all arguments as an array
# "$#" stores number of arguments

#! /bin/bash

echo $0 $1 $2 $3 ' > echo $0 $1 $2 $3'
args=("$@")
echo ${args[0]} ${args[1]} ${args[2]}
echo $@
echo $#