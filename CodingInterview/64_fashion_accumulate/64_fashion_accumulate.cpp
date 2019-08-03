//
// Created by LAB540 on 2019/8/3.
//

// 面试题64：求1+2+…+n
// 题目：求1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case
// 等关键字及条件判断语句（A?B:C）。
// 除了 n(n+1)/2 无外乎就是循环和递归两种方式

#include <cstdio>
#include <iostream>


// 方式一： 将累加运算放在构造函数中完成， 使用static的成员变量
class Temp
{
public:
    Temp()
    {
        ++N;
        Sum += N;
    }

    static void Reset()
    {
        N = 0;
        Sum = 0;
    }

    static unsigned int GetSum()
    {
        return Sum;
    }

private:
     static unsigned int N;
     static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;
unsigned  int Sum_solution1(unsigned int n)
{
    Temp::Reset();
    Temp *a = new Temp[n];
    a = NULL;

    return  Temp::GetSum();
}

// 方式二： 利用虚函数求解
// 虚函数的基类和继承类，一个充当递归函数，一个处理递归终止情况
class A;
A* Array[2];

//终止条件，n=0了
class A
{
public:
    virtual unsigned int Sum(unsigned int n) {
        return 0;
    }
};

//递归条件
class B : public A
{
    virtual unsigned int Sum(unsigned int n) {
        return Array[!!n]->Sum(n - 1) + n;
    }
};

int Sun_Solution2(int n)
{
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;

    int value = Array[1]->Sum(n);

    return value;
}

// 方法三：利用函数指针求解
// 使用函数指针的方式来构建一个递归；
typedef unsigned int (*fun)(unsigned int);

unsigned int Solution3_Terminator(unsigned int n)
{
    return 0;
}

unsigned int Sum_Solution3(unsigned int n)
{
    static fun f[2] = {Solution3_Terminator, Sum_Solution3};
    return n + f[!!n](n-1);
}

// 利用模板类求解
template <unsigned int n> struct Sum_Solution4
{
    enum Value { N = Sum_Solution4<n - 1>::N + n};
};

template <> struct Sum_Solution4<1>
{
    enum Value { N = 1};
};

template <> struct Sum_Solution4<0>
{
    enum Value { N = 0};
};




int main()
{
//   // int sum_1 = Sum_solution1(3);
//    int sum_2 = Sun_Solution2(3);
//   // std::cout << "sum_1: " << sum_1 << std::endl;
//    std::cout << "sum_2: " << sum_2 << std::endl;
//    int sum_3 = Sum_Solution3(3);
//    std::cout << "sum_3: " << sum_3 << std::endl;
    int sum_4 = Sum_Solution4<3>::N;
    std::cout << "sum_4: " << sum_4 << std::endl;
    return 0;
}


