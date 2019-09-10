//
// Created by hualong on 2019/4/27.
//

/*
 * 求一个数组 最长升序子序列
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
  int getGreastSumOfSubArray_dp(const vector<int>& nums)
  {
    if(nums.empty())
      return 0;

    int max_count = 1;
    bool flag = false;
    int temp_count = 1;
  for(int i=0; i<nums.size()-1; i++)
  {

    if(nums[i] < nums[i+1])
    {
      flag = true;
      temp_count++;
    }
    else {
      flag = false;
      temp_count = 1;
    }
    if(flag && temp_count>max_count)
      max_count = temp_count;
  }
    return  max_count;
  }




};

int main()
{
  Solution solution;
  vector<int> numbers{5,1,2,3,4,2,3};
  int result = solution.getGreastSumOfSubArray_dp(numbers);


  cout << "the GreastSumOfSubArray: " << result << endl;
}
