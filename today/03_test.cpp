#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



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
    for(int j=0; j<nums-1; j++)
    {
      int a,b;
      cin >> a >> b;
      temp.push_back(make_pair(a,b));
    }
    cout << "niuniu" << endl;
//    cout << "niumei" << endl;
//    input.push_back(temp);
  }

//  cout << "input size: " << input.size() << endl;
//  cout << "nums.size: " << input[0].size() << endl;

}

