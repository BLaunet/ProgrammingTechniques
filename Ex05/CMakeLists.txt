cmake_minimum_required( VERSION 2.8 )

project(Benchmark)

set(CMAKE_INSTALL_PREFIX ${CMAKE_HOME_DIRECTORY}/install)
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

link_directories(${CMAKE_INSTALL_PREFIX}/lib)
include_directories(${CMAKE_INSTALL_PREFIX}/include/)

add_executable(bittest bittest.cpp)

add_executable(genome-test genome-test.cpp)
add_executable(animal-test animal-test.cpp)


add_library(Penna STATIC genome.cpp animal.cpp)

target_link_libraries(genome-test Penna)
target_link_libraries(animal-test Penna)

install(TARGETS animal-test genome-test cdDESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

install(TARGETS Penna
	ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
	LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
	)
install(FILES animal.hpp genome.hpp DESTINATION ${CMAKE_INSTALL_PREFIX}/include)