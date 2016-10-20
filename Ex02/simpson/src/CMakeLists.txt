cmake_minimum_required(VERSION 2.8)
 
project(Simpson)

add_executable(main_simpson simpson.cpp main.cpp)

# We create library simpson based on cpp file located in simpson.cpp
add_library(math STATIC simpson.cpp)
target_link_libraries(main_simpson math)

# Install
install(TARGETS main_simpson DESTINATION bin)

