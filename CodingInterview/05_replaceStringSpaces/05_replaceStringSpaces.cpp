//
// Created by hualong on 2019/4/1.
//
#include <iostream>
using namespace std;
/*
 * ************************************************
 * 问题描述： 字符串数组中的空格替换
 * 请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入，则输出
 * @ 输入： “We are happy.”
 * @ 返回： “We%20are%20happy.”
 *
 * 解题思路： 如果从前往后插入，每替换一个空格，就要移动后面的所有元素一次
 * 所以可以考虑从后往前替换。使用两个指针不断向前移动。
 * ************************************************
 */
class Solution {
public:
// 方法描述：
    void replceStringSpaces(char* str, int length){
        if(str==nullptr && length<=0)
            return;
        //先遍历出空格的数量
        char* pStr = str;
        int count = 0;
        while (*(pStr++) != '\0'){
            if(*pStr == ' ')
                count++;
        }
        //从后往前移动
        int newLength = length + count*2; //每有一个空格，字符串长度增加2
        int indexOfOriginal = length;
        int indexOfNew = newLength;
        while (indexOfOriginal>=0 && indexOfNew > indexOfOriginal){
            if(str[indexOfOriginal] == ' ') {
                str[indexOfNew--] = '0';
                str[indexOfNew--] = '2';
                str[indexOfNew--] = '%';
            } else
                str[indexOfNew--] = str[indexOfOriginal];
            indexOfOriginal--;
        }
}


};


int main()
{
    //输入
    char inputString[] = "We are happy.";
    int stringLength = sizeof(inputString)/sizeof(char);

    Solution solution;
    solution.replceStringSpaces(inputString,stringLength);
    char* pString = inputString;
    while (*pString != '\0') {
        cout << *pString;
        pString++;
    }
    cout<< endl;

    return 0;
}

/* *********************************************
 * 分析思路： 字符串的替换
 * 每替换一次，串的长度会增加2，同时对于连续存储空间，串后面的数据
 * 所以避免数据移动的次数
 *
 * 测试用例：
 * "We are happy."
 * ""
 * "   "
 *
 * *********************************************
 */