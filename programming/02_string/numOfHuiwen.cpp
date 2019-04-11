
/* *********************************************************
 * 问题描述：
// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。
 * ----------------------------------
 * 输入示例：
 * 3
 *
 * 1 2 3 …… 999
 *
 * *********************************************************
 */

#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

class Solution{
public:
    bool countHuiwen(long long number){
        int binNum[30];
        int bit;
        int cur = 0;
        while(number)
        {
            bit = number & 1;
            number = number>>1;
            binNum[cur] = bit;
            cur ++;
        }
        cur --;
        int start = 0;
        int end = cur;
        while((start<end) && binNum[start]== binNum[end] )
        {
            ++start ;
            --end ;
        }
        if (binNum[start]== binNum[end])
                return true;
        else return false;
    }


};

int main() {
    long long number ;
    cin >> number;
    int count = 1;
    Solution solution;
    while(number)
    {
        if (number&1)
        {
            if (solution.countHuiwen(number))
            {
                count++;
            }
        }


        number--;
    }

    cout<<count<<endl;




    return 0;
}
