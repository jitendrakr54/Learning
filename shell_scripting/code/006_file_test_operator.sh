#! /usr/bin/bash

# -d, -f, -s, -w, -b, -c, -r, -w, -x
# -r, -w, -x -> To check whether file has read, write, execute permission

echo -e "Enter the file name: \c"  # -e is used to interpret /c
read file_name

# -e used to check if file exist or not
# if [ -e $file_name ]              
# then
#     echo "$file_name found"
# else
#     echo "$file_name not found"
# fi

# -f used to check if it's regular file
# if [ -f $file_name ]              
# then
#     echo "$file_name is regular file"
# else
#     echo "$file_name is not a regular file"
# fi

# -d used to check if it's directory
# if [ -d $file_name ]             
# then
#     echo "$file_name is directory"
# else
#     echo "$file_name is not a directory"
# fi

# -s -> checks whether file is empty or not
if [ -s $file_name ]             
then
    echo "$file_name is not empty"
else
    echo "$file_name is empty"
fi