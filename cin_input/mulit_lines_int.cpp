

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <set>
using namespace std;


// 指定切分符 ',' or ' ' .....
void split(std::string& input_str, vector<int>& output_list) {
  std::istringstream tmp_stream(input_str);
  string tmp_str;
  while (getline(tmp_stream, tmp_str, ' ')) {
    output_list.push_back(stoi(tmp_str));
  }
}

int main()
{
  std::string s1;
//  std::cin >> s1;
  getline(cin, s1);
//  cin.get(); //read 回车

  std::string s2;
//  std::cin >> s2;
  getline(cin, s2);

  vector<int> list1;
  vector<int> list2;
  split(s1,list1);
  split(s2,list2);

  cout << "list1.size: " << list1.size() << " first value: "<< list1.front() << endl;
  cout << "list2.size: " << list2.size() << " first value: "<< list2.front() << endl;


}
// 1, 2, 3,4,5
// 11,22,33 ,44, 55,66,77

// 1 2 3 4 5
// 11 22 33 44 55 66 77