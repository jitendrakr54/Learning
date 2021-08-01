# How to append output to the end of text file

#! /usr/bin/bash

echo -e "Enter the file name: \c"
read file_name

if [ -f $file_name ]
then
    if [ -w $file_name ]
    then
        echo "Type something... Press ctrl+d to quit"
        cat >> $file_name
    else
        echo "$file_name doesn't have write permission!"
    fi
else
    echo "$file_name not found"
fi
