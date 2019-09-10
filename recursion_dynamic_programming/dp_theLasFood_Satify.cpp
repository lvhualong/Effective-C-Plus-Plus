//
// Created by LAB540 on 2019/8/27.
//

/*
 * 问题描述：
 * 有一个零食柜有n件零食，其中第i件值vi元，能获得的满足度为 Si, 供应的数量为Ni
 * 现在您有现金 M元，问怎么消费才能获得最大的满足感。
 *
 *

 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using  namespace std;

struct item
{
  int max_satisfy;
  vector<int> value;
  vector<int> nums;
};

int package_dp(vector<int>& value, vector<int>& satisfy, vector<int>& nums, int total) {

  vector<item> dp(total+1); //set size, total的长度
  int size = value.size();
  for(auto& dpi:dp) //注意引用符号！！！
  {
    dpi.value.resize(size); //每一项又有 weight个元素,多一位存储最大值
    dpi.nums.resize(size);
  }

  cout << "init: " << "size: " << dp.size() << " every one: " << dp[0].nums.size() << endl;
  for(int i=0; i<=value.size(); i++)
  {
    dp[0].value[i] = 0; //第一行初始化
  }
  dp[0].max_satisfy = 0;
  dp[0].nums = nums;


  for(int i=1; i<=total; i++){
    for(int j=0; j<size; j++)
    {

      if(i >= value[j] ) {
//        cout << "i: " << i << " j:" <<j <<" dp[i-1].nums[j]: " << dp[i-1].nums[j] << endl;
        dp[i].max_satisfy = max(dp[i].max_satisfy, dp[i - value[j]].max_satisfy + satisfy[j]);
        dp[i].value[j] = dp[i].max_satisfy;


//        cout << "i: " << i << " j "<< j << " result: " << dp[i][max_n] << endl;
      } else{
        if(j==0){
          dp[i].value[j] = dp[i-1].max_satisfy;
          dp[i].max_satisfy = dp[i].value[j];
        }
        else
          dp[i].value[j] = dp[i].max_satisfy;
      }
    }
    dp[i].nums = dp[i-1].nums;
  }

  return dp[total].max_satisfy;
}


int main() {
  vector<int> V{10,25,40,50,60};
  vector<int> S{10,30,39,40,50};
  vector<int> N{10, 2, 3, 3, 3};
    int total = 120;
    int reslut = package_dp(V, S, N, total);
    cout << "the resutl: "<< reslut << endl;
//    package_dp(v,w,sizeof(v)/sizeof(int)-1,total);
    return 0;
}