
/* *********************************************************
 * 问题描述：计算字符串最后一个单词的长度，单词以空格隔开
 *
 *  一行字符串，非空，长度小于5000
 *  整数N，最后一个单词的长度。
 *
 *  例如：
 *  hello world
 *  5
 * *********************************************************
 */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    string strs;

    getline(cin, strs);
    string ss(strs.rbegin(), strs.rend()); //逆序

    char *c_str = new char[ss.length()+1];
    strcpy(c_str, ss.c_str());
    string pch = strtok(c_str, " "); //切分

    cout << pch.size() << endl; //输出

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