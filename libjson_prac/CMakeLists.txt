cmake_minimum_required(VERSION 2.8)
add_compile_options(--std=c++11)
project(libjson_prac)

include_directories("/usr/include/jsoncpp/")

add_executable(${PROJECT_NAME} "libjson_pracs.cpp")
target_link_libraries(${PROJECT_NAME} libjsoncpp.so )
