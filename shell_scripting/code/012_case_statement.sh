#! /bin/bash

# case expression in
#     pattern1 )
#         statements ;;
#     pattern2 )
#         statements ;;
#     ...
# esac

vehicle=$1                      # take 1st arg from command line

case $vehicle in
    "car" )                                        # we can pass regular expression and can be checked same in case
        echo "Rent of $vehicle is 100 dollar" ;;
    "jeep" )
        echo "Rent of $vehicle is 120 dollar" ;;
    "bus" )
        echo "Rent of $vehicle is 50 dollar" ;;
    * )
        echo "Unknown vehicle" ;;
esac