cmake_minimum_required(VERSION 3.16)
project(Thread1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Thread1 main.cpp)

find_package(Threads REQUIRED)

#添加头文件搜索路径
include_directories(/usr/include)
#添加库文件搜索路径
link_directories(/usr/local/lib)
set(BOOST_ROOT "/usr/boost")
target_link_libraries(Thread1 boost_thread boost_system rt)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")