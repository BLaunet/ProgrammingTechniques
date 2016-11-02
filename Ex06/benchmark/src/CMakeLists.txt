cmake_minimum_required( VERSION 2.8 )

project(Benchmark)

add_library(random SHARED random.cpp)
add_library(timer SHARED timer.cpp)
add_executable(benchmark main.cpp)

target_link_libraries(benchmark timer random)

install(TARGETS random timer
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
	RUNTIME DESTINATION bin
	)

install(TARGETS benchmark DESTINATION bin)

install(FILES random.hpp timer.hpp DESTINATION include)


