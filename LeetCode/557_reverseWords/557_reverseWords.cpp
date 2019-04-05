//
// Created by hualong on 2019/4/1.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  //std::reverse
using namespace std;
/*
 * ************************************************
问题描述：
给定一个字符串，你需要反转字符串中每个单词的字符顺序，
同时仍保留空格和单词的初始顺序。
在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
```
测试示例：
输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc"
```
```
解题思路：
以空格为间隔分开字符，再对每个字符反转
 C++ 有reverse可以反转单段字符，没有split
 定义一个vector<int> 记录空格位置
```
 * ************************************************
 */
class Solution {
public:
// 方法描述：
    string reverseWords(string s)
    {
        //记录空格位置
        vector<int> blank_posi;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == ' ')
                blank_posi.push_back(i);
        }
        int blank_nums = blank_posi.size();
        if(blank_nums == 0) {
            reverse(s.begin(), s.end()); //注意形参为迭代器
            return s;
        }
            reverse(s.begin(), s.begin()+blank_posi[0]); //反转第一个word
        for(int i=0; i<blank_nums-1; i++) {
            reverse(s.begin()+blank_posi[i]+1, s.begin() + blank_posi[i+1]); //反转second -- lase second
        }
        reverse(s.begin()+blank_posi[blank_nums-1]+1, s.end()); //+1 别把最后的空格给丢了

        return s;
    }
};


int main()
{
    //输入
    string inputString="Let's take a LeetCode contest !";
    cout <<"Input: " << inputString <<endl;
    Solution solution;
    string outputString = solution.reverseWords(inputString);

    cout << "Output: "<< outputString <<endl;
    return 0;
}





/* *********************************************
 * 测试用例：
 * "aabbccddeeff"  //注意单个字符串的情况
 *
 * *********************************************
 */