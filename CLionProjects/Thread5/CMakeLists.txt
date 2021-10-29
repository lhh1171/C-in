cmake_minimum_required(VERSION 3.16)
project(Thread5)

set(CMAKE_CXX_STANDARD 14)

add_executable(Thread5 main.cpp)

target_link_libraries(Thread5 boost_thread boost_system rt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")