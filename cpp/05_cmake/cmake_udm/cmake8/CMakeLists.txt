cmake_minimum_required(VERSION 3.0.0)

project(MATH_TEST VERSION 1.0.0)

find_package(math)

if(math_FOUND)
    message("math library found!")
    add_executable(calc main.cpp)
    target_link_libraries(calc math)
else()
    message(FATAL_ERROR "math library not found")
endif()