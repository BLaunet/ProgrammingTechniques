cmake_minimum_required(VERSION 2.8)
 
project(Z2)

add_executable(main_Z2 Pb1.cpp)


# Install
install(TARGETS main_Z2 DESTINATION bin)