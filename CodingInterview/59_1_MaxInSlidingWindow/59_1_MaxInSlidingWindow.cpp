//
// Created by LAB540 on 2019/8/3.
//

// 面试题59（一）：滑动窗口的最大值
// 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
// 如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
// 滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，

#include <iostream>
#include <vector>
#include <deque>
using namespace std;


vector<int> maxInWindows(const vector<int>& nums, int windows)
{
    vector<int> max_windows; //要输出的窗口最大值的数组
    if(nums.size()>=windows && windows>=1)
    {
        deque<int> index;//双端队列存的是下标
        for(int i=0; i<windows; i++) //初始化第一个窗口
        {
            while(!index.empty() && nums[i] >= nums[index.back()])
                index.pop_back(); //有更大的加进来就把小的删除

                index.push_back(i);
        }

        for(int i=windows; i<nums.size(); i++)
        {
            max_windows.push_back(nums[index.front()]);//每改变一次滑窗，就输出一个当前滑窗的最大值

            while(!index.empty() && nums[i]>= nums[index.back()])
                index.pop_back();

            if(!index.empty() && index.front() <= i-windows)//前面的值太老了，也该移除滑窗了
                index.pop_front();

            index.push_back(i);

        }

        max_windows.push_back(nums[index.front()]);
    }
    return max_windows;
}

int main()
{
    vector<int> test_nums{2,3,4,2,6,2,5,1};

    vector<int> result = maxInWindows(test_nums, 3);

    for(auto  max: result)
    cout << max << " ";
    cout << endl;
    return 0;
}

/*
 * 解题思路：
 *  最暴力的方法，对每个长度为K的滑窗，求最大值，然后滑动n-k次
 *
 *  第二种方式,维护一个队列，把可能成为滑窗最大值的元素留在滑窗，把当前滑窗最大值放在队列的front端
 */