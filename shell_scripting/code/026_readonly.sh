#! /bin/bash

# readonly command
# readonly command can be used to to make you variables and functions read only that means you cannot
# change the value of variables or you can not overwrite a function.

var=31

readonly var

var=50

echo "var => $var"

hello() {
    echo "Hello World"
}

readonly -f hello   # -f is required to make function readonly

hello() {
    echo "Hello World Again"
}

readonly -p   # it shows all the readonly variables

readonly -f   # It shows readonly functions

