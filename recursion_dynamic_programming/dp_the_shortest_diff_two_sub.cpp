

/*
 * 给定一个数组，将这个数组划分成两个部分， 使得两个子数组的和的差最小，
 *
 * 例如 {2,4,5,6,7},得出的两组数：{2，4，6}和{5，7} 差为0
 * {2，5，6，10} 子数组为：{2,10}和{5,6}， 差为1
 */

/*
 * 解题思路：
 * 很容易知道如果选取的某个子数组的和currentSum=sum/2，则这两个子数组的和的差值最小；
 * 即从数组中选取某些数字使得其和接近整个数组的1/2.
 * 所以该命题本质上是一个01背包命题，原命题等价于从n个物品中选取若干个，其重量不超过sum/2，且重量达到最大
 *
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int M = 100;
int w[M];
int currentSum[M*M];
bool state[M][M];
int main()
{
  int n;
//  while (scanf("%d ", &n) != EOF) {//输入数组元素个数
  cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &w[i]);
      sum += w[i];//sum存储整个数组元素的和
    }
    memset(currentSum, 0, sizeof(currentSum));
    memset(state, 0, sizeof(state));

    for (int i = 0; i < n; ++i)
      for (int j = sum/2; j >= w[i]; --j) {
        if (currentSum[j] < currentSum[j-w[i]] + w[i]) {
          currentSum[j] =currentSum[j-w[i]] + w[i];
          state[i][j] = true;
        }
      }
    //输出差
    printf("%d\n", sum - currentSum[sum/2]*2);

      //输出子数组
//    int i = n, j = sum/2;
//    while (i--) {
//      if (state[i][j]) {
//        printf("%d ", w[i]);
//        j -= w[i];
//      }
//    }
//    printf("\n");
//  }
  return 0;
}