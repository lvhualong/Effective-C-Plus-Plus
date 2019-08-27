
#include <vector>
#include <iostream>

#include <unordered_set>
#include <map>

/*
 *  在一个考场上，
 *  有n个男生 编号1~n
 *  有n个女生，编号n+1 ~ 2n
 *
 *  男生可能认识异性女生，女生可能认识异性男生，为了保证考试公平，会把一部分同学移到其他考场中
 *  怎么选择，能够保证移动的人数最少，而且编号尽可能小
 *
 *  测试用例：
 *  输入：
 *  2 2   n m 有2个男生两个女生， 有两组朋友关系
 *  1 3   1号男生认识3号女生
 *  1 4   1号男生认识4号女生
 *  输出
 *  1     移动1位同学
 *  1     编号为1
 *
 */

using namespace std;

void remove_stuents(map<int, vector<int>> &boy_friends, map<int, vector<int>> &girl_friends,
                    vector<int> &stuends )
{
  pair<int,int> max_boy{pair<int,int>(0,0)};
  pair<int,int> max_girl{pair<int,int>(0,0)};
  for(auto boy:boy_friends)
  {
    int num = boy.second.size();
    if( num > max_boy.second)
    {
      max_boy.first = boy.first;
      max_boy.second = num;
    }
  }
  cout << "max boy:" << max_boy.first << " " << max_boy.second << endl;
  for(auto girl:girl_friends)
  {
    int num = girl.second.size();
    if(num > max_girl.second)
    {
      max_girl.first = girl.first;
      max_girl.second = num;
    }
  }
cout << "max girl :" << max_girl.first << " " << max_girl.second << endl;
  //递归终止条件
  if(max_boy.second == 0 || max_girl.second ==0)
    return;
  else
  {
    if(max_boy.second >= max_girl.second)
    {
      stuends.push_back(max_boy.first);
      for(int i=0; i<max_boy.second; i++) {
        girl_friends.erase((boy_friends[max_boy.first])[i]);
      }
      boy_friends.erase(max_boy.first);
    }
    else
    {
      stuends.push_back(max_girl.first);
      for(int j=0; j<max_girl.second; j++){
        boy_friends.erase((girl_friends[max_girl.first])[j]);
      }
      girl_friends.erase(max_girl.first);
    }
  }
  //递归
  remove_stuents(boy_friends, girl_friends, stuends);
}


int main()
{

  map<int, vector<int>> boy_friends;
  map<int, vector<int>> girl_friends;
  vector<int> stuends;

  int personal;
  int nums;
  cin >> personal >> nums;
  for(int i=0; i<nums; i++)
  {
    int temp_a, temp_b, temp;
    cin >> temp_a >> temp_b;
    if (temp_a > temp_b)
    {
      temp = temp_a;
      temp_a = temp_b;
      temp_b = temp;
    }
    boy_friends[temp_a].push_back(temp_b);
    girl_friends[temp_b].push_back(temp_a);
  }

  remove_stuents(boy_friends,girl_friends, stuends);

//  cout << "boy friend size: " << boy_friends.size() << endl;
//  cout << "girl friend size: " << girl_friends.size() << endl;

  cout << stuends.size() << endl;
  for(auto num:stuends)
    cout << num << endl;

  return 0;

}

/*
 * 设计思路：
 * 同步设置两个map 一个存每个男生认识的女生，一个存每个女生认识的男生，key为自己的id  value为 认识同学的id
 *
 * 然后找到认识朋友最多的那个同学，记录他，并且remove掉
 * 注意remove的时候，要同时删除两个map中的
 *
 */

/*
 * 测试用例：
 *
 * 输入：
 * 2 2
 * 1 3
 * 1 4
 *
 * 输出：
 * 1
 * 1
 *
 * 输入
 * 4 4
 * 1 5
 * 2 6
 * 2 7
 * 4 5
 * 输出
 * 2
 * 2
 * 5
 *
 * 输入：
 * 4 4
 * 1 5
 * 2 6
 * 2 7
 * 4 8
 * 输出
 * 3
 * 2
 * 1
 * 4
 *
 */