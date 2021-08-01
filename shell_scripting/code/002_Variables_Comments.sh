# this is a comment
# there are 2 types of variable in Shell - System variable, User defined variable
# System variables are created and maintained by Linux/Unix operating system
# System variables are usually defined in capital letter
# variable name doesn't start with number
#! /usr/bin/bash

echo Our shell name is $BASH
echo $BASH_VERSION
echo $HOME
echo $PWD

name=Jit
echo Name is: $name

10val=10                # error, not allowed
echo value $10val