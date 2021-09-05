cmake_minimum_required(VERSION 3.0.0)

############################################# Flow Control Commands ###############################
# Example 1:
# set(VAR YES)
# # set(VAR "")

# if(VAR)
#     message("If block executed")
# else()
#     message("Else block executed")
# endif()


# Example 2:
# set(VAR OFF)
# set(VAR2 VAR)

# # if(VAR2)
# if(${VAR2})
#     message("If block executed")
# else()
#     message("Else block executed")
# endif()

# Example 3:
# set(Name Alice)

# if(DEFINED Name)
#     message("Name: if block executed")
# else()
#     message("Name: else block executed")
# endif()

# Example 4:
# if(DEFINED Age)
#     message("Age: if block executed")
# else()
#     message("Age: else block executed")
# endif()

######################################## if() and Unary Tests ####################################

# Example 1:
# if(COMMAND target_link_library)
#     message("target_link_library is a command")
# else()
#     message("target_link_library is NOT a command")
# endif()

# Example 2:
# if(COMMAND target_link_libraries)
#     message("target_link_libraries is a command")
# else()
#     message("target_link_libraries is NOT a command")
# endif()

# Example 3:
# if(EXISTS /home/jitendra/Learning/cpp/05_cmake/cmake_udm/cmake4)
#     message("Given file exists")
# else()
#     message("File not found")
# endif()


######################## Binary commands ###############################

# Example 1:
# set(Name1 Charlie)
# set(Name2 bob)

# if(Name1 STRLESS Name2)
#     message("${Name1} is less than ${Name2}")
# elseif(Name1 STRGREATER Name2)
#     message("${Name1} is greater than ${Name2}")
# elseif(Name1 STRWQUAL Name2)
#     message("${Name2} is equal to ${Name2}")
# endif()

##################################### Looping commands ###################################

# Example 1:
# while(NOT VAR STREQUAL "aaaaaaaaaa")
#     set(VAR ${VAR}a)
#     message(${VAR})
# endwhile()

# Example 2:
# foreach(Name Alice Bob Charlie)
# foreach(Name Alice;Bob;Charlie)  # Can be done in either way
#     message(${Name})
# endforeach()

# Example 3:
# foreach(x RANGE 100 105)
#     message("Person_${x}")
# endforeach()

# Example 4:
# set(VAR1 0;1)
# set(VAR2 2 3)
# # set(VAR3 "4 5")
# set(VAR3 "4;5")

# Example 5:
# foreach(x IN LISTS VAR1 VAR2 VAR3)
#     message("x = ${x}")
# endforeach()

######################################## Functions ################################

# Example 1:
# function(print_detail)
#     message("My name is ${name_var}")
# endfunction()

# print_detail()

# Example 2:
# function(print_detail name_var)
#     message("My name is ${name_var}")
# endfunction()

# print_detail(charlie)

# Example 3:
# function(print_detail name_var)
#     # message("My name is ${name_var}")
#     message("My name is ${${name_var}}")
# endfunction()

# set(Name Charlie)

# # print_detail(${Name})
# print_detail(Name)

# Example 4:
# set(Name Charlie)
# set(Age 45)
# function(print_detail var)
#     message("My ${var} is ${${var}}")
# endfunction()
# print_detail(Name)
# print_detail(Age)

# Example 5:
# set(Name Charlie)
# set(Age 45)

# function(print_detail var)
#     message("1. My ${var} is ${${var}}")
# endfunction()

# function(print_detail var)
#     message("2. My ${var} is ${${var}}")
# endfunction()

# function(print_detail var)
#     message("3. My ${var} is ${${var}}")
# endfunction()

# print_detail(Name)
# _print_detail(Name)
# __print_detail(Name) #Error: 1st fun can't be called by putting double underscore in case of 3 functions

# Example 6:
# function(print_detail name_var)
#     message("My name is ${${name_var}}")

#     if(DEFINED ARGV1)
#         message("Hello, my name is ${ARGV1}")
#     endif()

# endfunction()

# set(Name Charlie)

# print_detail()  # Error: parameterised fun can't be called without argument
# print_detail(Name Bob) #Output will be same if more argument is passed, to print optional argument,
                        # it should be handled using ARGV1

# Example 7:
# function(print_detail name_var)
#     message("My name is ${${name_var}}")

#     if(DEFINED ARGV1)
#         message("Hello, my name is ${ARGV1}")
#     endif()

#     message("ARGC= ${ARGC}")
#     message("ARGV= ${ARGV}")
#     message("ARGN= ${ARGN}")

#     if(DEFINED ARGV0)
#         message("ARGV0= ${ARGV0}")
#     endif()

#     if(DEFINED ARGV1)
#         message("ARGV1= ${ARGV1}")
#     endif()

#     if(DEFINED ARGV2)
#         message("ARGV2= ${ARGV2}")
#     endif()

#     if(DEFINED ARGV3)
#         message("ARGV3= ${ARGV3}")
#     endif()

# endfunction()

# set(Name Charlie)

# print_detail(Name Bob Alice)


######################################### Scopes #################################
# Example 1:
set(Name Charlie)

function(print_detail)
    message("Inside Function: Before modifictaion: ${Name}")
    # set(Name Bob)
    set(Name Bob PARENT_SCOPE)
    message("Inside Function: After modification: ${Name}")
endfunction()

message("Outside function: Before function call: ${Name}")
print_detail()
message("Outside function: After function call: ${Name}")

