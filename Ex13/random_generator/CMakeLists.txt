cmake_minimum_required(VERSION 2.8)

project(RandomGenerator)

set(CMAKE_CXX_FLAGS "-Wall")

include_directories(/usr/local/Cellar/boost/1.62.0/include/)
add_executable(rg main.cpp)

install(FILES RandomGenerator.hpp DESTINATION include)
install(TARGETS rg DESTINATION bin)
