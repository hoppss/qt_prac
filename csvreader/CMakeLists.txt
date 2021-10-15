project(csvreader)
cmake_minimum_required(VERSION 2.8)

add_compile_options(-std=c++11)

include_directories(.)

add_library(${PROJECT_NAME}  SHARED   csvreader.cpp)
add_executable(main   main.cpp  csvreader.cpp)
add_executable(write  CSVWriter.cpp)
add_executable(read  CSVReader.cpp)
