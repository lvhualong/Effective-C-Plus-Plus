


#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <cmath>

using  namespace std;




int main()
{
  int n;
  deque<int> nums;
  cin >> n;

  for(int i=0; i<pow(2,n)-1; i++)
  {
    int temp; cin >> temp;
    nums.push_back(temp);
  }


  return 0;
}

