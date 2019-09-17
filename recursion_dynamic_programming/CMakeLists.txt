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

## ----------------------------------------------------------------------------------------------------------------------

## 贪心/动态规划解决方案
## 求数组的最大子序列和
#add_executable(dp_theLastSubArraySum dp_theLastSubArraySum.cpp)

### 找零钱问题
#add_executable(dp_charge_problem dp_charge_problem.cpp)

## 二维网格，走数值最大的一条路径(摘苹果)
#add_executable(dp_theMaxVaulePath_occupiedGrid dp_theMaxVaulePath_occupiedGrid.cpp)

## 给定两个字符串，定义两个字符串长度的距离，
#add_executable(dp_edit_string_distance  dp_edit_string_distance.cpp)

## 背包装东西问题，每种物品有价值和重量，但是每种物品不限量
#add_executable(dp_theLastSubStringMatch dp_theLastSubStringMatch.cpp)
#add_executable(dp_theLastValue_Satify dp_theLastValue_Satify.cpp)
#add_executable(dp_theLasFood_Satify dp_theLasFood_Satify.cpp)
#add_executable(dp_theMaxCommonSubStringMatch  dp_theMaxCommonSubStringMatch.cpp)

## 二维数组平面上切水果  每一刀只能横切、竖切、左斜切、又斜切，怎么切刀数最少
#add_executable(03_fruit_SliceInPlane  03_fruit_SliceInPlane.cpp)

## 回溯算法
add_executable( backtrack_backPackage   backtrack_backPackage.cpp)

## 给定一个序列，求其中最长的等差序列的长度为多少
#add_executable(dp_theLongestSubSeq_length dp_theLongestSubSeq_length.cpp)

## 给定一个序列，将其分为两个子序列，使得两个子数组和的的差值最小
#add_executable(dp_the_shortest_diff_two_sub  dp_the_shortest_diff_two_sub.cpp)