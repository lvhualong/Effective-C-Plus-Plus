cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

set( Sorted_problem_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/sorted_problem)

## make directory
##file( MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR})
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/bin)
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/lib)
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${Sorted_problem_OUTPUT_DIR})


### 基本排序算法，使用stl库，手写各种排序算法

#add_executable(01_std_sort_used based_sort/01_stl_sorted_used.cpp)
#add_executable(02_base_sorted based_sort/02_base_sorted.cpp)

## 字符串单词 排序
#add_executable(01_string_sort  01_string_sort.cpp)

## 每一个商品有不同属性，组合成pair, 根据其中一个属性进行排序
#add_executable(02_unit_maxSatify  02_unit_maxSatify.cpp)