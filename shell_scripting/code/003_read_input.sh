# Reading input
# "read" command is used to take input from user

# echo "Enter name"
# read name
# echo "name is: $name"

# read multiple input 
# echo "Enter names"
# read name1 name2 name3
# echo "names are: $name1, $name2, $name3"

# read input on same line as on output
# read -p 'username: ' user_name
# read -sp 'password: ' user_password
# echo "username: $user_name"
# echo "password: $user_password"

# read onput in an array
# echo "Enter names:"
# read -a names
# echo ${names[0]} ${names[1]}


echo "Enter names:"
read
echo "Name: $REPLY"
