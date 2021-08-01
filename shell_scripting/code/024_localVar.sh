#! /bin/bash

# LOCAL VARIABLES IN FUNCTIONS : 
# Variables defined within functions are global, i.e. their values are known throughout the entire shell program keyword 
# “local” inside a function definition makes referenced variables “local” to that function. Local variables can be created by 
# using the keyword local.

# Local variables

function print() {
    # name=$1
    local name=$1
    echo "the name is $name"
}

name="Tom"

echo "The name is $name : Before"

print Max

echo "The name is $name : After"