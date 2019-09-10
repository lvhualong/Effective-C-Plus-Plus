//
// Created by LAB540 on 2019/9/7.
//


/*
 *
 * 问题描述：
 * 一个贼在偷窃一家商店时发现了n件物品，其中第i件值vi元，重wi磅。
 * 他希望偷走的东西总和越值钱越好，但是他的背包只能放下W磅。
 * 请求解如何放能偷走最大价值的物品，这里vi、wi、W都是整数
 *
 * 之前分析了 采用动态规划的思想来解决问题
 *
 * 现在换一个思路，采用回溯法来解决问题
 *
 */



/*

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

#include <iostream>
#include <stdio.h>
//#include <conio.h>
using namespace std;
int n;//物品数量
double c;//背包容量
double v[100];//各个物品的价值　value
double w[100];//各个物品的重量　weight
double cw = 0.0;//当前背包重量　current weight
double cp = 0.0;//当前背包中物品总价值　current value
double bestp = 0.0;//当前最优价值best price
double perp[100];//单位物品价值(排序后) per price
int order[100];//物品编号
int put[100];//设置是否装入，为1的时候表示选择该组数据装入，为0的表示不选择该组数据


//按单位价值排序
void knapsack()
{
  int i,j;
  int temporder = 0;
  double temp = 0.0;

  for(i=1;i<=n;i++)
    perp[i]=v[i]/w[i]; //计算单位价值（单位重量的物品价值）
  for(i=1;i<=n-1;i++)
  {
    for(j=i+1;j<=n;j++)
      if(perp[i]<perp[j])//冒泡排序perp[],order[],sortv[],sortw[]
      {
        temp = perp[i];  //冒泡对perp[]排序
        perp[i]=perp[i];
        perp[j]=temp;

        temporder=order[i];//冒泡对order[]排序
        order[i]=order[j];
        order[j]=temporder;

        temp = v[i];//冒泡对v[]排序
        v[i]=v[j];
        v[j]=temp;

        temp=w[i];//冒泡对w[]排序
        w[i]=w[j];
        w[j]=temp;
      }
  }
}

//回溯函数
void backtrack(int i)
{   //i用来指示到达的层数（第几步，从0开始），同时也指示当前选择玩了几个物品
  double bound(int i);
  if(i>n) //递归结束的判定条件
  {
    bestp = cp;
    return;
  }
  //如若左子节点可行，则直接搜索左子树;
  //对于右子树，先计算上界函数，以判断是否将其减去
  if(cw+w[i]<=c)//将物品i放入背包,搜索左子树
  {
    cw+=w[i];//同步更新当前背包的重量
    cp+=v[i];//同步更新当前背包的总价值
    put[i]=1;
    backtrack(i+1);//深度搜索进入下一层
    cw-=w[i];//回溯复原
    cp-=v[i];//回溯复原
  }
  if(bound(i+1)>bestp)//如若符合条件则搜索右子树
    backtrack(i+1);
}

//计算上界函数，功能为剪枝
double bound(int i)
{   //判断当前背包的总价值cp＋剩余容量可容纳的最大价值<=当前最优价值
  double leftw= c-cw;//剩余背包容量
  double b = cp;//记录当前背包的总价值cp,最后求上界
  //以物品单位重量价值递减次序装入物品
  while(i<=n && w[i]<=leftw)
  {
    leftw-=w[i];
    b+=v[i];
    i++;
  }
  //装满背包
  if(i<=n)
    b+=v[i]/w[i]*leftw;
  return b;//返回计算出的上界

}



int main()
{
  int i;
  printf("请输入物品的数量和背包的容量：");
  scanf("%d %lf",&n,&c);
  /*printf("请输入物品的重量和价值：\n");
  for(i=1;i<=n;i++)
  {
      printf("第%d个物品的重量：",i);
      scanf("%lf",&w[i]);
      printf("第%d个物品的价值是：",i);
      scanf("%lf",&v[i]);
      order[i]=i;
  }*/
  printf("请依次输入%d个物品的重量:\n",n);
  for(i=1;i<=n;i++){
    scanf("%lf",&w[i]);
    order[i]=i;
  }

  printf("请依次输入%d个物品的价值:\n",n);
  for(i=1;i<=n;i++){
    scanf("%lf",&v[i]);
  }


  knapsack();
  backtrack(1);


  printf("最优价值为：%lf\n",bestp);
  printf("需要装入的物品编号是：");
  for(i=1;i<=n;i++)
  {
    if(put[i]==1)
      printf("%d ",order[i]);
  }
  return 0;
}

/*
 * 测试用例：
 *vector<int> value{15,25,40,20,9};
  vector<int> weight{30,50,70,40,20};
 */