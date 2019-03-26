cmake_minimum_required(VERSION 2.8)
project(dataStructure)

set(CMAKE_CXX_STANDARD 11)

set( PROJECT_OUTPUT_DIR ${PROJECT_BINARY_DIR}/${CMAKE_SYSTEM_PROCESSOR})

## make directory
#file( MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR})
file( MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR}/bin)
file( MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR}/lib)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_OUTPUT_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR}/lib)
set(CMAKE_LIBRARY_ARCHITECTURE  ${PROJECT_OUTPUT_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/dataStructure)

add_library(myVector SHARED dataStructure/myVector.cpp)

add_executable(vector_exe  dataStructure/myVector.cpp)


