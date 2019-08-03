
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

### 56_1 一个数组中只有两个数字出现了一次，其他数字出现了两次， find them
add_executable(56_1_TwoNumbersAppearOnce 56_1_TwoNumbersAppearOnce/56_1_TwoNumbersAppearOnce.cpp)
add_executable(56_2_NumberAppearingOnce  56_2_NumberAppearingOnce/56_2_NumberAppearingOnce.cpp)

### 57_1 给定一个递增数组和一个数字， 在数组中查找两个数之和组成这个数，
### 57_2 给定一个数字， 输出所有连续序列之和等于这个数，最少两个连续数
#add_executable(57_1_TwoNumbersWithSum 57_1_TwoNumbersWithSum/57_1_TwoNumbersWithSum.cpp)
#add_executable(57_2_ContinuousSquenceWithSum 57_2_ContinuousSquenceWithSum/57_2_ContinuousSquenceWithSum.cpp)

### 58_1 翻转一个字符串中的单词顺序
### 58_2 字符串的左旋转
#add_executable(58_1_ReverseWordsInSentence 58_1_ReverseWordsInSentence/58_1_ReverseWordsInSentence.cpp)
#add_executable(58_2_LeftRotateString 58_2_LeftRotateString/58_2_LeftRotateString.cpp)

### 59_1 滑动窗口最大值
### 59_2 定义一个队列，并且 max push_ back pop_front时间复杂度都是O(1)
#add_executable(59_1_MaxInSlidingWindow 59_1_MaxInSlidingWindow/59_1_MaxInSlidingWindow.cpp)
#add_executable(59_2_QueueWithMax 59_2_QueueWithMax/59_2_QueueWithMax.cpp)

## 60 N个骰子，随机仍在地上，计算所有朝上面之和，所有情况的概率
#add_executable(60_DicesProbability 60_DicesProbability/60_DicesProbability.cpp)

### 61 随机抽出几张扑克牌，判断是不是顺子
#add_executable(61_ContinousCards 61_ContinousCards/61_ContinousCards.cpp)

### 62 约瑟夫环问题，每次从环中删除第m个元素，输入最后一个元素
#add_executable( 62_LastNumberInCircle_JosephuseCircle 62_LastNumberInCircle_JosephuseCircle/62_LastNumberInCircle_JosephuseCircle.cpp)

### 63 最大股票利润， 查找一个数组中最小值和最大值之差
#add_executable(63_MaximalProfit_max_min_value 63_MaximalProfit_max_min_value/63_MaximalProfit_max_min_value.cpp)

### 64发散性思维，巧妙的方法进行累加求和
#add_executable(64_fashion_accumulate 64_fashion_accumulate/64_fashion_accumulate.cpp )