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
// 方法描述：
vector<int>  twoSum(vector<int>& nums, int target)
{

}

};


int main()
{
    //输入
    vector<int> inputNums{-1,-2,-3,-4,-5};
    int realTarget = -8;
    vector<int> expectTarget{2,4};

    //输出
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