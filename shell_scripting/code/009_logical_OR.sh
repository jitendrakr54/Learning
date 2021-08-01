#! /bin/bash/

age=17

if [ $age -gt 18 ] || [ "$age" -lt 30 ]
# if [ "$age" -gt 18 -o "$age" -lt 30 ]
# if [[ "$age" -gt 18 || "$age" -lt 30 ]]
then
    echo "valid age"
else
    echo "age not valid"
fi