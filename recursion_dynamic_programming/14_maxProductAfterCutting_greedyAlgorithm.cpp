
/* *********************************************************
 * 问题描述：
 // 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。
 * ----------------------------------
 * 输入示例：
 * 输入 n
 * 输出 最大乘积
 *
 * *********************************************************
 */

#include <iostream>
#include <cmath>

using namespace std;

class Solution{
public:
    int maxProductAfterCutting_greedyAlgorithm(const int& length){
        //边界条件
        if(length<2) return 0;
        if(length == 2) return 1;
        if(length == 3) return 2;
        if(length == 4) return 4;

        //从下往上存储最优值的数组
        int max;
        int timesOf3 = length/3; //切成3的份数
        int timesOf2 = 0;
        if(length%3 == 1)
            timesOf3--;
        timesOf2 = (length-timesOf3*3)/2;
        max = pow(3, timesOf3)*pow(2, timesOf2);
        return max;
    }
};

int main() {

    const int length = 8;
    Solution solution;
    cout << "the max product after cutting: "<< solution.maxProductAfterCutting_greedyAlgorithm(length) << endl;

    return 0;

}
/* *********************************************************
 * 解题思路：
 * 动态规划求解： f(n)= f(i)*f(n-i)  时间复杂度O(n^2)
 *  先从i 处切分，将一个划分成 i  n-i两段，
 *  f(n)= f(i)*f(n-i)
 *  因为并不知道那个f(i)是最优的，所以要循环遍历一下
 *  从下往上依次求解
 *
 * 贪心算法求解
 *  length= 1 2 3 4的情况单独拿出来分析
 *  分析 n>=5
 *  首先 n>4
 *  n-4 > 0
 *  2n-4 > n
 *  2(n-2) > n  当绳子剩下的长度 大于等于5时， 剪成2或者3的长度的乘积 大于原本长度
 *
 *  n>=5
 *  3(n-3)>= 2(n-2) 因此应该尽量多减长度为3的绳子段
 *  所有贪心算法设计：
 *  应为n>=5,  length除以3的余数， 1 2两种情况，如果余数为1，拨出一个3 凑成两个2
 *  1. length/3 看能切出多少个3
 *  2. 对余数处理，如果余数为2刚好，如果余1，拨出一个3 凑成两个2
 * ----------------------------------
 * 测试示例：
 * 5
 * 6 (3*2)
 *
 * 8
 * 18 (3*3*2)
 * *********************************************************
 */