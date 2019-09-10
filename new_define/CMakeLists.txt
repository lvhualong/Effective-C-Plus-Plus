cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

set( new_define_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/new_define)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${new_define_OUTPUT_DIR})


## 一个二进制操作的问题
#add_executable(bin_operate  bin_operate.cpp)

## 定义一个二维矩阵乘法的运算
#add_executable(01_twoDimMatrixMulit     01_twoDimMatrixMulit.cpp)
#add_executable(01_twoDimMatrixMulit_1   01_twoDimMatrixMulit_1.cpp )

## 一个素数的操作   给定一个数， 输出这个范围内所有的素数以及多次方
#add_executable(primeNumberFiniteField  primeNumberFiniteField.cpp)

## 把一个数字进行拆分，定义两种操作， 减1/或者把其中一个再拆分成两个数字
#add_executable(01_splitNum 01_splitNum.cpp)

## 搬运水果的最小成本
#add_executable(02_allocationForMinCost   02_allocationForMinCost.cpp)


## 一个包含n个数字的数组，对数组进行k次操作,定义每次操作的方式
#add_executable(03_arraySubSmallest  03_arraySubSmallest.cpp)

## @JD 给定一个大字符串和n个子串，输出最多能有几个子串
#add_executable(01_findSubstringNum  01_findSubstringNum.cpp)

## @HUAWEI 平面上五个点到原点的最短路径， 使用algorithm  next_permutation函数
#add_executable(02_shortestPahtInPlane 02_shortestPahtInPlane.cpp)

## @aibee 给定一组点，求包围这些点的boundingBox
#add_executable(02_boundingBox  02_boundingBox.cpp)

## @优必选 利用向量叉乘， 判断一个点在线段的左边还是右边，判断两个线段是否相交 判断点在三角形内外还是上
#add_executable(vector-cross-product vector-cross-product.cpp)

## 计算两个向量的夹角
#add_executable(vector_angle math/vector_angle.cpp)