# An array is a variable containing multiple values. Any variable may be used as an array. 
# There is no maximum limit to the size of an array, nor any requirement that member variables be
# indexed or assigned contiguously. Arrays are zero-based: the first element is indexed with the number 0.

#! /bin/bash

os=('ubuntu' 'windows' 'kali')

# To add element in array
os[3]='mac'

# To update existing element in array
# os[0]='mac'

# To remove element from array
unset os[2]     # 

# To print all elements
echo "${os[@]}"

# To print all elements
echo "${os[*]}"

# To print single element
echo "${os[1]}"

# To print indices of array
echo "${!os[@]}"

# To print length of array
echo "${#os[@]}"

# Any variable can be treated as array
string=abchdgeiwbjljd
echo "${string[@]}"
echo "${string[0]}"
echo "${string[1]}"     # prints nothing because it keeps variable at 0th index
echo "${#string[@]}"

number=1245782346
echo "${number[@]}"


