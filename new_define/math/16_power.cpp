
/* *********************************************************
 * 问题描述：
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。
 * ----------------------------------
 * 诱惑性的输入示例：
 *  2.0 2  ==> 4.0
 * *********************************************************
 */

#include <iostream>
//#include <algorithm>
using namespace std;

class Solution{
public:
    //常规方法
    double power_original(double base, int exponent){
        bool invalidInput = false;
        if(equal(base, 0.0))  //特殊值判断与非法输入判断
        {
            if(exponent<0)
                invalidInput = true;
            return 0.0;
        }

        unsigned int absExponent = (unsigned int)exponent;
        if(exponent<0)
            absExponent = (unsigned int)(-exponent);

        double resule = powerWithUnsignedExponent(base, absExponent);
//        double resule = powerWithUnsignedExponent_1(base, absExponent);
        if(exponent<0)
            resule = 1.0/resule;
        return  resule;
    }

private:
    double powerWithUnsignedExponent(double base, unsigned int exponent){
        double result = 1.0;
        while (exponent--)
            result *= base;
        return  result;
    }

    // 新颖方法 来优化这幂函数运算
    double powerWithUnsignedExponent_1(double base, int exponent){
        if(exponent == 0)
            return 1;
        if(exponent == 1)
            return  base;

        double result = powerWithUnsignedExponent_1(base, exponent>>1); //右移代替除法
        result *= result;
        if( exponent&0x1 == 1) //用与运算代替取余
            result *= base;
        return result;
    }

    bool equal(double a, double b){
        if((a-b)>-0.000001 && (a-b)<0.000001)
            return true;
        return false;
    }

};

int main() {
    Solution solution;

    std::cout << "the power result: "<< solution.power_original(-3, -3) << std::endl;

    return 0;

}
/* *********************************************************
 * 解题思路：
 * double Power(double base, int exponent)
 * 题目已经给出了函数的参数形式，所以对参数类型一定要敏感
 * 1. 对幂指数的不同范围进行讨论
 * 2. 对非法输入的讨论 如 0^-2
 * 3. 先求 base^(abs(exponent))
 *
 * 新颖的方法 先求幂运算
 *  0 1 比较特殊， 主要大于等于2次幂以上，可以分奇数偶数讨论
 * ----------------------------------
 * 测试示例：
 *
 * *********************************************************
 */