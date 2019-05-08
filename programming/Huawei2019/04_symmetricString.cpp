
/* *********************************************************
 * 问题描述：判断一个字符串是否为双对称字符串
 *
 * 双对称字符串的定义：
 * 1. 字符串是一个对称字符串(字符串顺序和逆序一样) 如 aabbaa
 * 2. 字符串长度为偶数 aabcc 就不行
 * 3. 字符串的连续两个字符都一致
 *
 * 同时满足上面三个条件称为双对称字符串
 *
 * 输入多行（可能多行，可能一行）
 * 输出：每行一个输出结果，如若不是 输出 false, 是的话就变成单对称序列
 *
 * 例如：
 * aabbccbbaa
 * aabbcccbbaa
 *
 * abcba
 * false
 * *********************************************************
 */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void function(string& string_input) {
    string string_output;
    string string_res(string_input.rbegin(), string_input.rend()); //逆序
    if (string_input.size() % 2 == 0 && string_input == string_res) {
        string::iterator pOne = string_input.begin();
        string::iterator pTwo = string_input.begin();
        pTwo++;
        while (pTwo < string_input.end()) {
            if (*pOne != *pTwo) {
                cout << "false" << endl;
                return;
            } else{
                string_output += (*pOne); //别在这一个一个输出
            }
            pOne += 2;
            pTwo += 2;
        }
        cout << string_output <<endl; //要匹配完之后整个输出

    }
    else
      cout << "false" << endl;
}


int main() {
    string string_input;
//    while(getline(cin, string_input))
    while(cin>>string_input)
        function(string_input);

  return 0;
}
/* *********************************************************
 * 解题思路：
 * aabbccbbaa
 * abccba
 * aabccbaa 注意这个测试示例哈，之前通过80%就是没有考虑这个测试示例
 * 出现 afalse 这种情况， 字符串要一并输出
 * ----------------------------------
 * 测试示例：
 *
 * *********************************************************
 */