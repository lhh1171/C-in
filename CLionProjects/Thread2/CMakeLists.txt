cmake_minimum_required(VERSION 3.16)
project(Thread2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Thread2 main.cpp)

target_link_libraries(Thread2 boost_thread boost_system rt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")