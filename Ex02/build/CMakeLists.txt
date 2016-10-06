cmake_minimum_required(VERSION 2.8)
 
project(Simpson)

#Including headers
include_directories(../include)

#Making library
add_library(simpson SHARED ../src/simpson.cpp)

# Just compile the square program from both source files
add_executable(main ../src/main.cpp)

target_link_libraries(main simpson)

#install the programs into the bin subdirectory
install(TARGETS main DESTINATION bin)

install(TARGETS main
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	RUNTIME DESTINATION bin       )
install(FILES ../simpson.hpp DESTINATION include)

