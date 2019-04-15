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

## Library
add_library(myVector SHARED dataStructure/myVector.cpp) ## Vector library
add_library(myList SHARED dataStructure/myList.cpp) ## List library
add_library(myQueue SHARED dataStructure/myQueue.cpp)

#add_library(myStack SHARED dataStructure/myStack.cpp
#        dataStructure/myVector.cpp
#        dataStructure/myList.cpp)


## LeetCode子文件夹
set( LeetCode_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/LeetCode)
file( MAKE_DIRECTORY  ${LeetCode_OUTPUT_DIR} )
add_subdirectory(LeetCode)

## Programming子文件夹
set( Programming_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/programming)
file( MAKE_DIRECTORY  ${Programming_OUTPUT_DIR} )
add_subdirectory(programming)

## CodingInterview 剑指offer文件夹
set( CodingInterview_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/codingInterview)
file( MAKE_DIRECTORY  ${CodingInterview_OUTPUT_DIR} )
add_subdirectory(CodingInterview)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_OUTPUT_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR}/lib)
set(CMAKE_LIBRARY_ARCHITECTURE  ${PROJECT_OUTPUT_DIR}/lib)

add_executable(vector_exe  dataStructure/myVector.cpp) ## vextor_exe
add_executable(list_exe dataStructure/myList.cpp)

## EXE
add_executable(01_test today/01_test.cpp)
add_executable(02_test today/02_test.cpp)
add_executable(03_test today/03_test.cpp)


