
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

set( Programming_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/programming)

## make directory
##file( MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR})
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/bin)
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${Programming_OUTPUT_DIR})





## 01 vector 数组的相关操作  11111111111111111111111111111111111111111111111111111111111111111111111111111
## 单链表 的基本操作
#add_executable(00_mySingleNodeList  01_array/00_mySingleNodeList.cpp)
## 双向链表的基本操作
#add_executable(00_myDoubleNodeList  01_array/00_myDoubleNodeList.cpp)
## 自定义一个栈
add_executable(00_myStack  01_array/00_myStack.cpp)

## 【一叠牌 重新排序问题】 每次输入第一个，第二个移到最后
#add_executable(01_arrayShiftProblem 01_array/01_arrayShiftProblem.cpp)
#add_executable(01_arrayShiftProblem_reverse 01_array/01_arrayShiftProblem_reverse.cpp)
## 已排序数组删除重复元素
#add_executable(02_removeDuplicates 01_array/02_removeDuplicates.cpp)
## 求一组二维点的boundingBox坐标 左上 右下 【二维点的排序】
#add_executable(03_boundingBox 01_array/03_boundingBox.cpp)
## 平面上五个二维点到原点的最短路径
#add_executable(04_shortestPahtInPlane 01_array/04_shortestPahtInPlane.cpp)
### 05_fruit_SliceInPlane_dynamic.cpp  【二维平面切水果问题】 【根据横切 竖切 斜切的特点 动态规划】
### 06_theLastSubArraySum.cpp  最大子数组和问题 【贪心算法 和 动态规划解法】
### 07_theLastVesselProblem.cpp  给定一系列第一象限坐标，get最大容器问题，【对输入字符串切分，转整型， 贪心算法】

## 02 string  2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222

### 00  string字符串的基本操作
### 01  华为笔试，大端小端编码， 对一个编码后的串进行解码输出【string 反向迭代输出】
### 02 一个字符串和多个子串， 输出子串的最大数目
### 03 输入一个整数表示位数，打印所有整数 3 -> 1~999，【字符串数组的累加定义】
### 04 输入一个数表示范围，输出这个范围内，所有二进制是回文的数量 【二进制回文】
#add_executable(numOfHuiwen 02_string/04_numOfHuiwen.cpp)
### 05 正则表达式的匹配 【* 超前考虑】
#add_executable(05_regularExpressionMatching 02_string/05_regularExpressionMatching.cpp)
### 06 【 输出最后一个子串单词的长度】
### 07 【双对称字符的判断  字符串逆序 与迭代器的使用】
### 08 【多行字符串的数组，转成整型vector的处理】 theLastVesselProblem.cpp
### 09 【检查括号匹配问题  [] () {}  栈的基本使用】
### 10 【字符串运算表达式的解析与求解  带加减乘除括号运算符】
#add_executable(09_bracket_check 02_string/09_bracket_check.cpp)
add_executable(10_stringEvaluationReversePolishNotation 02_string/10_stringEvaluationReversePolishNotation.cpp)

## 03_treeAndGraph  333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333

### 01 Dijkstra 单源最短路径问题
add_executable(01_Dijkstra-singleSourceShortestPath 03_treeAndGraph/01_Dijkstra-singleSourceShortestPath.cpp)


## 04_sorted  44444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444

### 01 arrayShiftProblem【手上的一打牌排序的问题；每次把第一张输出，第二张插到结尾】
### 01 arrayShiftProblem_reverse【逆问题，现在桌子上有一打牌，给出原来手里牌的顺序】



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
#add_executable(15_binOperation 08_math/15_binOperation.cpp)
#add_executable(16_power 08_math/16_power.cpp)
#add_executable(17_printaTotheMaxNum 02_string/03_printaTotheMaxNum.cpp)


## ##########################################################
##  名企编程题
## ###########################################################
## 腾讯2019
### 01 一个数字的拆分消去游戏 [每次拆分成两数之和或者减1]
### 02 n个村庄的水果供给分配问题  [有正有负，要求搬运次数最少]
### 03 对一个有n个数字的数组，对数组进行k次操作[非零元 - 最小的非零元)]
#add_executable(01_splitNum Tencent2019/01_splitNum.cpp)
#add_executable(02_allocationForMinCost Tencent2019/02_allocationForMinCost.cpp)
#add_executable(03operateToNums Tencent2019/03operateToNums.cpp)

## AiBEE 2019代码考察
## 1. 二维矩阵乘法运算
## 2. 求二维数组的BouningBox
#add_executable(01_twoDimMatrixMulit  AiBEE2019/01_twoDimMatrixMulit.cpp)
#add_executable(02_boundingBox AiBEE2019/02_boundingBox.cpp)

## DJI 2019
### 用钱购买零食，获得最大满足感的问题
### 机器人最短路劲问题
add_executable(02_theMaxSatisfication DJI2019/02_theMaxSatisfication.cpp)
add_executable(03_dijistra_distance DJI2019/03_dijistra_distance.cpp)
## 华为2019
#### 01 字符串的小端/大端编码
#### 02 二维平面上5点到原点的最短路径
#### 03 二维平面上直线切水果
#### 04 双对称字符的判断
#### 05 【公交车换乘问题  转化成单源最短路径模型】

####
#add_executable(01_String_BigendOrLittleend_Encode Huawei2019/01_String_BigendOrLittleend_Encode.cpp Zijie2019/test.cpp)
#add_executable(02_shortestPahtInPlane Huawei2019/02_shortestPahtInPlane.cpp)
#add_executable(03_fruit_SliceInPlane  Huawei2019/03_fruit_SliceInPlane.cpp)
add_executable(05_Dijkstra Huawei2019/05_Dijkstra-singleSourceShortestPath.cpp)
add_executable(05_Dijkstra_1 Huawei2019/05_Dijkstra_shortestDistance.cpp)

## 微众银行(腾讯)
### 1. 二进制的加减与移位操作
### 2. 指定一个范围，输出之间的素数以及素数的方幂
#add_executable(bin_operate  Weizong2019/bin_operate.cpp)
#add_executable(primeNumberFiniteField  Weizong2019/primeNumberFiniteField.cpp)

## 腾讯 2019
### 1. 一个数拆分消去， 每次拆分成两个，或者所有数-1
### 2, n个村庄供给分配最小成本问题
### 3. 一个数组减去最小的非零元素，循环输出
#add_executable(01_splitNum Tencent2019/01_splitNum.cpp)
#add_executable(02_allocationForMinCost Tencent2019/02_allocationForMinCost.cpp)
#add_executable(03_arraySubSmallest Tencent2019/03_arraySubSmallest.cpp)

## 字节跳动 2019
### 大数加法定义的 array 形式
#add_executable(bigNumAdd_Array Zijie2019/bigNumAdd_Array.cpp)
#### 大数加法定义的 String 形式
#add_executable(bigNumAdd_String Zijie2019/bigNumAdd_String.cpp)

## 悉见科技
## 求两个字符串的汉明距离
## 求一个collatzSequence序列



## 文远知行，景驰科技
### 最大子数组问题  最大容器装水体积问题
#add_executable(01_theLastSubArraySum    weRide2019/01_theLastSubArraySum.cpp)
#add_executable(01_theLastVesselProblem  weRide2019/01_theLastVesselProblem.cpp)
### 智力题通关问题


## 京东
### 寻找一个大字符串出现的n个小字符串的最大数量
#add_executable(01_findSubstringNums jd2019/01_findSubstringNum.cpp)
