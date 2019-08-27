//
// Created by LAB540 on 2019/8/23.
//

/*
### 生兔子， 成熟的兔子一年生一个兔子，3年兔子才能成熟
 n年后总共有多少只兔子
 */

#include <iostream>

using namespace std;

// 递归的方式
int generate(int num)
{
  if(num<1)
    return 0;
  if(num==1 || num==2 || num==3)
    return  num;

    return generate(num-1)+generate(num-3);
}

// 迭代的方式
int generate_1(int num)
{
  if(num==1 || num==2 || num==3)
    return  num;

  int prepre = 1;
  int pre = 2;
  int res = 3;
  int temp1 = 0;
  int temp2 = 0;
  for(int i=4; i<=num; i++)
  {
    temp1 = pre;
    temp2 = res;
    res += prepre;
    prepre = temp1;
    pre = temp2;
  }
    return res;
}


int main()
{
  int n = 10;
  int result = generate(n);
  int result_1 = generate_1(n);

  cout << "the result: " << result << endl;
  cout << "the result_1: " << result_1 << endl;
}

