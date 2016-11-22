cmake_minimum_required( VERSION 2.8 )

project(Benchmark)

set(INSTALL_DIR ${CMAKE_HOME_DIRECTORY}/install)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

add_executable(benchmark main.cpp)
add_library(timer STATIC timer.cpp)

target_link_libraries(benchmark timer)

install(TARGETS benchmark DESTINATION ${INSTALL_DIR}/bin)

install(TARGETS timer	ARCHIVE DESTINATION ${INSTALL_DIR}/lib        LIBRARY DESTINATION ${INSTALL_DIR}/lib        RUNTIME DESTINATION ${INSTALL_DIR}/bin       )

install(FILES timer.hpp simpson.hpp function.hpp benchmark.hpp DESTINATION ${INSTALL_DIR}/include)