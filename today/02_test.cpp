


#include <iostream>
#include <deque>
#include <cmath>

using  namespace std;
struct BinaryTreeNode
{
  int val;
  BinaryTreeNode* left;
  BinaryTreeNode* right;

  BinaryTreeNode(int value):val(value),left(NULL),right(NULL){};
};






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

  int p, q;
  cin >> p >> q;

  BinaryTreeNode* nodes;
   return 0;
}

//4
// 9 6 15 2 -1 12 25 -1 -1 -1 -1 -1 -1 20 37
// 12 20