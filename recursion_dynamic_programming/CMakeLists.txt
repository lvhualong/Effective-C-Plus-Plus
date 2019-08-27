cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

set( recursion_dynamic_programming_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/recursion_dynamic_programming)

## make directory
##file( MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR})
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/bin)
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/lib)
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${recursion_dynamic_programming_OUTPUT_DIR})


## 递归解决方案
### 输入一个n 按照规则构建一个序列 sequenceCollatz
#add_executable(sequenceCollatz sequenceCollatz.cpp)

### 输入一个n,构建一个fibonacci数列 台阶跳
#add_executable(sequenceJumpFloor_Fibonacci sequenceJumpFloor_Fibonacci.cpp)

### 生兔子， 成熟的兔子一年生一个兔子，3年兔子才能成熟
#add_executable(sequence_rabbit  sequence_rabbit.cpp)

## 贪心/动态规划解决方案
## 求数组的最大子序列和
add_executable(01_theLastSubArraySum 01_theLastSubArraySum.cpp)

### 找零钱问题
#add_executable(dp_charge_problem dp_charge_problem.cpp)