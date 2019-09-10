
/*
 * 二叉树遍历问题： 给你以层次遍历(广度优先遍历) 2^n -1个节点的值， 输出这个二叉树的中序遍历结果
 *
 * 测试用例
 * 第一行 输入树的深度为N
 * 第二行 2^n -1个元素，以层次遍历的完全二叉树
 *
 * 求中序遍历的元素序列
 *      1
 *    2   3
 *  4  5 6 7
 * 输入
 * 3
 * 1 2 3 4 5 6 7
 *
 * 输出
 * 4 2 5 1 6 3 7
 *
 *
 * 解题思路：
 * 层次遍历也就是广度优先遍历，可以借助一个双端队列实现遍历
 * 我们遍历的时候是 创建一个deque<node*> buffer 从根节点开始 每次取front, 然后将这个节点的左右child放在back
 * 这样就可以通过 顺着root节点的这棵树，将所有节点都遍历一遍
 *
 * 现在问题反过来了，我们已经知道了完全二叉树的广度遍历的结果，反过来推算中序遍历的结果
 * 第一步需要根据遍历结果，构建出一颗完全二叉树
 * 然后再从根节点开始，对树进行中序遍历。
 *
 * 构建平衡二叉树的过程和原来一样，把遍历结果放在deque中，每次从front取，然后不断地定义节点，连接节点
 *
 */

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <cmath>

using  namespace std;
struct BinaryTreeNode
{
  int val;
  BinaryTreeNode* left;
  BinaryTreeNode* right;

  BinaryTreeNode(int value):val(value),left(NULL),right(NULL){};
};

void inorder_traversal(BinaryTreeNode* root) {

  if(root == NULL)
    return;
  inorder_traversal(root->left);
  cout << root->val << endl;
  inorder_traversal(root->right);
}

void  ConnectLeftNodes(BinaryTreeNode* parent, BinaryTreeNode* left_node)
{
  if(parent != NULL)
  {
    parent->left = left_node;
  }
}
void  ConnectRightNodes(BinaryTreeNode* parent, BinaryTreeNode* right_node)
{
  if(parent != NULL)
  {
    parent->right = right_node;
  }
}

void BFS_Binary_tree(BinaryTreeNode* nodes, deque<int>& nums) {
  deque<BinaryTreeNode *> buffer;
//  cout << "nums size: " << nums.size() << endl;
  BinaryTreeNode* root = new BinaryTreeNode(nums.front());
  nums.pop_front();
  buffer.push_back(root);

  while (!nums.empty()) {
    BinaryTreeNode* current = buffer.front();

    BinaryTreeNode *left = new BinaryTreeNode(nums.front());
    nums.pop_front();
    ConnectLeftNodes(current, left);
    buffer.push_back(left);
//    cout << "nums size: " << nums.size() << endl;

    if(!nums.empty()) {
      BinaryTreeNode *right = new BinaryTreeNode(nums.front());
      nums.pop_front();
      ConnectRightNodes(current, right);
      buffer.push_back(right);
    }
    buffer.pop_front();
//    cout << "buffer size:" << buffer.size() << endl;
  }

  inorder_traversal(root);
  delete root;

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

  BinaryTreeNode* nodes;
  BFS_Binary_tree(nodes, nums);

  return 0;
}

