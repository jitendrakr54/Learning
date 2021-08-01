#! /bin/bash

usage() {
    echo "You need to provide an argument: "
    echo "usage: $0 file name"
}

is_file_exist() {
    local file="$1"
    [[ -f "$file" ]] && return 0 || return 1  # behaves like ternary operator
    # So if [[ true ]] then 1 otherwise false
}

[[ $# -eq 0 ]] && usage

if ( is_file_exist "$1")
then 
echo "$1 file found!"
else
    echo "$1 file not found!"
fi

n=0
[[ $n -eq 1 ]] && echo "hello" || echo "hi"