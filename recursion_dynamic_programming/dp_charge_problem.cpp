//
// Created by LAB540 on 2019/8/23.
//

#include <iostream>
#include <cstdio>
#include <vector>
using  namespace std;

//输入各种零钱的面值，钱的数目
// 输出找零的最小个数
/*
 *
 * 测试用例：
 * 1,5,10,50 零钱面值
 * 100 money
 *
 * 输出 2 两张50的就可以
 */

/*
 *  动态规划求解思路：
 *  把原问题分解为若干个子问题，子问题和原问题形式相同或者类似，只不过规模变小了，子问题都解决了，原问题即解决。
 *  子问题的解一旦求出，便将其保存，所有每个子问题只需要求解一次。
 */

int charge_problem(const vector<int>& coins, int amount)
{
  vector<int> dp(amount+1);
  for(auto& dpi:dp )
    dpi = amount+1;

  dp[0] = 0; //注意动态规划的入口

  for(int i=1; i<=amount; i++)
  {
    for(int j=0; j<coins.size(); j++)
    {
      if(i >= coins[j])
        dp[i] = min(dp[i], dp[i-coins[j]] + 1); //转态转移方程
    }
  }

  if(dp[amount] <= amount)
    return dp[amount];
  else
    return -1;
}





 int coinChange(vector<int>& coins, int amount) {
   if (coins.size() == 0)
   {
     return -1;
   }
   int *dp = new int[amount + 1];

   for (int i = 0; i < amount + 1; i++) {
     dp[i] = amount + 1;//特别注意这里的取值，为什么取这个数，如果是amount，则下面就不能判断了
   }
   dp[0] = 0;

   int size = coins.size();
   for (int i = 0; i < amount + 1; i++)
   {
     for (int j = 0; j < size; j++)
     {
       // i是money  i>=coios[j]说明可以找零了
       if (i >= coins[j]) //dp[i]表示用前j个硬币和为i的最小组合数
         dp[i] = min(dp[i], dp[i - coins[j]] + 1);
     }
   }

   if (dp[amount] <= amount)
     return dp[amount];

   else
     return -1;
 }



int main()
{
  int money = 5;
  vector<int> small_money{1,2,3};

  int result = coinChange(small_money, money);
  int result_1 = charge_problem(small_money, money);

  cout << "the sorts of charge: " << result << endl;
  cout << "the sorts of charge: " << result_1 << endl;
}