

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <set>
using namespace std;


// 指定切分符 ',' or ' ' .....
void split(std::string& input_str, vector<string>& output_list) {
  std::istringstream tmp_stream(input_str);
  std::string tmp_str;
  while (getline(tmp_stream, tmp_str, ',')) {
    output_list.push_back(tmp_str);
  }
}

int main()
{
  std::string s1;
  std::cin >> s1;

  std::string s2;
  std::cin >> s2;

  vector<std::string> list1;
  vector<std::string> list2;
  split(s1,list1);
  split(s2,list2);

  cout << "list1.size: " << list1.size() << endl;
  cout << "list2.size: " << list2.size() << endl;

}
// weather,joke,music,stock,joke,news,taxi,temperature,pm2.5
// joke,music,news,stock,joke,joke,news,taxi