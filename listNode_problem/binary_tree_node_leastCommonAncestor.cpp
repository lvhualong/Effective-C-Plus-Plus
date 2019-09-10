
/*
 * 给定二元查找树，(二叉查找树 左节点都小于根，右节点都大于根)， 然后给定两个节点，查找他们的公共祖先
 *
 * 公共祖先；必定一个节点小于 root, 一个节点大于root, 所以使用递归的方式查找祖先
 *
 * 输入：
 * 第一行输入深度 n
 * 第二行输入二元查找树的节点的value 2^n -1个
 * 第三行输入两个节点的value p q
 *
 * 测试用例
 * 4
 * 9 6 15 2 -1 12 25 -1 -1 -1 -1 -1 -1 20 37
 * 12 20
 *
 * 输出 15
 */


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


BinaryTreeNode* lowestCommonAncestor(BinaryTreeNode* root, BinaryTreeNode* p, BinaryTreeNode* q) {
  if (root == NULL)
    return root;

  if (p->val > root->val && q->val > root->val) {
    return lowestCommonAncestor(root->right,p,q);
  }
  else if (p->val < root->val && q->val < root->val) {
    return lowestCommonAncestor(root->left,p,q);
  }
  return root;
}


void ConnectNodes(BinaryTreeNode* parent, BinaryTreeNode* left_node, BinaryTreeNode* right_node)
{
  if(parent != NULL)
  {
    parent->left = left_node;
    parent->right = right_node;
  }
}

void BFS_Binary_tree(deque<int>& nums, int value_p, int value_q) {
  deque<BinaryTreeNode *> buffer;
  BinaryTreeNode* p(NULL);
  BinaryTreeNode* q(NULL);
  BinaryTreeNode* root = new BinaryTreeNode(nums.front());
  nums.pop_front();
  buffer.push_back(root);

  while (nums.size() >= 2) {
    BinaryTreeNode* current = buffer.front();

    int left_value = nums.front();
    BinaryTreeNode *left = new BinaryTreeNode(left_value);
    buffer.push_back(left);
    if(left_value == value_p)
      p = left;
    if(left_value == value_q)
      q = left;
      nums.pop_front();

    int right_value = nums.front();
    BinaryTreeNode *right = new BinaryTreeNode(right_value);
    buffer.push_back(right);
    if(right_value == value_p)
      p = left;
    if(right_value == value_q)
      q = left;
    nums.pop_front();

    ConnectNodes(current, left, right);

    buffer.pop_front();
    }

  BinaryTreeNode* result_node =  lowestCommonAncestor(root, p, q);
  cout << "result: " << result_node->val << endl;
}



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
  BFS_Binary_tree(nums, p, q);

  return 0;
}

//4
// 9 6 15 2 -1 12 25 -1 -1 -1 -1 -1 -1 20 37
// 12 20