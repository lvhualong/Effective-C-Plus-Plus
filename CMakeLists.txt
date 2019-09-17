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
#add_library(myVector SHARED dataStructure/myVector.cpp) ## Vector library
#add_library(myList SHARED dataStructure/myList.cpp) ## List library
#add_library(myQueue SHARED dataStructure/myQueue.cpp)

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


## sorted_problem dir
set( Sorted_problem_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/sorted_problem)
file( MAKE_DIRECTORY  ${Sorted_problem_OUTPUT_DIR} )
add_subdirectory(sorted_problems)

## search_problem dir
set( search_problem_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/search_problem)
file( MAKE_DIRECTORY  ${search_problem_OUTPUT_DIR} )
add_subdirectory(search_problem)


## string_problem dir
set( string_problem_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/string_problem)
file( MAKE_DIRECTORY  ${string_problem_OUTPUT_DIR} )
add_subdirectory(string_problem)

## recursion_dynamic_programming dir
set( recursion_dynamic_programming_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/recursion_dynamic_programming)
file( MAKE_DIRECTORY  ${recursion_dynamic_programming_OUTPUT_DIR} )
add_subdirectory(recursion_dynamic_programming)


## listNode_problem
set( listNode_problem_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/listNode_problem)
file( MAKE_DIRECTORY  ${listNode_problem_OUTPUT_DIR} )
add_subdirectory(listNode_problem)

## 一些新的定义问题
set( new_define_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/new_define)
file( MAKE_DIRECTORY  ${new_define_OUTPUT_DIR} )
add_subdirectory(new_define)

## cin_input
set( cin_input_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/cin_input)
file( MAKE_DIRECTORY  ${cin_input_OUTPUT_DIR} )
add_subdirectory(cin_input)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_OUTPUT_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR}/lib)
set(CMAKE_LIBRARY_ARCHITECTURE  ${PROJECT_OUTPUT_DIR}/lib)

#add_executable(vector_exe  dataStructure/myVector.cpp) ## vextor_exe
#add_executable(list_exe dataStructure/myList.cpp)

## EXE
add_executable(01_test today/01_test.cpp)
add_executable(02_test today/02_test.cpp)
add_executable(03_test today/03_test.cpp)
add_executable(04_test recursion_dynamic_programming/dp_the_shortest_diff_two_sub.cpp)
add_executable(0_theLongestSubSeq recursion_dynamic_programming/dp_theLongestSubSeq_length.cpp)




