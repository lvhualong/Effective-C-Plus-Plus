
/* *********************************************************
 * 问题描述：
 // 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。
 * ----------------------------------
 * 输入示例：
 * 输入 n m
 * 输出 最大乘积
 *
 * *********************************************************
 */

#include <iostream>

using namespace std;

class Solution{
public:
    int maxProductAfterCutting_dynamic(const int& length){
        //边界条件
        if(length<2) return 0;
        if(length == 2) return 1;
        if(length == 3) return 2;

        //从下往上存储最优值的数组
        int max;
        int* product = new int[length+1];
        product[0] = 0;
        product[1] = 1;
        product[2] = 2;
        product[3] = 3;
        for(int i=4; i<=length; ++i){
            max = 0;
            for(int j=1; j<i; ++j){
                int product_temp = product[j]*product[i-j];
                if(product_temp > max)
                    max = product_temp;
                }
            product[i] = max;
        }
        max = product[length];
        delete[] product;
        return max;
    }

};

int main() {

    const int length = 8;
    Solution solution;
    cout << "the max product after cutting: "<< solution.maxProductAfterCutting_dynamic(length) << endl;

    return 0;

}
/* *********************************************************
 * 解题思路：
 * 动态规划求解： f(n)= f(i)*f(n-i)  时间复杂度O(n^2)
 *  先从i 处切分，将一个划分成 i  n-i两段，
 *  f(n)= f(i)*f(n-i)
 *  因为并不知道那个f(i)是最优的，所以要循环遍历一下
 *  从下往上依次求解
 * ----------------------------------
 * 测试示例：
 * 5
 * 6 (3*2)
 *
 * 8
 * 18 (3*3*2)
 * *********************************************************
 */