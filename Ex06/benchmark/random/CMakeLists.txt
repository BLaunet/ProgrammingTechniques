cmake_minimum_required( VERSION 2.8 )

project(random)

set(CMAKE_INSTALL_PREFIX ${CMAKE_HOME_DIRECTORY}/../install)

add_library(random STATIC random.cpp)

install(TARGETS random
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
	)

install(FILES random.hpp DESTINATION include)