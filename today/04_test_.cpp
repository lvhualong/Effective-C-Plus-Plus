#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
void split(const string &s, vector<int> &sv, const char flag = ' ') {
  sv.clear();
  istringstream iss(s);
  string temp;

  while (getline(iss, temp, flag)) {
    sv.push_back(stoi(temp));
  }
}

int cal_min_step(vector<int> &nums) {
  int max_first_step = nums.size() / 2;
  int min_step = INT32_MAX;
  for (int i = 1; i < max_first_step; ++i) {
    int reach = i;
    int step = 1;
    while (reach < nums.size()) {
      reach = reach + nums[reach];
      step++;
      if (reach == nums.size() - 1) {
        min_step = min(step, min_step);
        break;
      }
    }
  }
  return min_step;
}

int main() {
//  string nu = "7 5 9 4 2 6 8 3 5 4 3 9";
//  stringstream ss(nu);
//  cin.rdbuf(ss.rdbuf());
  string str;
  getline(cin, str);
  vector<int> nums;
  split(str, nums, ' ');
  int res = cal_min_step(nums);
  cout << res << endl;
  return 0;
}