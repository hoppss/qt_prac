cmake_minimum_required(VERSION 2.8)
project(pcl_0)

add_compile_options(-std=c++11)

find_package(PCL 1.7 REQUIRED)
message("PCL include " ${PCL_INCLUDE_DIRS})
message("PCL library " ${PCL_LIBRARY_DIRS})
message("PCL definitions " ${PCL_DEFINITIONS})

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcd_write_test pcd_write.cpp)
target_link_libraries(pcd_write_test ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES} )

add_executable(pcd_read_test pcd_read.cpp)
target_link_libraries(pcd_read_test ${PCL_LIBRARIES} )

add_executable(pcd_concatenate concatenatepointcloud.cpp)
target_link_libraries(pcd_concatenate ${PCL_LIBRARIES} )
