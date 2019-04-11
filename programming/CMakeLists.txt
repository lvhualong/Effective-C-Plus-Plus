
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

set( Programming_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/programming)

## make directory
##file( MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR})
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/bin)
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/lib)
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${Programming_OUTPUT_DIR})

## 01 vector 数组的相关操作
add_executable(removeDuplicates 01_array/removeDuplicates.cpp) ##

## 02 string
add_executable(mySring 02_string/myString.cpp)


## 03_tree

## 04_sorted

## 05_searchFind

## 06_dynamicProgramming_greedyAlgorithm

## 07_backTrackingAlgorithm
#add_executable(12_stringPathInCharMatrix  07_backTrackingAlgorithm/12_stringPathInCharMatrix.cpp)
#add_executable(13_robotMoveCountInPlane 07_backTrackingAlgorithm/13_robotMoveCountInPlane.cpp)
#add_executable(14_maxProductAfterCutting_solution_dynamic 06_dynamicProgramming_greedyAlgorithm/14_maxProductAfterCutting_solution_dynamic.cpp)
#add_executable(14_maxProductAfterCutting_greedyAlgorithm 06_dynamicProgramming_greedyAlgorithm/14_maxProductAfterCutting_greedyAlgorithm.cpp)

## 08_math 数学运算的实现
#add_executable(sqrt_exe 08_math/sqrt.cpp) ## 根号的实现
#add_executable(myMath 08_math/myMath.cpp)
add_executable(15_binOperation 08_math/15_binOperation.cpp)
#add_executable(16_power 08_math/16_power.cpp)
add_executable(17_printaTotheMaxNum 02_string/17_printaTotheMaxNum.cpp)
add_executable(numOfHuiwen 02_string/numOfHuiwen.cpp)


## 腾讯2019
#add_executable(01_splitNum Tencent2019/01_splitNum.cpp)
#add_executable(02_allocationForMinCost Tencent2019/02_allocationForMinCost.cpp)
#add_executable(03operateToNums Tencent2019/03operateToNums.cpp)

## 华为2019
add_executable(01_String_BigendOrLittleend_Encode Huawei2019/01_String_BigendOrLittleend_Encode.cpp)