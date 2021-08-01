#! /bin/bash

# use for loop to execute commands
# for command in ls pwd date
# do
#     echo "---------------$command---------------"
#     $command
# done

# * means it refers all files within current directory
for item in *
do
    if [ -f $item ]
    then
        echo $item
    fi
done