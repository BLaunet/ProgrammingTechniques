cmake_minimum_required( VERSION 2.8 )

project(Benchmark)

set(CMAKE_INSTALL_PREFIX ${CMAKE_HOME_DIRECTORY}/install)
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

# mskoenz: use a sepeate variable (extern_lib) for this
# link/include_dir take "input", CMAKE_INSTALL_PREFIX is for "output" of your project
# and the "input" (external libs) don't need to be there. 
# i.e. Never read from CMAKE_INSTALL_PREFIX
link_directories(${CMAKE_INSTALL_PREFIX}/lib)
include_directories(${CMAKE_INSTALL_PREFIX}/include/)

add_executable(benchmark benchmark.cpp timer.cpp)

# mskoenz: after DESTINATION you only write lib or bin ...
# the CMAKE_INSTALL_PREFIX will be added by cmake
install(TARGETS benchmark DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
