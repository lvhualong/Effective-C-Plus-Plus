//
// Created by LAB540 on 2019/8/4.
//

// 面试题53（三）：数组中数值和下标相等的元素
// 题目：假设一个单调递增的数组里的每个元素都是整数并且是唯一的。请编程实
// 现一个函数找出数组中任意一个数值等于其下标的元素。例如，在数组{-3, -1,
// 1, 3, 5}中，数字3和它的下标相等。

#include <vector>
#include <iostream>
using namespace std;

int findIndexEqualValue(vector<int> nums)
{
    int length = nums.size();
    int left = 0;
    int right = length - 1;
    while(left <= right)
    {
        int middle = (left + right) >>1;
        if(middle == nums[middle])
            return middle;
        if(middle < nums[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}




int main()
{
    vector<int> test{-1,1,4,6,9};

    cout << "the result:"  << findIndexEqualValue(test) << endl;
    return 0;
}