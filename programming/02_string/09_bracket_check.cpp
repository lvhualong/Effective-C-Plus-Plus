//
// Created by hualong on 2019/4/27.
//
/*
 *  括号匹配问题：
 * 给定一个字符串，里边可能包含“()”、"{}"、“[]”三种括号，
 * 请编写程序检查该字符串的括号是否成对出现。
 * 输入一行字符串，输出， true or false
 *
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isBracketMatch(string& str )
{
    stack<char> leftBracket;
    for(int i=0; i<str.length(); ++i)
    {
        if(str[i] == '('  || str[i] == '[' ||str[i] == '{')
            leftBracket.push(str[i]);
        else if(str[i] == ')'  || str[i] == ']' ||str[i] == '}')
        {
            switch(str[i])
            {
                case ')':
                    if(leftBracket.top() == '(') {
                        leftBracket.pop();
                        break;
                    } else return false;
                case ']':
                    if(leftBracket.top() == '[') {
                        leftBracket.pop();
                        break;
                    } else return false;
                case '}':
                    if(leftBracket.top() == '{') {
                        leftBracket.pop();
                        break;
                    } else return false;
                default:
                    break;
            }
        }
        else continue;
    }
    if(leftBracket.empty())
        return true;
    else return false;
}

int main()
{
//    string testStr = "(6-{(2+3)*(8/(6-5))}";
    string testStr = ")6-{(2+3)*(8/(6-5))}";
//    string testStr = "6-{(2+3)*(8/(6-5))}";

    bool flag = isBracketMatch(testStr);
    if(flag)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

/*
 * 解决思路：
 * 1. 遇到左括号 ([{ 都放入栈中
 * 2. 遇到非括号都不管
 * 3. 遇到右括号，和栈顶元素比较
 *
 * 注意最后看栈是否为空哈
 */