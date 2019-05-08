//
// Created by hualong on 2019/4/27.
//
/*
 * 根据字符串所给的表达式 判断字符串是否合理，并计算字符串表达式的值
 * 【leetcode 150  逆波兰序问题】
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;// 命名空间


int compareNumber(char x)//用来比较符号的优先级
{
    if (x == '+' || x == '-')
        return 0;
    if (x == '*' || x == '/')
        return 1;
    return -1;
}

// 将字符表达式的中序， 改为逆波兰序的 后序
void change(string& mid, string& suxfix)//中缀表达式转换为后缀表达式
{
    int i = 0, len = mid.length(), mid_index = 0;

    stack<char>intElements;// int数据集
    intElements.push('#');// 特殊符号用来区分元素
    while (i < len)
    {
        if (mid[i] == '(')
        {
            intElements.push(mid[i]);
            i++;
        }
        else if (mid[i] == ')')
        {
            while (intElements.top() != '(')
            {
                suxfix[mid_index++] = intElements.top();
                suxfix[mid_index++] = ' ';
                intElements.pop();
            }
            intElements.pop();
            i++;
        }
        else if (mid[i] == '+' || mid[i] == '-' || mid[i] == '/' || mid[i] == '*')
        {
            while (compareNumber(intElements.top()) >= compareNumber(mid[i]))
            {
                suxfix[mid_index++] = intElements.top();
                suxfix[mid_index++] = ' ';
                intElements.pop();
            }
            intElements.push(mid[i]);
            i++;
        }
        else if (mid[i] >= '0'&&mid[i] <= '9')
        {
            while (mid[i] >= '0'&&mid[i] <= '9')
            {
                suxfix[mid_index++] = mid[i];
                i++;
            }
            suxfix[mid_index++] = ' ';
        }
        else
        {

        }
    }
    while (intElements.top() != '#') {
        suxfix[mid_index++] = intElements.top();
        suxfix[mid_index++] = ' ';
        intElements.pop();
    }
    suxfix[mid_index] = 0;
}

double countSuxfix(string& suxfix)//计算后缀表达式   suxfix后缀表达式
{
    int len = suxfix.length();
    double x;
    stack <int>intElements;
    int i = 0;
    while (i<len) {
        if (suxfix[i] == ' ')// 用于表达式有效字符集用完跳出循环
        {
            i++;
            continue;
        }
        switch (suxfix[i])
        {
            case '+':
                x = intElements.top();//根据原理图看
                intElements.pop();
                x = intElements.top() + x;
                intElements.pop(); i++;
                break;
            case '-':
                x = intElements.top();
                intElements.pop();
                x = intElements.top() - x;
                intElements.pop();
                i++;
                break;
            case '*':
                x = intElements.top();
                intElements.pop();
                x = intElements.top()*x;
                intElements.pop();
                i++;
                break;
            case '/':
                x = intElements.top();
                intElements.pop();
                x = intElements.top() / x;
                intElements.pop();
                i++;
                break;
            default:
            {
                x = 0;
                while (suxfix[i] >= '0'&&suxfix[i] <= '9') {
                    x = x * 10 + suxfix[i] - '0';// 连续2个数，第一个*10，以此类推
                    i++;
                }
            }
        }

        intElements.push(x);
    }
    return intElements.top();
}
int main()
{
    string str, newStr;
    cin >> str;
    change(str, newStr);
    cout << newStr << endl;
    cout << countSuxfix(newStr) << endl;
    return 0;
}

/*
 * 解决思路：
 *
 * 测试用例：
 * ( 1 + 2 ) * 3 /4
 */

