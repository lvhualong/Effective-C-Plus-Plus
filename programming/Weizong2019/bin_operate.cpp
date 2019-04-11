
/* *********************************************************
 * 问题描述：
给定三个整数a b c, 需要计算2^a+2^b-2^c 在二进制表示下1 的个数
 * ----------------------------------
 * 输入示例：
 * 2^3 + 2^2 - 2^1 = (1010)
 * 输入  3 2 1
 * 输出 2
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
//    int num;
//    cin >> num;
    int a, b, c;
    cin >> a >> b >>c;
    int num = (1<<a | 1<<b) - (1<<c);
    int count = 1 + (b-c);
//    Solution solution;
//    cout << "the number of 1 in binary num: " << solution.numberOf1InBin_1(num) << endl;
//    cout << "the number of 1 in binary num: " << solution.numberOf1InBin_2(num) << endl;
//    cout << solution.numberOf1InBin_2(num) << endl;
      cout << count <<endl;
    return 0;

}
/* *********************************************************
 * 解题思路：
 *  最开始的思路是因为做了求一个数中1的个数，想着先求这个数，再求1的个数
 *  但是这个数太了， 最多左移32位或者64位，所以要想其他办法
 *
 *  既然 a>b>c 所以2^a+2^b-2^c时， a的1保持不变，b的1被借调，b c 之间的0全部变成1
 *
 *  求一个数中1的个数
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