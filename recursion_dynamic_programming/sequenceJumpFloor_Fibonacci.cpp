//
// Created by LAB540 on 2019/8/23.
//

/*
 * part1: 有n个台阶，每次可以跳1步或者两步，问总有多少种走法
 *
 * part2: 有n个台阶，每次可以跳1步、2步……n步，问总有多少种走法
 */

#include <iostream>

using namespace std;

// 递归的方式
int jumpFloor_1(int num)
{
  if(num<1)
    return 0;
  if(num == 1)
    return 1;
  if(num == 2)
    return 2;

    return jumpFloor_1(num-1)+jumpFloor_1(num-2);
}

// 迭代的方式
int jumpFloor_2(int num)
{
  if(num<1)
    return 0;
  if(num == 1)
    return 1;
  if(num == 2)
    return 2;

  int pre = 1;
  int res = 2;
  int tem = 0;
  for(int i=3; i<=num; i++)
  {
    tem = res;
    res = tem+pre;
    pre = tem;
  }
    return res;
}

int jumpFloor_mulit(int num)
{
  if(num == 1)
    return 1;
  return jumpFloor_mulit(num-1)*2;
}

int main()
{
  int n = 10;
  int result = jumpFloor_1(n);
  int result_1 = jumpFloor_2(n);
  int result_2 = jumpFloor_mulit(n);

  cout << "the result: " << result << endl;
  cout << "the result_1: " << result_1 << endl;
  cout << "the result_2: " << result_2 << endl;
}

