//
// Created by hualong on 2019/4/1.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
 * ************************************************
>问题描述：
将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
```
测试示例：
输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]
```
```
解题思路：
直接遍历一遍进行逆序, 使用数组的引用方式
```
 * ************************************************
 */
class Solution {
public:
// 方法描述：遍历，交换
    void reverseString(vector<char>& s)
    {
        int length = s.size();
        for(int i=0; i< length/2; i++)
        {
            char temp;
            temp = s[i];
            s[i] = s[length-1-i];
            s[length-1-i] = temp;
        }
    }
};


int main()
{
    //输入
    vector<char> input{'H','e','l','l','o'};

    //输出
    cout<< "input:" ;
    for(auto ch:input)
        cout << ch;
    cout<<endl;

    Solution solution;
    solution.reverseString(input);

    cout<< "output:" ;
    for(auto ch:input)
        cout << ch;
    cout<<endl;


    return 0;
}





/* *********************************************
 * 测试用例：
 * [-1,-2,-3,-4,-5]  -8  ==>  [2,4]
 *
 * *********************************************
 */