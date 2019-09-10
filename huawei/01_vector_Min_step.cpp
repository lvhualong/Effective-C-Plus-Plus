

/*
 * 数组遍历查找问题：
 * 一个正整形数组，走方格
 * 第一步必须从第一个元素开始， 1<=步长<len/2
 * 第二步开始以所在成员的的数字走相应的步数，
 * 如果目标不可达返回-1，
 *
 * 输出最少的步骤数量
 *
 * 测试用例：
 * 7 5 9 4 2 6 8 3 5 4 3 9
 * 输出 2
 *
 *第一步可选步长为2， 第一个成员7走到第二个成员
 *第二步： 第二个成员值为9，经过9个成员后刚好到达最后。
 *
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>

using namespace std;


// 指定切分符 ',' or ' ' .....
void split(std::string& input_str, vector<int>& output_list) {
  std::istringstream tmp_stream(input_str);
  string tmp_str;
  while (getline(tmp_stream, tmp_str, ' ')) {
    output_list.push_back(stoi(tmp_str));
  }
}

int result(vector<int>& nums)
{
  int min_count = INT16_MAX;
  int len = nums.size();
  if(len < 3)
    return -1;
  int zero_count = 0;
  for(int i=1; i<len/2; i++)
  {
    int lamda;
    int current = 1;
    int index = i;
    while(index < len)
    {
      current++;
      lamda = nums[index];
      index = index + lamda;

      if(index == len -1)
      {
        min_count = min(current, min_count);
        break;
      }
    }
  }
  if(min_count == INT16_MAX)
    return -1;
  return  min_count;
}

int main()
{
  std::string s1;
//  std::cin >> s1;
  getline(cin, s1);
//  cin.get(); //read 回车



  vector<int> list1;
  split(s1,list1);


  cout  << result(list1) << endl;



}
// 7 5 9 4 2 6 8 3 5 4 3 9