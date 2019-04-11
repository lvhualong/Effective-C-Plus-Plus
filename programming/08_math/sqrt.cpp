//
// Created by hualong on 2019/4/1.
//
#include <iostream>

using namespace std;
/*
 * ************************************************
 * 问题描述：
 * 使用高效的方法，定义 sqrt运算
 * @ 输入整形数 int x  或者 浮点型
 * @ 输出整形数 根号x
 * 4 -> 2
 * 5 -> 2
 * ************************************************
 */
class Solution {
public:
// 方法描述：二分法迭代
float sqrtByBisection(float const& x)
{

    if(x<0) return x;
    float lo, hi, mid, last;
    lo = 0; hi = x;
    mid = (lo + hi )/2;
    do{

        if(mid*mid > x) hi = mid;
        else lo = mid;
        last = mid;
        mid = (lo + hi )/2;
    }while(abs(mid-last) > eps);
    return mid;
}

// 线性高斯牛顿迭代的方式
// 用(x, f(x))的切线来逼近方程 x^2 - a = 0, 根号a 就是方程的一个正实根
// 函数的切线斜率是2x, x-f(x)/(2x)就是比x更接近根的近似值
// 带入 f(x)=x^2-a得到x-(x^2-a)/(2x)，也就是(x+a/x)/2。
float sqrtByNewton(float const& x)
{
    float val = x; //final value
    float last; //上一次计算的值
    do{
        last = val;
        val = (val + x/val)/2;
    }while(abs(last-val)>eps);
    return val;
}

private:
     float eps = 0.001; //精度控制净量小一些
};


int main()
{
    //输入
    float intNum = 5;

    //输出
    float outputTarget1,outputTarget2;
    Solution solution;
    outputTarget1  =  solution.sqrtByBisection(intNum);
    outputTarget2  = solution.sqrtByNewton(intNum);

    cout << "sqrtByBisection Result = " << outputTarget1 << endl;
    cout << "sqrtByNewton Result = " << outputTarget2 << endl;
    cout << endl;


    return 0;
}





/* *********************************************
 * 测试用例：
 *
 * *********************************************
 */