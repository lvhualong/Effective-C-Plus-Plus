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


## LeeCode子文件夹
set( LeeCode_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/LeeCode)
file( MAKE_DIRECTORY  ${LeeCode_OUTPUT_DIR} )
add_subdirectory(LeeCode)




set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_OUTPUT_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR}/lib)
set(CMAKE_LIBRARY_ARCHITECTURE  ${PROJECT_OUTPUT_DIR}/lib)
## EXE
add_executable(test  test.cpp)
add_executable(vector_exe  dataStructure/myVector.cpp) ## vextor_exe
add_executable(list_exe dataStructure/myList.cpp)




