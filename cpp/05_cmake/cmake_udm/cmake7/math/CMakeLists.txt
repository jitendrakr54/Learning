add_library(math
src/addition.cpp
src/division.cpp)

# target_include_directories(<target>
# <scope>
# <dir1>
# <dir2>)

# target_include_directories(math PUBLIC include)

target_include_directories(math PUBLIC 
$<INSTALL_INTERFACE:include>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/addition.h ${CMAKE_CURRENT_SOURCE_DIR}/include/division.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include/math)

install(TARGETS math DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/math)

install(TARGETS math EXPORT my_export DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/math)

install(EXPORT my_export FILE math-config.cmake DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/math)