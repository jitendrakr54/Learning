add_library(math
src/addition.cpp
src/division.cpp)

# target_include_directories(<target>
# <scope>
# <dir1>
# <dir2>)

target_include_directories(math PUBLIC include)