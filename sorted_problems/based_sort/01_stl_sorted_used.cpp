
#include <vector>
#include <algorithm> //include stl sorted
#include <iostream>

using namespace std;

void print_vector(vector<int>& nums)
{
  for(auto num:nums)
    cout << num << " ";
  cout << endl;
}

void print_PairVector(vector<pair<int, int>>& nums)
{
  for(auto num:nums)
    cout << num.first << "," << num.second << "   ";
  cout << endl;
}


//自定义比较模式
bool comp(const int& a, const int& b)
{
//  return  a>b; // decrease
  return  a<b; // increase
}

bool comp_pair(const pair<int, int>& a, const pair<int, int>& b)
{
  return  a.second < b.second; // increase
}



int main() {

  //一维 vector的比较
  vector<int> inputNums{1,5,0,2,2,3,1,2,8,2,7};
  cout << "the input nums: " ;
  print_vector(inputNums);

  // Increasing sorted 默认递增序列
  sort(inputNums.begin(), inputNums.end(),comp);
  cout << "the Increasing sorted nums: ";
  print_vector(inputNums);

  // Decreasing sorted 可以使用反向迭代 或者自定义序列
  sort(inputNums.rbegin(), inputNums.rend());
  cout << "the Decreasing sorted nums: ";
  print_vector(inputNums);

  //二维 pair或者point比较
  vector<pair<int, int>> inputPairNums{make_pair(1,10), make_pair(2,9), make_pair(3,8)};
  cout << "the input pairs vector: ";
  print_PairVector(inputPairNums);

  sort(inputPairNums.begin(), inputPairNums.end());
  cout << "use the pair.first increase sort: ";
  print_PairVector(inputPairNums);

  sort(inputPairNums.begin(), inputPairNums.end(),comp_pair);
  cout << "use the pair.second increase sort: ";
  print_PairVector(inputPairNums);

}