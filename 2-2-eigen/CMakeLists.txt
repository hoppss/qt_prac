cmake_minimum_required(VERSION 2.8)

project(2-2-eigen)
find_package(Eigen3)
add_executable(${PROJECT_NAME} "main.cpp")
