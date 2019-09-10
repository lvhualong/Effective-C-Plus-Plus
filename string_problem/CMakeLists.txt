cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

set( string_problem_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/string_problem)

## make directory
##file( MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR})
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/bin)
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/lib)
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${string_problem_OUTPUT_DIR})


## 整型数组/字符串 大数相加
#add_executable(bigNumAdd_Array   bigNumAdd/bigNumAdd_Array.cpp)
#add_executable(bigNumAdd_String  bigNumAdd/bigNumAdd_String.cpp)

## * 字符串输入一个表达表达式 * 写一个计算器，计算出表达式的值
#add_executable(01_string_caculateurs_Epression  01_string_caculateurs_Epression.cpp)

## 火星文输入的一个二位数，重新组合，输出一个更小的火星文
#add_executable(02_string_Num_EncodeDecode  02_string_Num_EncodeDecode.cpp)

## 输入一个带有 加减乘除的运算表达式(中序)， 输出逆波兰序的表达式，后序
#add_executable(03_reverse_polish_expression 03_reverse_polish_expression.cpp)

## 输入一个字符串表达式，9个字符为一个编码组，首字母0/1为大端小端编码，输出解码之后的字符串
#add_executable(01_String_BigendOrLittleend_Encode  01_String_BigendOrLittleend_Encode.cpp)

## @HUAWEI 定义一个双双对称字符串， 双回文， 然后输入一个字符串，判断是否双回文字符串
#add_executable(04_symmetricString  04_symmetricString.cpp)

