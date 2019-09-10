cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

set( cin_input_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/cin_input)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${cin_input_OUTPUT_DIR})


## 指定多行 每行输入多个字符串
#add_executable(mulit_lines_string  mulit_lines_string.cpp)


## 指定多行 每行输入多个整数
#add_executable(mulit_lines_int  mulit_lines_int.cpp)

## 不指定行数， 每行输入一组字符串作为测试用例
#add_executable(unfixed_lines_string  unfixed_lines_string.cpp)

## 不指定行数， 每行输入一组整型数作为测试用例