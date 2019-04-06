//
// Created by hualong on 2019/4/6.
//
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/*
 * ************************************************
 * 问题描述：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
 例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

 * 解题思路：
 * 1.最笨方法：先排序，然后查找相邻是否重复 排序需要O(nlogn),
 * 2.使用hash表，把数组元素加入到hash表，时间复杂度O(n), 然后扫描每一个元素 O(1), 但是空间上需要一个O(n) hash表为代价
 * 3. 注意题目所有数字都在0到n-1的范围内， 所以如果没有重复，通过交换，元素和下标应该是一致的。(不过与很多条件要注意,容易数组越界)
 * ************************************************
 */
class Solution {
public:
// 方法描述：hash table method
    bool duplicationInArray_1(vector<int>& nums, int& dup_num) {
        if(nums.empty())   return false;

        unordered_set<int> hashTable;
        for (auto num:nums) {
            if (hashTable.count(num) == 1) {
                dup_num = num;
                return true;
            } else hashTable.insert(num);
        }
        return false;
    }

//利用元素和下标的特性 (方法不好)
    bool duplicationInArray_2(vector<int>& nums, int& dup_num){
        if(nums.empty())   return false;

        for(int i=0; i<nums.size(); i++){  //排除负数
            if(nums[i] < 0) return false;

            while (nums[i] != i){
                if(nums[i] == nums[nums[i]])
                {
                    dup_num = nums[i];
                    return  true;
                }
//            if(nums[i] < nums.size()-1)
            {
                int temp = nums[i];
                nums[i] = nums[temp]; //小心数组越界
                nums[temp] = temp;
             }
            }
        }
        return false;
    }


};


int main()
{
    //输入
    vector<int> inputNums{100,2,3,2,4,5};
    Solution solution;

    int duplication_num = 0;
    bool flag = false;
    flag = solution.duplicationInArray_1(inputNums,duplication_num);
//    flag = solution.duplicationInArray_2(inputNums,duplication_num);
    if(flag)
        cout << "the duplication number is: " << duplication_num <<endl;

    for(int i=)

    return 0;
}





/* *********************************************
 * 测试用例：
 * [-1,-2,-3,-4,-5]  -8  ==>  [2,4]
 *
 * *********************************************
 */