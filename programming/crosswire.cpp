//
// Created by hualong on 2019/4/2.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * ************************************************
 * 问题描述： 交叉线 相交圆问题
 * 给出n个在横坐标上的点，然后连续的用半圆连接他们：
 * 首先连接第一个点与第二点(以第一个点和第二点作为半圆的直径)。
 * 然后连接第二个第三个点，直到第n个点。
 * 现在需要判定这些半圆是否相交了，在端点处相交不算半圆相交。
 * 2
 * 4
 * 0 10 5 15
 * 4
 * 0 15 5 10
 *
 * y
 * n
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