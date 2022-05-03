cmake_minimum_required(VERSION 2.8)
add_compile_options(-std=c++11)
project(2d_pointer)
# add_executable(${PROJECT_NAME} "main.cpp")

add_executable(2d_pointer 2d_pointer.cpp)
add_executable(typedef_ptr typedef_ptr.cpp)
add_executable(array_ptr array_ptr.cpp)