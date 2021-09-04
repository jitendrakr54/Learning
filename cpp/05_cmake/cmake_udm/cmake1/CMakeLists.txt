# cmake_minimum_required(VERSION 3.0.0)

# project(Calculator_Project VERSION 1.0.0)

# add_executable(calculator
# main.cpp
# addition.cpp
# division.cpp
# print_result.cpp)


# Generating first Library

# cmake_minimum_required(VERSION 3.0.0)

# project(Calculator_Project VERSION 1.0.0)

# add_library(arithmetic
# addition.cpp
# division.cpp)

# add_library(print
# print_result.cpp)

# add_executable(calculator
# main.cpp)

# target_link_libraries(calculator arithmetic print)


# FAQS
# 1. Can we have more than 1 execuatble in CMakeLists.txt?
#  Yes

cmake_minimum_required(VERSION 3.0.0)

project(Calculator_Project VERSION 1.0.0)

add_library(arithmetic
addition.cpp
division.cpp)

add_library(print
print_result.cpp)

add_executable(calculator
main.cpp)

add_executable(dup_calculator
main.cpp)

target_link_libraries(calculator arithmetic print)

target_link_libraries(dup_calculator arithmetic print)

# 2. Can we have 2 targets of the same name?
#    No, If we do so, the CMake will give an error and this error is to prevent any confusion 
#    in the subsequent stage.
#    This is the reason why above example used a different name while making another executable.

# 3. Do we have the target files saved in our computer?
#    Yes