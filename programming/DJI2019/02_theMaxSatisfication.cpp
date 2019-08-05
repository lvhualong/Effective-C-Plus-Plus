//
// Created by LAB540 on 2019/8/4.
//


/*
 * 题目说明：
 * 零食柜里有各种零食
 * 每种零食标有价格、满足感、以及数量
 * 给定一定数量money, 怎么买能获得最大的满足感
 *
 * 比如输入
 * 3 100  3种零食，100元钱
 * 26 100 4   每种零食的价格，满足感以及数量
 * 5 1 2
 * 5 2 2
 *
 * 输出 306
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//bool mycomp(pair<int , pair<int, int>>& p1, pair<int , pair<int, int>>& p2)
//{
//    return  (double)p1.first/p1.second.first > (double)p2.first/p2.second.first;
//}

struct mycomp {
  bool operator()(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) const {
    return (double) p1.first / p1.second.first > (double) p2.first / p2.second.first;;
  }
};

int MaxSatify(vector<pair<int, pair<int, int>>> &objects, int &money) {
  int result = 0;
  sort(objects.begin(), objects.end(), mycomp());

  if (money < objects[0].second.first)
    return 0;

  for (auto object: objects) {
    while (object.second.second > 0 && money > object.second.first) {
      money = money - object.second.first;
      object.second.second--;
      result += (int) object.first;
    }
    if (money < objects.back().second.first)
      return result;
  }
  return result;
}

int main() {
  vector<pair<int, pair<int, int>>> objects;
  int numbers;
  int money;

  while (cin >> numbers >> money) {
    for (int i = 0; i < numbers; i++) {
      int a, b, c;
      double d;
      cin >> a >> b >> c;
      pair<int, pair<int, int>> temp;
      temp = make_pair(b, make_pair(a, c));
      objects.push_back(temp);
    }
    cout << MaxSatify(objects, money);
  }
  return 0;
}


/*
 * 设计思路：
 * 每一个零食组成一个pair,
 * 然后按照 单位满足感排序 满足感/价格
 * 然后按照递减序 依次花光money
 * 测试用例
2 10
1 1 1
1 1 1
输出 2

3 100
26 100 4
5 1 4
5 2 2

输出306
 *
 */
