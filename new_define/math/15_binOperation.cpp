
/* *********************************************************
 * 问题描述：
// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。
 * ----------------------------------
 * 输入示例：
 * 输入 9
 * 输出 2  因为你1001
 * *********************************************************
 */

#include <iostream>
using namespace std;

class Solution{
public:
    //常规解法
    int  numberOf1InBin_1(int& num){
        int count = 0;
        unsigned int flag = 1;
        while(flag){
            if(num & flag)
                count++;
            flag = flag << 1; //左移到整数的最大位，最后就变成0  循环32次
        }
        return count;
    }

    //巧妙解法
    int numberOf1InBin_2(int& num){
        int count = 0;
        while(num){
            num = num & (num-1); //每次消去最右边的一个1，有几个1就循环几次
            count++;
        }
        return count;
    }
};

int main() {
    int num;
    cin >> num;
//    int a, b, c;
//    cin >> a >> b >>c;
//    int num = (1<<a | 1<<b) - (1<<c);

    Solution solution;
//    cout << "the number of 1 in binary num: " << solution.numberOf1InBin_1(num) << endl;
//    cout << "the number of 1 in binary num: " << solution.numberOf1InBin_2(num) << endl;
    cout << solution.numberOf1InBin_2(num) << endl;
    return 0;

}
/* *********************************************************
 * 解题思路：
 *
 *  思路1：通过每次通过左移、右移一位，然后与1与，统计1的个数
 *  【注意 负数的右移操作是补1】
 *
 *  任意一个数二进制表示间，减去1，会把最右边的1变成0， 1左边的不变，1右边的0都编程1
 *  例如 1100  - 1 = 1011
 *
 * ----------------------------------
 * 测试示例：
 * 9 --> 2
 *
 * -9 --> 31
 *
 * *********************************************************
 */