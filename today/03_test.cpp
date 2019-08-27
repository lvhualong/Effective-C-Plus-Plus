#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

void solution(string a, string b)
{

  int i = 0;
  while(a[i] == b[i])
    i++;

  cout << i;

}

int main() {

  int num;
  cin >> num;
  vector<string> inputstrs;
  for(int i=0; i< num; i++)
  {
    string temp;
    cin >> temp;
    inputstrs.push_back(temp);
  }
  vector<pair<int,int>> state;
  for(int i=0; i< num; i++)
  {
    int a,b;
    cin >> a>>b;
    state.push_back(make_pair(a,b));
  }

  for(int j=0; j<state.size(); j++)
  {
    solution(inputstrs[state[j].first],inputstrs[state[j].second]);
  }


    return 0;
}
