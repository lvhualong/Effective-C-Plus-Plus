//
// Created by hualong on 3/4/19.
//

#include <iostream>
#include <vector>

class Solution{
public:
    // 二分查找
    int binSearch(const std::vector<int>& nums, int target){
        int first = 0, last = nums.size();
        while(first <= last)
        {
            int mid = (first + last)/2;

            if(nums[mid] == target)
                return  mid;

            if(target <= nums[mid])
                last = mid -1 ;
            else first = mid +1;
        }
        return -1;
    }


    //对排好序的数组，旋转，旋转数组查找    0 1 2 4 5 6 7 might become 4 5 6 7，8,9,10 0 1 2)
    int search(const std::vector<int>& nums, int target){
        int first = 0, last =  nums.size();
        while(first != last)
        {
            const int mid = first + (last - first)/2; //折半
            if(nums[mid] == target)
                return mid;
            //
            if(nums[first] <=  nums[mid])
            {
                if(nums[first] <= target && target <= nums[mid])
                    last = mid;
                else first = mid+1;
            }

            else
            {
                if(nums[mid] <= target && target <= nums[last])
                    first = mid + 1;
                else last = mid;
            }
        }
        return -1;
    }
};

int main()
{
    //std::vector<int> inputArray = {4, 5, 6, 7,8,9,10,0,1,2};
    std::vector<int> inputArray = {1,2,3,4,5,6,7,8,9,10};
    int target = 5;//待查找目标

    std::cout << "InputArray is :" << std::endl;
    for(int i=0; i<inputArray.size(); i++)
    {
        std::cout << inputArray[i] << " " ;
    }
    std::cout << std::endl;

    Solution solution;

    int index = solution.binSearch(inputArray, target);

    std::cout << "serch " << target << "  index is " << index <<std::endl;

    return 0;


}