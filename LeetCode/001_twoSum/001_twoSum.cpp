//
// Created by hualong on 2019/4/1.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * ************************************************
 * 问题描述：
 * 给定一个`整数数组` nums 和一个目标值 target，请你在该数组中找出和为目标值
 * @ 给定 nums = [2, 7, 11, 15], target = 9
 * @ 返回值：[0, 1]
 * ************************************************
 */
class Solution {
public:
    // 暴力遍历法 O(n^2)时间复杂度
//    vector<int> twoSum(vector<int>& nums, int target) {
//        vector<int> index = {0, 0};
//        for(int i=0; i<nums.size(); i++)
//        {
//            //if(nums[i] <= target)
//                for(int j=i+1; j< nums.size(); j++)
//                {
//                    if(nums[j] == (target-nums[i]))
//                    {
//                        index[0] = i;
//                        index[1] = j;
//                        return index;
//                    }
//                }
//        }
//        return index;
//    }

// 哈希表的解决方案  以空间换取时间
vector<int>  twoSum(vector<int>& nums, int target)
{
    const int n = nums.size();
    unordered_map<int,int>  hashMap;
    for(int i = 0; i<n; i++) //一遍哈希表
    {
        if(hashMap.end() != hashMap.find(target - nums[i])) //查找另一个元素
            return  {hashMap[target-nums[i]], i};

        hashMap.insert({nums[i], i}); //将每一个元素加入哈希表
    }
    return {0,1};
}

};


int main()
{
    vector<int> inputNums{-1,-2,-3,-4,-5};
    int realTarget = -8;
    vector<int> expectTarget{2,4};

    vector<int> outputTarget;
    Solution solution;
    outputTarget  =  solution.twoSum(inputNums, realTarget);

    (outputTarget == expectTarget) ?  cout << "Successful! ^_^": cout << "failed -_-";
    cout << endl;


    return 0;
}





/* *********************************************
 * 测试用例：
 * [-1,-2,-3,-4,-5]  -8  ==>  [2,4]
 *
 * *********************************************
 */