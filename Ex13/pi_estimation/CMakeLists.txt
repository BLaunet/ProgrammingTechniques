cmake_minimum_required(VERSION 2.8)

project(PiEstimation)

set(CMAKE_CXX_FLAGS "-Wall")

add_executable(pi main.cpp)

install(TARGETS pi DESTINATION bin)
