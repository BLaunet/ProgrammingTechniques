cmake_minimum_required( VERSION 2.8 )

project(Benchmark)

add_library(Timer STATIC Timer.cpp)
add_library(Generator STATIC Generator.cpp)

add_executable(benchmark main.cpp)

target_link_libraries(benchmark Timer Generator)

install(TARGETS benchmark DESTINATION bin)

install(TARGETS Timer Generator
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

install(FILES Timer.hpp Generator.hpp DESTINATION include)