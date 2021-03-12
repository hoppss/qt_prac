cmake_minimum_required(VERSION 3.13)
project(thread)
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++11 -pthread")
add_executable(1thread_function 1thread_function.cpp)

add_executable(2thread_functor 2thread_functor.cpp)

add_executable(3thread_functor_ref_arg 3thread_functor_ref_arg.cpp)

add_executable(4thread_lambda 4thread_lambda.cpp)

add_executable(5thread_lambda2 5thread_lambda2.cpp)

add_executable(6thread_detach_args 6thread_detach_args.cpp)


add_executable(7thread_detach_args2 7thread_detach_args2.cpp)

add_executable(8thread_args_ref 8thread_args_ref.cpp)

add_executable(9thread_args_ref 9thread_args_ref2.cpp)

add_executable(10thread_args_member_fun 10thread_args_member_fun.cpp)
