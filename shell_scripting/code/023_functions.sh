#! /bin/bash

# Functions make scripts easier to maintain. Basically it breaks up the program into smaller pieces.
#  A function performs an action defined by you, and it can return a value if you wish.

function Hello() {
    echo "Hello"
}

quit() {
    exit
}

# quit
# Hello
# echo "foo"

# Hello
# quit
# echo "foo"

# Hello
# echo "foo"
# quit



# Passing parameter to a function

# function print() {
#     echo $1
# }

# print Hello
# print World
# print Again


function print() {
    echo $1 $2 $3
}
print Hello World Again


