//
// Created by LAB540 on 2019/8/3.
//

// 面试题57（二）：为s的连续正数序列
// 题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
// 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、
// 4～6和7～8。

#include <iostream>
#include <deque>


using namespace std;

int sumSequence(deque<int> nums)
{
    int sum = 0;
    for(auto num:nums)
        sum += num;
    return sum;
}

void printSequence(const deque<int> nums)
{
    for(auto num:nums)
        cout << num << " ";
    cout << endl;
}

void ContinuousSequenceWithSum(unsigned int num)
{
    deque<int> sequence{1,2};
    int begin = sequence.front();
    int end = sequence.back();

    while (end <= (num+1)/2 && !sequence.empty())
    {
        int current_sum = sumSequence(sequence);
        if ( current_sum == num)
        {
            printSequence(sequence);
            sequence.push_back(++end);
        }
        else if(current_sum < num)
            sequence.push_back(++end);
        else
            sequence.pop_front();
    }

}

int main()
{
    ContinuousSequenceWithSum(15);
    return 0;
}

/*
 * 解题思路： 设置两个迭代器，不断地进行移动
 * - 把两个迭代器之前的所有元素求和，如果小了，右边增加，如果小了，左边剔除；
 */

/*
 * 测试用例：
 * 15
1 2 3 4 5
4 5 6
7 8

 */