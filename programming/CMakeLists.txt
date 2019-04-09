
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

set( Programming_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/programming)

## make directory
##file( MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR})
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/bin)
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/lib)
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${Programming_OUTPUT_DIR})

## 数组的相关操作s
add_executable(removeDuplicates   array/removeDuplicates.cpp) ##

## string
add_executable(mySring 000_basic_Operate/myString.cpp)
add_executable(myMath 000_basic_Operate/myMath.cpp)

## 数学运算的实现
add_executable(sqrt_exe math/sqrt.cpp) ## 根号的实现


## 腾讯2019
#add_executable(01_splitNum Tencent2019/01_splitNum.cpp)
#add_executable(02_allocationForMinCost Tencent2019/02_allocationForMinCost.cpp)
#add_executable(03operateToNums Tencent2019/03operateToNums.cpp)

## 华为2019
add_executable(01_String_BigendOrLittleend_Encode Huawei2019/01_String_BigendOrLittleend_Encode.cpp)