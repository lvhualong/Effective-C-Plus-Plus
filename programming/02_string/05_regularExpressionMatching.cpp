
/* *********************************************************
 * 问题描述：正则表达式的匹配问题(剑指offer-19  LeeCode-10)
 *
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。
 模式中的字符'.' 表示任意一个字符，
 而'*'表示它前面的字符可以出现任意次（含0次）。
 在本题中，匹配是指字符串的所有字符匹配整个模式。
 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。
 * *********************************************************
 */

#include <iostream>
#include <string>
using namespace std;


class Solution{
public:
    bool match(const char* str, const char* pattern)
    {
        if(str == nullptr || pattern == nullptr)
            return false;

        return matchCore(str, pattern);
    }

private:
    bool matchCore(const char* str, const char* pattern)
    {
        //指针结尾的结束条件
        if(*str == '\0' && *pattern == '\0')
            return true;

        if(*str != '\0' && *pattern == '\0')
            return false;

    //注意：先判断pattern的下一个符号是不是【*】，如果是的话要提前考虑
    if(*(pattern + 1) == '*')
        {
            if(*pattern == *str || (*pattern == '.' && *str != '\0'))
                // 进入有限状态机的下一个状态
                return matchCore(str + 1, pattern + 2)
                       // 继续留在有限状态机的当前状态
                       || matchCore(str + 1, pattern)
                       // 略过一个'*'
                       || matchCore(str, pattern + 2);
            else
                // 略过一个'*'
                return matchCore(str, pattern + 2);
        }

    //在判断完pattern的下一个符号不是【*】,再考虑当前是否匹配
        if(*str == *pattern || (*pattern == '.' && *str != '\0'))
            return matchCore(str + 1, pattern + 1); //这种递归相当于指针右移

    //都不满足就直接false
        return false;
    }
};

int main() {
    Solution solution;

    bool matchFlag  = solution.match("aaa", "ab*abbc*a");
    std::cout << "the match result: " << matchFlag<< std::endl;

    return 0;

}
/* *********************************************************
 * 解题思路：
 * 题目要解决模式串的字符 与 字符串中的字符是否匹配的问题
 *
 *  【.】比较好处理，可以替换成任意一个字符，主要是替换成成字符串中一样的字符
 *  【*】代表前一个字符出现的次数，如果多的话可以让它出现两次，少了的话可以让它出现多次
 *
 *  使用 char*的结构存储 str串和pattern串，从头指针一次遍历，
 *  使用递归，结束条件是 两个指针都到结尾了true,  pattern到了-str没到，返回false
 *
 *  条件判断主要有三种情况：
 *
 *  1. pattern最为复杂，而且还会影响它的前一个符号，所以先考虑
 *      如果 pattern+1是【*】，再分情况讨论
 *          如果当前的 str==pattern
 *              要么 把str+1, pattern+2 进行下一次匹配   (相当于 *让前一个字符出现一次)
 *              要么 把str+1, pattern不变，进行下一次匹配(相当于 *让前一个字符出现多次)
 *              要么 把str,   pattern+2，进行下一次匹配  (相当于 *让前一个字符出现0次)
 *          如果当前 str!=pattern
 *              那么 把str, 与 pattern+2 再进行一次匹配  (相当于 *让前面的字符出现0次)
 *      如果 pattern+1不是*
 *          判断当前 str pattern是否匹配，匹配的话，进行 str+1 pattern+1的匹配
 *
 *      当前也不匹配的话，直接return false
 *
 * ----------------------------------
 * 测试示例：
 * 字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。
 * *********************************************************
 */