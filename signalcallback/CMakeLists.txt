cmake_minimum_required(VERSION 2.8)
add_compile_options(-std=c++11)
project(signal)
add_executable(${PROJECT_NAME} main.cpp CSignal.hpp)
