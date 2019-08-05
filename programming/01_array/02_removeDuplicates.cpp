//
// Created by hualong on 2019/4/1.
//
#include <iostream>
#include <vector>
using namespace std;
/*
 * ************************************************
> 给定一个排序数组，你需要在原地删除重复出现的元素，
使得每个元素只出现一次，返回移除后数组的新长度。

 * @ 给定 nums = [0,0,1,1,1,2,2,3,3,4],
 * @ 返回值：5   新数组为 0, 1, 2, 3, 4
 * ************************************************
 */
class Solution {
public:
// 方法描述：判断相邻元素
    int removeDuplicates_1(vector<int>& nums)
    {
        int index = 1;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] != nums[i+1])
                nums[index++] = nums[i+1];
        }

        // 后面要截断
        for(int i=0; i<index; i++)
            nums.pop_back();
        return  index;
    }
    //比上面一种方法好，可以=删除连续相同的元素，因为vector的动态特性不好，这样效率更高
    int removeDuplicates_2(vector<int>& nums)
    {
        int index = 0;
        if(nums.size() <=1) return nums.size();//防止下面数组越界

        for(int i=1; i<nums.size(); i++)
        {
            if(nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        for(int i=0; i<index+1; i++)
            nums.pop_back();
        return index+1;
    }


};


int main()
{
    //输入
    vector<int> inputNums{0,0,1,1,1,2,2,3,3,4};
    for(auto num:inputNums)
        cout << num << " ";
    cout << endl;

    Solution solution;
//    int size  =  solution.removeDuplicates_1(inputNums);
    int size  =  solution.removeDuplicates_2(inputNums);

    cout << "the New size: " << size << endl;
    for(auto num:inputNums)
        cout << num << " ";
    cout << endl;


    return 0;
}





/* *********************************************
 * 测试用例：
 * [0,0,1,1,1,2,2,3,3,4]    ==>  5   并且新数组 0, 1, 2, 3, 4
 *
 * *********************************************
 */