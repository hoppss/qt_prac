cmake_minimum_required(VERSION 2.8)
project(set_define LANGUAGES CXX)
#add_compile_options(-std=c++11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(set_define main.cpp)
add_executable(pqt priotiy_queue_test.cpp)
add_executable(copy copy_backward.cpp)
add_executable(svd svd.cpp)
add_executable(trace trace.cpp)

