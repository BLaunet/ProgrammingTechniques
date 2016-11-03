cmake_minimum_required( VERSION 2.8 )

project(timer)

set(CMAKE_INSTALL_PREFIX ${CMAKE_HOME_DIRECTORY}/../install)

add_library(timer STATIC timer.cpp)

install(TARGETS timer
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
	RUNTIME DESTINATION bin
	)

install(FILES timer.hpp DESTINATION include)