//
// Created by hualong on 2019/4/1.
//
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/*
 * ************************************************
>问题描述：
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。
找出那个只出现了一次的元素。
```
测试示例：
输入: [2,2,1]
输出: 1
```
 * ************************************************
 */
class Solution {
public:
    //巧用异或
    int singleNumber(vector<int> nums)
    {
        if(! nums.size())
            return 0;

        int single = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            single = single ^ nums[i]; //依次异或来抵消两次的元素
        }
        return single;
    }
    //使用unordered_set 哈希表的形式
    int singleNumber_set(vector<int>& nums) {
        unordered_set<int> numSet;
        long long numSum;
        for(auto num:nums)
        {
            if(numSet.count(num) == 1)//之前出现过
            {
                numSet.erase(num);
                numSum -= num;
            }
            else
            {
                numSet.insert(num);
                numSum += num;
            }
        }
        return numSum;
    }
};


int main()
{
    //输入
    vector<int> input{4,1,2,5,1,2,4};

    cout << "Input: " ;
    for(auto num:input)
        cout << num << " ";
    cout << endl;

    Solution solution;

    cout << "1 Output: " << solution.singleNumber(input)<< endl;
    cout << "2 Output: " << solution.singleNumber_set(input)<< endl;
    return 0;
}





/* *********************************************
 * 测试用例：
 * {4,1,2,5,1,2,4}  ==>  5
 *
 * *********************************************
 */