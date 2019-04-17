
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

set( CodingInterview_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/codingInterview)

## make directory
##file( MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR})
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/bin)
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/lib)
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CodingInterview_OUTPUT_DIR})

##
### 3 无序数组去重
#add_executable(03_duplicationInArray 03_duplicationInArray/03_duplicationInArray.cpp)
### 4 针对 横向 纵向都有序的的二维数组 查找
#add_executable(04_findInPartiallySortedMatrix 04_findInPartiallySortedMatrix/04_findInPartiallySortedMatrix.cpp)
### 5 字符串指定元素的替换
#add_executable(05_replaceStringSpaces 05_replaceStringSpaces/05_replaceStringSpaces.cpp)
### 6 单链表的创建 插入 删除 打印
#add_executable(06_ListNodeInsert_Delete_Print 06_ListNodeInsert_Delete_Print/06_ListNodeInsert_Delete_Print.cpp) ##单链表
### 6 双向链表的创建 插入 删除 打印
#add_executable(06_dobuleListNode 06_ListNodeInsert_Delete_Print/06_DoubleListNodeInsert_Delete_Print.cpp) ##双向链表

