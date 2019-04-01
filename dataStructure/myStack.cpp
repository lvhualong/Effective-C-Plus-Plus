//
// Created by hualong on 2019/3/28.
//

#include "myStack.h"


// 利用帧实现进制转换
//void convert(StackWithVector<char>& stack , int64 input, int base)
//{
//    static char digit[] =
//            {'0','1','2','3','4','5','6','7','8','9','A','B','C',,'D','E','F'};
//
//    if(input>0)// 递归版本
//    {
//        convert(stack, input/base, base);
//        stack.push(input%base);
//    }
//}

void convert(StackWithList<char>& stack , int64_t input, int base)
{
    static char digit[] =
            {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    while (input>0) //迭代版本
    {
        stack.push(input%base);
        input /= base;
    }
}

//// 计算 括号是否匹配
//bool paren (const char exp[], int lo, int hi)
//{
//    StackWithVector<char> stack; //记录尚未匹配的左括号
//    for(int i=lo; i<hi; i++)
//    {
//        switch (exp[i])
//        {
//            case '(':
//            case '[':
//            case '{': stack.push(exp[i]);
//            case ')': if(stack.empty() || '(' != stack.pop()) return false; break;
//            case ']': if(stack.empty() || '[' != stack.pop()) return false; break;
//            case '}': if(stack.empty() || '{' != stack.pop()) return false; break;
//            default:
//                break;
//        }
//    }
//    return  stack.empty(); // 空栈说明匹配上了
//}

//int main()
//{
//    return 0;
//}