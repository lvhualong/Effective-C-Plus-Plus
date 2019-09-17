#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool  comp(pair<int, int> a, pair<int, int> b)
{
  return (a.second - a.first) > (b.second - b.first);
}

void resutl(vector<pair<int, int>>& nums)
{
  sort(nums.begin(), nums.end(), comp);
  int add_time = 0;
  for(auto num:nums)
  {
    if(num.first > num.second+add_time) {
      cout << "No" << endl;
      return;
    } else {
      add_time = add_time + num.second - num.first;
    }
  }
  cout << "Yes" << endl;
  return;
}

int main()
{

  int test_num;
  int nums;
  vector<vector<pair<int, int>>> input;

  cin >> test_num;
//  input.resize(test_num);
  vector<pair<int, int>> temp;
  for(int i=0; i< test_num; i++)
  {
    cin >> nums;
//    input[i].resize(nums);
    for(int j=0; j<nums; j++)
    {
      int a,b;
      cin >> a >> b;
      temp.push_back(make_pair(a,b));
    }
    resutl(temp);
//    input.push_back(temp);
  }

//  cout << "input size: " << input.size() << endl;
//  cout << "nums.size: " << input[0].size() << endl;

}

