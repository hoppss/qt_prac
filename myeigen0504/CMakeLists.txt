cmake_minimum_required(VERSION 2.8)
add_compile_options(-std=c++11)

find_package(Eigen3)

project(myeigen0504)
add_executable(${PROJECT_NAME} "main.cpp")
