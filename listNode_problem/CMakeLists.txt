cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

set( listNode_problem_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/listNode_problem)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${listNode_problem_OUTPUT_DIR})



## 构造单向链表 / 双向链表的基本表达
#add_executable( 00_mySingleNodeList  00_mySingleNodeList.cpp)
#add_executable( 00_myDoubleNodeList  00_myDoubleNodeList.cpp)


## 在O(n)的时间复杂度内判断 一个单向链表是否为回文链表
#add_executable(01_isHuiWen_SingleNodeList 01_isHuiWen_SingleNodeList.cpp)


## 二叉树问题
add_executable(binary_tree_node_problem  binary_tree_node_problem.cpp)
### 二叉树的构建
### 二叉树的深度优先遍历和广度优先遍历
