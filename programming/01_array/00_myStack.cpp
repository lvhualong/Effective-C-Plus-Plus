//
// Created by hualong on 2019/4/27.
//

/*
 * 自定义栈操作
 *
 * init 栈初始化
 * top()
 * pop()
 * push()
 * isEmpty()
 * isPull()
 *
 */
#include <iostream>
#include <cstdio>

using namespace std;

const int  SIZE = 100; // 栈的初始容量
const int  ADDSIZE = 5; // 栈的单位增加容量
const int INF = -0xfffffff;// 用于空栈时防止尴尬，返回一个不能读取的地址，让读取的人尴尬；

template <class T>
struct Strack
{
    T *top;// 栈顶的指针
    T *base;// 栈底的指针
    int strackSize;//栈容量

    void init()//栈的初始化
    {
        base = (T *)malloc(SIZE * sizeof(T));//分配内存
        top = base;
        strackSize = SIZE;
    }

    T Top()
    {// 返回栈顶元素
        if (top == base)
            return INF;// 返回尴尬地址
        return *(top - 1);
    }

    bool pop()
    {// 删除栈顶元素
        if (top == base)
            return false;
        top--;
        return true;
    }

    void push(T x)
    {//栈顶插入元素
        if (isPull()) {//如果内存不够重新分配内存
            base = (T *)realloc(base, (strackSize + ADDSIZE)*(sizeof(T)));
            top = base + strackSize;
            strackSize += ADDSIZE;
        }
        *top++ = x;
    }

    bool isEmpty()
    {//判断栈是否为空
        if (top == base)
            return true;
        return false;
    }

    bool isPull()//判满函数
    {
        if (top - base == strackSize)// 一次push一个所以当top - base = strackSize时满
            return true;
        else
            return false;
    }
};

int main()
{
    Strack<int> myStack;
    myStack.init();
    for(int i=0; i<10; i++)
        myStack.push(i);

    while(!myStack.isEmpty()) {
        cout << myStack.Top() << "  ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}