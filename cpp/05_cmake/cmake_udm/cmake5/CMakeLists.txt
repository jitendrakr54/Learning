cmake_minimum_required(VERSION 3.0.0)

set(Name Charlie)

message("root directory: Before adding subdirectory: ${Name}")
add_subdirectory(subdir)
message("Root directory: After adding subdirectory: ${Name}")