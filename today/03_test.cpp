

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <stack>
#include <map>
using namespace std;


// 指定切分符 ',' or ' ' .....
void split(std::string& input_str, vector<string>& left, vector<string>& right) {
  std::istringstream tmp_stream(input_str);
  std::string tmp_str;
  vector<string> output_list ;

  while (getline(tmp_stream, tmp_str, ';')) {
    output_list.push_back(tmp_str);
  }
//  cout<< "output: size: "<< output_list.size() << endl;
  istringstream left_stream(output_list[0]);
  while(getline(left_stream, tmp_str, ','))
    left.push_back(tmp_str);

  istringstream right_stream(output_list[1]);
  while(getline(right_stream, tmp_str, ','))
    right.push_back(tmp_str);

//    cout<< "left size: "<< left.size()  << "right "<< right.size()<< endl;
}

map<string, int> element(vector<string> strs)
{
  map<string, int> temp;
  for(auto str:strs) {
    int pos_l = str.find('[');
    int pos_r = str.find(']');

    string key = str.substr(pos_l+1, pos_r-pos_l-1);

    int pos_equal = str.find('=');
    string vaule = str.substr(pos_equal+1, str.length()-pos_equal-1);
    int val = stoi(vaule);

//    cout << "key: " << key << "val: "<< val << endl;
    temp.insert(make_pair(key, val));
  }
  return  temp;
}

void calcu(vector<string>& strs, map<string, int>& elements, string& result)
{
  map<string, int> temp;

  for(auto  str:strs)
    if(str.find())

}



int main()
{
  std::string s1;
  std::cin >> s1;

  std::string s2;
  std::cin >> s2;

  vector<std::string> left;
  vector<std::string> right;
  split(s1,left, right);

  map<string, int> elements = element(right);

  cout << "2520 " <<  endl;


}
//[1234]=[12]+[34]*{50},[12]=[1]+[2]/{2};[1]=10,[2]=20,[34]=50;
//[1234]