cmake_minimum_required(VERSION 2.8.9)
project (linal)

set(SOURCE_EXE main.cpp)

set(SOURCE_LIB Vector3D.cpp Matrix3D.cpp)

add_library(vector_matrix STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main vector_matrix)