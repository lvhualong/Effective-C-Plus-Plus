//
// Created by LAB540 on 2019/8/27.
//

/*
 * 问题描述：
 * 一个贼在偷窃一家商店时发现了n件物品，其中第i件值vi元，重wi磅。
 * 他希望偷走的东西总和越值钱越好，但是他的背包只能放下W磅。
 * 请求解如何放能偷走最大价值的物品，这里vi、wi、W都是整数
 *
 * 采用动态规划 dp长度设置为背包能装的最大重量
 * dp[i] = max(dp[i], dp[i-weight[j]]+value[j]);
 *
 *  但是要注意一些问题，比如每一个dp[i]都要遍历 每一个背包，所以最好设置一个二维dp
 *  dp[i][j] 存储遍历到total=i weight[i]的最优解
 *  dp[i][max_n] 存当前 total=i 的最优解
 *
 *   dp[i][max_n] = max(dp[i][max_n], dp[i - w[j]][max_n] + v[j]);
     dp[i][j] = dp[i][max_n];

*
 * 如果采用贪心算法来解
 * 每次找性价比最高的， 所以计算单位重量的价值 value/weight 然后排序， 从性价比高到底装
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int package_dp(vector<int>& v, vector<int>& w, int total) {
  vector<vector<int>> dp(total+1); //set size, total的长度
  int max_n = w.size();
  for(auto& dpi:dp) //注意引用符号！！！
    dpi.resize(max_n+1); //每一项又有 weight个元素,多一位存储最大值

   cout << "init: " << "size: " << dp.size() << " every one: " << dp[0].size() << endl;
  for(int i=0; i<=w.size(); i++)
  {
    dp[0][i] = 0; //第一行初始化
  }

  for(int i=1; i<=total; i++){
    for(int j=0; j<w.size(); j++)
    {
      if(i >= w[j]) {
        dp[i][max_n] = max(dp[i][max_n], dp[i - w[j]][max_n] + v[j]);
        dp[i][j] = dp[i][max_n];
//        cout << "i: " << i << " j "<< j << " result: " << dp[i][max_n] << endl;
      } else{
        if(j==0){
          dp[i][j] = dp[i-1][max_n];
          dp[i][max_n] = dp[i][j];
        }
        else
          dp[i][j] = dp[i][max_n];
      }
    }
  }

  return dp[total][max_n];
}

bool comp(pair<int,int> a, pair<int,int> b)
{
  return a.first/(float)a.second > b.first/(float)b.second;
}

//贪心算法有时有点问题，有时求得并不是最优解
int package_greedy(vector<pair<int,int>> &items, int total)
{
    sort(items.begin(), items.end(), comp);
    int result = 0;
    for(int i=0; i<items.size(); i++)
    {
      while(total >= items[i].second)
      {
        result += items[i].first;
        total -= items[i].second;
        cout << "item_i: " << items[i].first << " result: " << result << " total: " << endl;
      }
    }
  return result;
}

int main() {
  vector<int> value{15,25,40,20,9};
  vector<int> weight{30,50,70,40,20};

  vector<pair<int,int>> items;
  for(int i=0; i<value.size(); i++)
  {
    items.push_back(make_pair(value[i], weight[i]));
  }
  int total = 120;
  int result_dp = package_dp(value, weight, total);
  int result_gp = package_greedy(items, total);
  cout << "the dynamic programming result is: " << result_dp << endl;
  cout << "the greedy programming result is: " << result_gp << endl;
  return 0;
}

/*
 * 测试用例：
 *vector<int> value{15,25,40,20,9};
  vector<int> weight{30,50,70,40,20};
 */