//
// Created by LAB540 on 2019/8/27.
//


/*
 * 问题描述：
 *
 * 一个矩形区域被划分为N*M个小矩形格子，在格子(i,j)中有A[i][j]个苹果。
 * 现在从左上角的格子(1,1)出发，要求每次只能向右走一步或向下走一步，最后到达(N,M)，
 * 每经过一个格子就把其中的苹果全部拿走。请找出能拿到最多苹果数的路线。
 */

/*
 *  动态规划问题：
 *  dp[i][j] = max{dp[i-1][j], dp[i][j-1]}+a[i][j]
 *
 *  注意格子是从1,1开始，所以我们把dp的第一行和第一列 补了一圈0，
 *  测试用例：
0 1 2 3
4 5 6 7
8 9 10 11
12 13 14 15
the resutl: 66
 *
 */


#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


int main()
{
  int N = 4, M=4;
//  cin >> N >>M;

  vector<vector<int>> vector_2d;

  vector<vector<int>>* input = new  vector<vector<int>>;
  input->resize(N); //行

  //输入
  for(int i=0; i<N; i++)
  {
    (*input)[i].resize(M);
    for(int j=0; j<M; j++){
      (*input)[i][j]= i*N+j;
      cout << (*input)[i][j] << " ";
    }
    cout << endl;
  }

  //动态规划
  vector<vector<int>>* dp = new  vector<vector<int>>;
  (*dp).resize(N+1);
  for(int i=0; i<N+1; i++) {
      (*dp)[i].resize(M+1);
  }

  //第一圈附初始值
  for(int i=0; i<M+1; i++)
    (*dp)[0][i]  = 0;
  for(int j=0; j<N; j++)
    (*dp)[j][0]  = 0;

  for(int i=1; i<N+1; i++)
    for(int j=1; j<M+1; j++)
    {
      (*dp)[i][j] = max((*dp)[i-1][j], (*dp)[i][j-1]) + (*input)[i-1][j-1];
    }

   cout << "the resutl: " << (*dp)[N][M];

}