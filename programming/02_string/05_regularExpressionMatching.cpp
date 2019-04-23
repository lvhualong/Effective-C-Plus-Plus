
/* *********************************************************
 * 问题描述：正则表达式的匹配问题
 *
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。
 模式中的字符'.' 表示任意一个字符，
 而'*'表示它前面的字符可以出现任意次（含0次）。
 在本题中，匹配是指字符串的所有字符匹配整个模式。
 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。
 * *********************************************************
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution{
public:
    bool isMatch(string str, string pattern){
        int slen = str.size(), plen = pattern.size();
        //
        vector<vector<bool>>  dp(slen+1, vector<bool>(plen));

    }
};

int main() {
    Solution solution;

    std::cout << " " << std::endl;

    return 0;

}
/* *********************************************************
 * 解题思路：
 *
 * ----------------------------------
 * 测试示例：
 *
 * *********************************************************
 */