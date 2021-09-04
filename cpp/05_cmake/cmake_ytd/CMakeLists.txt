cmake_minimum_required(VERSION 3.13.4)

project(HELLOWORLD)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(arithmetics)

target_include_directories(${PROJECT_NAME} PUBLIC arithmetics)

target_link_directories(${PROJECT_NAME} PRIVATE arithmetics)

target_link_libraries(${PROJECT_NAME} arithmetics)