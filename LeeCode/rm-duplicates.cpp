//
// Created by hualong on 3/5/19.
//

#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:

    int removeDuplicates1(std::vector<int>&  nums){
        if (nums.empty())  return 0;

        int index = 0;
        //判断连续两个元素是否相等
        for(int i=1; i < nums.size(); i++) {
            if (nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        return  index + 1;

    }

    int removeDuplicates2(std::vector<int>& nums){
        //unique 消除相邻的相同元素  distance求迭代器的长度
        return std::distance(nums.begin(), std::unique(nums.begin(), nums.end()));
    }

    //对于排好序的数组，允许有两个元素的重复
    int removeDuplicates3(std::vector<int>& nums)
    {
        if(nums.size() <= 2)  return nums.size();

        int index = 2;
        for(int i = 2; i< nums.size(); i++){
            if(nums[i] != nums[index-2] )
                nums[index++] = nums[i];
        }
        return index;
    }

};



int main()
{
    std::vector<int> inputArray  = {1,2,2,2,2,3,4,4,4 ,5}; //测试输入
    //输入数据
//    int number, elements; //总数与元素
//    std::cin >> number;
//    {
//        for(int i=0; i < number; ++i)
//            std::cin >> elements;
//            inputArray.push_back(elements);
//    }
//    std::cout << "inputArray size :" << inputArray.size() << std::endl;

    int length;
    Solution solution;
    length =  solution.removeDuplicates3(inputArray);
    std::cout << "length2 = " << length << std::endl;

    return 0;
}