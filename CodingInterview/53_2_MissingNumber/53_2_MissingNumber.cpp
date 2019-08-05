//
// Created by LAB540 on 2019/8/4.
//

// 面试题53（二）：0到n-1中缺失的数字
// 题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字
// 都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组
// 中，请找出这个数字。
// 例如 {0,1,3,4}  missing 2

#include <vector>
#include <iostream>
using namespace std;

int findMissingNum(vector<int> nums)
{
    int length = nums.size();
    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        int middle = (left+right) >> 1;
        if(middle != nums[middle])
        {
            if(middle==0 || nums[middle-1]== middle-1)
                return  middle;
            right = middle -1;
        }
        else
            left = middle+1;
    }
    if(left == length)//最后一种情况
        return length;
    return -1;
}

int main()
{
    vector<int> test{1,2,3,4,5};
    vector<int> test_1{0,1,2,3,4};
    vector<int> test_2{0,2,3,4,5};

    cout << "the result:"  << findMissingNum(test_2) << endl;
    return 0;
}