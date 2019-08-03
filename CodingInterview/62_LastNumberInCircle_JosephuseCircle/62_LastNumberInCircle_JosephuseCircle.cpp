//
// Created by LAB540 on 2019/8/3.
//

// 面试题62：圆圈中最后剩下的数字
// 题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
// 删除第m个数字。求出这个圆圈里剩下的最后一个数字。


#include <list>
#include <iostream>
using namespace std;
//传统方法， 时间复杂度O(mn)
int josePhuse_circle(list<int> nums, int m)
{
    if(nums.empty())
        return 0;
    list<int>::iterator current = nums.begin();
    while (nums.size() > 1)
    {
        // find the current 指向
        for(int i=1; i<m; i++)
        {
            current++;
            if(current == nums.end())
                current = nums.begin();
        }
        //确定下一次的指向
        list<int>::iterator next = ++current;
        if(next == nums.end())
            next = nums.begin();
        //删除当前的vaule
        nums.erase(--current);
        current = next;
    }
    return *current;
}


// ====================方法2====================
// 对问题进行分析后的结果
int LastRemaining_Solution2(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1)
        return -1;

    int last = 0;
    for (int i = 2; i <= n; i ++)
        last = (last + m) % i;

    return last;
}

int main()
{
    list<int> test_list{0,1,2,3,4};
    int test_m = 3;

//    int last_value = josePhuse_circle(test_list, test_m);
    int last_value = LastRemaining_Solution2(5, 3);
    std::cout << "the last value: " << last_value << endl;
    return 0;
}