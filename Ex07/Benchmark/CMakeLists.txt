cmake_minimum_required( VERSION 2.8 )

project(Benchmark)

set(CMAKE_INSTALL_PREFIX ${CMAKE_HOME_DIRECTORY}/install)
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

link_directories(${CMAKE_INSTALL_PREFIX}/lib)
include_directories(${CMAKE_INSTALL_PREFIX}/include/)

add_executable(benchmark benchmark.cpp timer.cpp)

install(TARGETS benchmark DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)