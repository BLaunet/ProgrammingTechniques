cmake_minimum_required(VERSION 2.8)
 
project(Simpson)

 # Just compile the square program from both source files
add_executable(simpson simpson_main.cpp simpson_method.cpp)

#install the programs into the bin subdirectory
install(TARGETS simpson DESTINATION bin)