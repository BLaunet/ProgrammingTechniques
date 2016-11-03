cmake_minimum_required( VERSION 2.8 )

project(Benchmark)

set(CMAKE_INSTALL_PREFIX ${CMAKE_HOME_DIRECTORY}/../install)

link_directories(${CMAKE_INSTALL_PREFIX}/lib)
include_directories(${CMAKE_INSTALL_PREFIX}/include/)

add_executable(benchmark main.cpp)
target_link_libraries(benchmark timer random)

install(TARGETS benchmark DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)


