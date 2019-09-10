//
// Created by hualong on 2019/4/27.
//



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    //能得到最大的子数组之和，没有子数组 O(n)复杂度
    // 贪心的策略
    int getGreastSumOfSubArray(vector<int> nums){

        int greastSum = INT16_MIN;
        int tempSum = 0;
        for(int i=0; i<nums.size(); ++i)
        {
            if(tempSum < 0)
                tempSum = nums[i];
            else
                tempSum += nums[i];
            if(tempSum > greastSum)
                greastSum = tempSum;
        }
        return greastSum;
    }

     // 动态规划的思路： 状态方程 dp[ i ]  = max( dp[ i -1 ] ) + arr[ i-1 ] , arr[ i-1 ] )
    int getGreastSumOfSubArray_dp(const vector<int>& nums)
    {
      if(nums.empty())
        return -1;

      int size = nums.size();
      vector<int> dp(size+1);
      for(auto& dpi:dp)
        dpi = 0;

        int MAX = INT32_MIN;

        dp[1] = nums[0];
      for(int i=1; i<=size; i++)
      {
        dp[i] = max(nums[i-1], dp[i-1]+nums[i-1]);

        if(dp[i] > MAX)
          MAX = dp[i];
      }

      return MAX;
    }



    int getGreastSumOfSubArray_Dynamic(vector<int>& nums)
    {
        if(nums.size() < 1) return 0;

        int Sum = nums.front();
        int Max = nums.front();

        for(auto num:nums) {
            Sum = max(Sum + num, num);

            if(Sum > Max)
                Max = Sum;
        }
        return  Max;
    }
};

int main()
{
    Solution solution;
    vector<int> numbers{1,-2,3,10,-4,7,2,-5};
//    int greastSumOfSubArray = solution.getGreastSumOfSubArray(numbers);
    int greastSumOfSubArray = solution.getGreastSumOfSubArray_Dynamic(numbers);
    int result = solution.getGreastSumOfSubArray_dp(numbers);

    cout << "the GreastSumOfSubArray: " << greastSumOfSubArray << endl;
    cout << "the GreastSumOfSubArray: " << result << endl;
}

/*
 * 测试用例：
 * {1,-2,3,10,-4,7,2,-5}
 * 最大子数组 3 10 -4 7 2  sum=18
 */