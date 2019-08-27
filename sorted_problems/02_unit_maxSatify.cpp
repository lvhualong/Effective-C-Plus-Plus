
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * 零食柜问题
 * 每一种零食有 数量、价格、满足度三种属性
 * 用一定的钱，怎么买获得最大的满足感
 */

//比较单位价格的满足感
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
 *
 * 两种零食，总共有10元钱
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
