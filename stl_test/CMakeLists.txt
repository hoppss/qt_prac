cmake_minimum_required(VERSION 2.8)
add_compile_options(-std=c++11)
project(vector_test)
add_executable(${PROJECT_NAME} "main.cpp")
add_executable(set set_container.cpp)
add_executable(list list.cpp)

add_executable(priotiy_queue_test priotiy_queue_test.cpp)

add_executable(circlebuffer CircleBuffer.cpp)


