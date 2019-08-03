//
// Created by LAB540 on 2019/8/3.
//
// 面试题57（一）：和为s的两个数字
// 题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们
// 的和正好是s。如果有多对数字的和等于s，输出任意一对即可。
#include <iostream>
#include <vector>

using namespace std;

bool TwoNumbersWithSum(vector<int> nums, int sum, int& a, int& b)
{
    if(nums.size() < 2)
        return false;
    vector<int>::iterator begin = nums.begin();
    vector<int>::iterator end = nums.end()-1;

    while (begin < end)
    {
        int currnetSum = *begin + *end;

        if(currnetSum == sum)
        {
            a = *begin;
            b = *end;
            return  true;
        }
        else if(currnetSum > sum)
            end--;
        else
            begin++;
    }

    return false;
}

int main()
{
    vector<int> test{1,2,3,4,5,6,7};

    int result_a =0, result_b = 0;
    int sum = 6;
    bool result = TwoNumbersWithSum(test, sum, result_a, result_b);

    if(result)
        cout << "find the value: "<< result_a <<" " << result_b << endl;
    else
        cout << "can not find the value" << endl;

    return 0;
}
