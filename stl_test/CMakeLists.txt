cmake_minimum_required(VERSION 2.8)
add_compile_options(-std=c++14)
project(vector_test)
add_executable(${PROJECT_NAME} "main.cpp")
add_executable(set set_container.cpp)
add_executable(list list.cpp)

add_executable(priotiy_queue_test priotiy_queue_test.cpp)

add_executable(circlebuffer CircleBuffer.cpp)


add_executable(simple_math simple_math.cpp)


add_executable(string_cmp string_cmp.cpp)

add_executable(char_cast char.cpp)

add_executable(bit bit.cpp)

add_executable(copysign copysign.cpp)

add_executable(cb circle_buffer.cpp)
add_executable(cb_2 circle_buffer_2.cpp)

add_executable(ve  vector_erase.cpp)

add_executable(bound_area_line  bound_area_line.cpp)
add_executable(bound_area_segment  bound_area_linesegment.cpp)
