

/*
 * 输入两个子串； s1 s2
 * 定义子序列，从最初序列在不改变顺序的时候，去掉某些元素，形成新序列
 * 请判断 s2是否为S1的子序列
 */


#include <string>
#include <iostream>
using  namespace std;

int result(string s1, string s2)
{
  if(s1.length() < s2.length())
    return 0;

  int pos_prev = -1;
  for(int i=0; i<s2.length(); i++)
  {
    int pos = s1.find(s2[i]);
    cout << "pose:" << pos << endl;
    if(pos != -1 && pos > pos_prev) {
      pos_prev = pos;
      s1.replace(pos, 1, " "); //找到之后换成
      cout << s1 << endl;
    }
    else
      return 0;
  }
  return true;

}

int main()
{
  string s1{"abcdefa"};
  string s2{"aba"};

  cout << result(s1, s2);
}