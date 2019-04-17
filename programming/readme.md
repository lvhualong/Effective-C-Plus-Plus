<!-- vscode-markdown-toc -->
* 1. [数组 array](#array)
	* 1.1. [有序数组元素去重](#)
* 2. [字符串 string](#string)
* 3. [树 Tree](#Tree)
* 4. [排序](#-1)
* 5. [搜索](#-1)
* 6. [动态规划](#-1)
* 7. [设计问题](#-1)
* 8. [数学问题](#-1)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

# 算法与数据结构编程题  

## 常用算法
- next_permutation 全排列算法 01_array/shortestPathInPlane
- sort 对二维 vector的排序  01_array/boundingBox
- vectot list/deque的使用 01_array/arrayShiftProblem


##  1. <a name='array'></a>数组 array   
### 一叠牌 每次输入第一个，第二个移到最后
### 有序数组元素去重 
> 给定一个排序数组，你需要在原地删除重复出现的元素，  
使得每个元素只出现一次，返回移除后数组的新长度。  
给定 nums = [0,0,1,1,1,2,2,3,3,4],  
函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 

### 求一组二维点的boundingBox坐标 左上 右下
### 平面上五个二维点到原点的最短路径
### 在二维平面上切水果，输出最少的刀数


##  2. <a name='string'></a>字符串 string  

##  3. <a name='Tree'></a>树 Tree  

##  4. <a name='-1'></a>排序  

### sort的一维，多维排序
```C
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main () {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

  // using function as comp
  std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

  // using object as comp
  std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

```

##  5. <a name='-1'></a>搜索  

##  6. <a name='-1'></a>动态规划与贪心算法 
### 长为N的绳子剪成M段，求每段乘积最大值[]

##  7. <a name='-1'></a> 回溯算法 
### 字符二维矩阵中查找包含某一个字符串的路径[12_stringPathInMatrix]
### 机器人在二维平面上运动，每次移动一格，不能步入数位之和大于K的格子[13_robotMoveCountInPlane]

##  8. <a name='-1'></a>数学问题
### 输入一个整数，输出这个数二进制中1的个数[位操作 ]
### 不使用库函数，实现整数或者浮点数的 sqrt函数 [注意效率]
### 不使用库函数，实现幂函数运算Power(double base, int exponent)[注意代码的完整性]

========================================================

# 名企编程器

========================================================
## 腾讯2019笔试编程题
### 01 一个数字的拆分消去游戏 [每次拆分成两数之和或者减1]  
### 02 n个村庄的水果供给分配问题  [有正有负，要求搬运次数最少]  
### 03 对一个有n个数字的数组，对数组进行k次操作[非零元 - 最小的非零元)]    

## AiBEE 笔试题
### 定义二维矩阵乘法 [导清楚 M N K的对应下标]
### 给定一些二维平面的点，算出这些点的BoundingBox [二维Vector的排序/查找]

## 华为2019笔试编程题
### 字符串的小端/大端编码[字符串的切分 与字符串逆序]
### 二维平面上5点到原点的最短路径 [5个点的全排列，然后遍历一遍 <algorithm> //next_permutation 全排列算法]
### 二维平面上直线切水果[切水果]
### 字符串的加减问题[括号类问题，括号匹配的一类问题] 

## 腾讯-微众银行2019  
### 给出三个整数 a b c 需要计算2^a+2^b-2^c 在二进制表示下1 的个数[二进制运算的考察]
### 输入一个 < 1000的整数， 求素数的有限域内元素个数 [素数的变体]

## 字节跳动2019
### 两个整形数组的加法定义 
