
/*
 * 给定一个未排序的数组，找出其中最长等差序列
 *
 * 输入：
 * 5  长度
 * 1 4 2 5 3
 *
 * 输出 5
 */

/*
 * 使用动态规划的思想求解
 *  f [i] [j] 表示以 i 为结尾的某子序列（该子序列的等差为 j )的最大长度
 *  f [i] [j] =  f [i-1] [ Num[i] - Num[j] ] +1 表示等式的状态转移方程
 */

#include <vector>
#include <algorithm>
#include <iostream>

using  namespace std;


const int MAX=1010;
int dp[MAX][MAX];
int longestSubSeq(vector<int> nums)
{
  int size = nums.size();
  if (size <= 1) return size;

  sort(nums.begin(),nums.end()); //排序

  int ans=1;
  for(int i=0;i<MAX;i++)
    for(int j=0;j<MAX;j++)
      dp[i][j]=1; //单独成列

  for(int i=1;i<size;i++)
  {
    for(int j=i-1;j>=0;j--)
    {
      int diff = nums[i]-nums[j];
      dp[i][diff]=dp[j][diff]+1;
      ans=max(ans, dp[i][diff]);
    }
  }
  return ans;
}

int main()
{
  int n;
  vector<int> nums;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    int temp; cin >> temp;
    nums.push_back(temp);
  }

  cout << longestSubSeq(nums);

  return 0;
}

