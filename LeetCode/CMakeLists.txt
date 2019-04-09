
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

set( LeetCode_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/LeetCode)

## make directory
##file( MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR})
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/bin)
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/lib)
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${LeetCode_OUTPUT_DIR})


## include_directories(${PROJECT_SOURCE_DIR}/LeetCode/001_twoSum)
#add_executable(001_twoSumEXE 001_twoSum/001_twoSum.cpp)
#add_executable(104_BinTreeMaxDepth 104_BinTreeMaxDepth/104_binTreeMaxDepth.cpp) ##二叉树的最大深度
#add_executable(334_reverseString 334_reverseString/334_reverseString.cpp) ##反转字符数组
#add_executable(557_reverseWords 557_reverseWords/557_reverseWords.cpp) ##反转string的每一个单词
#add_executable(237_deleteNode 237_deleteNode/237_deleteNode.cpp) ## 删除单向链表的一个节点
#add_executable(136_findSingleNumber 136_findSingleNumber/136_findSingleNumber.cpp) ## 查找数组中只出现一次的元素
#add_executable(206_reverseList 206_reverseList/206_reverseList.cpp) ## 单链表反转

add_executable(_newDir_2  _newDir/02.cpp)
add_executable(_newDir_1  _newDir/01.cpp)
add_executable(_newDir_3  _newDir/03.cpp)

add_executable(01 Xiecheng/01.cpp)
add_executable(01 Xiecheng/01.cpp)
add_executable(01 Xiecheng/01.cpp)
