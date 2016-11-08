cmake_minimum_required( VERSION 2.8 )

project(Penna)

set(CMAKE_INSTALL_PREFIX ${CMAKE_HOME_DIRECTORY}/install)
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

link_directories(${CMAKE_INSTALL_PREFIX}/lib)
include_directories(${CMAKE_INSTALL_PREFIX}/include/)

add_executable(simulation simulation.cpp)
add_library(Penna STATIC population.cpp genome.cpp animal.cpp)
target_link_libraries(simulation Penna)

install(TARGETS simulation DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

install(TARGETS Penna
	ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
	LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
	)

install(FILES animal.hpp population.hpp genome.hpp DESTINATION ${CMAKE_INSTALL_PREFIX}/include)