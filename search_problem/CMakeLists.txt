cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

set( search_problem_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/search_problem)

## make directory
##file( MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR})
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/bin)
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/lib)
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${search_problem_OUTPUT_DIR})

## Dijkstra_shortestDistance
add_executable(Dijkstra_shortestDistance  Dijkstra_shortestDistance.cpp)



## 判断一个序列是否为非递增序列
#add_executable(nonIncreasing_sequence  nonIncreasing_sequence.cpp)

## 查找一个序列中出现一次的元素，其他元素可能出现两次次，可能出现三次
#add_executable(findNum_appearOnce  findNum_appearOnce.cpp)

## 考场中有n个男生，n个女生， 男生女生可能相互认识，为了保证考试公平，把认识的同学放到另一个教室，找出最少的学生
#add_executable(map_remove_sturents   map_remove_sturents.cpp)

## @华为 一个5*5的int矩阵， 现在输入一个序列，判断这个序列是否在矩阵中“相邻” 类似于通行域或者贪吃蛇
add_executable(matrix_find_neighbour_list   matrix_find_neighbour_list.cpp)
