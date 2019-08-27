
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

#include<stdio.h>
using namespace std;

/*
 * 输入一行单词组成的字符串，将每个单词按照逆序数进行排序
 *
 * 测试用例：
 * 输入：waimai,dache,lvyou,liren,meishi,jiehun,lvyoujingdian,jiaopei,menpiao,jiudian
 * 输出：waimai,menpiao,meishi,lvyoujingdian,lvyou,liren,jiudian,jiehun,jiaopei,dache
 *
 */

//以
void split_str(string& input, vector<string>& strs, char flag)
{
  istringstream ss(input);
  string temp_str;
  while(getline(ss, temp_str, flag))
  {
    strs.push_back(temp_str);
  }
  cout << strs.size();
}


bool comp(string a, string b)
{
  return  a>b;
}
int main()
{
  string  inputString= "ab,abc,lvyou,liren,meishi,jiehun,lvyoujingdian,jiaopei,menpiao,jiudian";
//   cin >> inputString;
  vector<string> strs;

  //
  split_str(inputString, strs, ',');


  sort(strs.begin(),strs.end(), comp);
  for(int i=0; i<strs.size()-1; i++ )
    cout <<strs[i] << "," ;

  cout << *(strs.end()-1) << endl;

  return 0;
}

