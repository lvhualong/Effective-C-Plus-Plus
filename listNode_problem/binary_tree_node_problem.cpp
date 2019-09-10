//
// Created by LAB540 on 2019/9/5.
//

/*
 * 二叉搜索树： 按照中序遍历，是已经排序好了的，left_child 小于根， right_child大于根
 * 平衡二叉搜索树： 叶子节点的深度差 <=1
 * 红黑树： 使用红黑节点插入方式 代替原生的 平衡插入算法，平衡深度可能多一层，但是插入效率高许多
 */
#include <iostream>
#include <vector>
#include <deque>
#include <stack>

using  namespace std;
struct BinaryTreeNode
{
  int val;
  BinaryTreeNode* left;
  BinaryTreeNode* right;

  BinaryTreeNode(int value):val(value),left(NULL),right(NULL){};
};

// 设置节点的连接
void  ConnectTreeNodes(BinaryTreeNode* parent, BinaryTreeNode* left_node, BinaryTreeNode* right_node);


/*
 * 各种遍历方式
 * 深度优先遍历 使用递归或者利用栈,
 * 广度优先遍历 利用双端队列，
 * https://www.cnblogs.com/llhthinker/p/4747962.html
 * 先序遍历 实际就是深度优先遍历， 根节点不为空先入栈， 如果栈不为空，pop_top 然后分别将top的右节点，左节点压入栈
 * 中序遍历
 * 后序遍历
 */
// 深度优先遍历
bool DFS_Binary_tree(BinaryTreeNode* root,  vector<int>& nums);
// 广度优先遍历
bool BFS_Binary_tree(BinaryTreeNode* root, vector<int>& nums);
// 先序遍历 stack
void preorder_traversal(BinaryTreeNode* root, vector<int>& nums);
// 中序遍历
void inorder_traversal(BinaryTreeNode* root, vector<int>& nums);
// 后序遍历
void postorder_traversal(BinaryTreeNode* root, vector<int>& nums);

int main()
{
  // add node
  BinaryTreeNode* p8 = new BinaryTreeNode(8);
  BinaryTreeNode* p6 = new BinaryTreeNode(6);
  BinaryTreeNode* p10 = new BinaryTreeNode(10);
  BinaryTreeNode* p4 = new BinaryTreeNode(4);
  BinaryTreeNode* p7 = new BinaryTreeNode(7);
  BinaryTreeNode* p9 = new BinaryTreeNode(9);
  BinaryTreeNode* p11 = new BinaryTreeNode(11);

//            8
//        6      10
//       4 7    9  11
  ConnectTreeNodes(p8, p6, p10);
  ConnectTreeNodes(p6, p4, p7);
  ConnectTreeNodes(p10, p9, p11);

  vector<int> depth_first_search_list;
  DFS_Binary_tree(p8, depth_first_search_list);
  cout << "DFS: " ;
  for(auto num:depth_first_search_list)
    cout << num << " " ;
  cout << endl;

  vector<int> breadth_first_search_list;
  BFS_Binary_tree(p8, breadth_first_search_list);
  cout << "BFS: " ;
  for(auto num:breadth_first_search_list)
    cout << num << " " ;
  cout << endl;

  vector<int> preorder_traversal_list;
  preorder_traversal(p8, preorder_traversal_list);
  cout << "preorder_traversal: " ;
  for(auto num:preorder_traversal_list)
    cout << num << " " ;
  cout << endl;

  vector<int> inorder_traversal_list;
  inorder_traversal(p8, inorder_traversal_list);
  cout << "in order_traversal: " ;
  for(auto num:inorder_traversal_list)
    cout << num << " " ;
  cout << endl;

  vector<int> postorder_traversal_list;
  postorder_traversal(p8, postorder_traversal_list);
  cout << "postorder_traversal: " ;
  for(auto num:postorder_traversal_list)
    cout << num << " " ;
  cout << endl;


  return 0;
}

/*
 * 深度优先使用递归
 */
bool DFS_Binary_tree(BinaryTreeNode* root,  vector<int>& nums)
{
   if(root == NULL)
     return false;

   nums.push_back(root->val);
   DFS_Binary_tree(root->left, nums);
   DFS_Binary_tree(root->right, nums);

  return  true;
}

/*
 * 广度优先，借用双端队列的结构
 * 每次把节点 push_back
 * 当deque不空时，pop_front 并且把front节点的 left_right节点，push_back
 */
bool BFS_Binary_tree(BinaryTreeNode* root, vector<int>& nums)
{
  deque<BinaryTreeNode*> buffer;
  if(root != NULL) {
    buffer.push_back(root);
    nums.push_back(root->val);
  }

  while(!buffer.empty())
  {
    BinaryTreeNode* temp_node = buffer.front();
    buffer.pop_front();
    if(temp_node->left != NULL)
    {
      buffer.push_back(temp_node->left);
      nums.push_back(temp_node->left->val);
    }
    if(temp_node->right != NULL)
    {
      buffer.push_back(temp_node->right);
      nums.push_back(temp_node->right->val);
    }
  }
  return true;
}

void preorder_traversal(BinaryTreeNode* root, vector<int>& nums)
{
   stack<BinaryTreeNode*> buffer;
   if(root != NULL)
   {
     buffer.push(root);
   }

   while(!buffer.empty())
   {
     BinaryTreeNode* temp_node = buffer.top();
     nums.push_back(temp_node->val);
     buffer.pop();

     // !! 先压如右节点
     if(temp_node->right != NULL){
       buffer.push(temp_node->right);
     }
     if(temp_node->left != NULL){
       buffer.push(temp_node->left);
     }
   }
}


void inorder_traversal(BinaryTreeNode* root, vector<int>& nums)
{
  // 递归版本
//  if(root == NULL)
//    return;
//  inorder_traversal(root->left, nums);
//  nums.push_back(root->val);
//  inorder_traversal(root->right, nums);

  // 非递归，使用栈
  stack<BinaryTreeNode*> buffer;
  BinaryTreeNode* current_Node = root;

  while (current_Node != NULL || !buffer.empty())
  {
    //先把left_child都入栈
    while(current_Node != NULL) {
      buffer.push(current_Node);
      current_Node = current_Node->left;
    }

    if(!buffer.empty())
    {
      current_Node = buffer.top();
      buffer.pop();
      nums.push_back(current_Node->val);
      current_Node = current_Node->right;
    }
  }
}

void postorder_traversal(BinaryTreeNode* root, vector<int>& nums)
{
  // 递归版本
  if(root == NULL)
    return;
//  postorder_traversal(root->left, nums);
//  postorder_traversal(root->right, nums);
//  nums.push_back(root->val);

  // 非递归，使用栈
  stack<BinaryTreeNode*> buffer;
  BinaryTreeNode* current_Node = NULL;
  BinaryTreeNode* prev_Node = NULL;
  buffer.push(root);

  while ( !buffer.empty())
  {
    current_Node = buffer.top();
    if(prev_Node==NULL || prev_Node->left==current_Node || prev_Node->right==current_Node)
    {
      if(current_Node->left != NULL)
        buffer.push(current_Node->left);
      else if(current_Node->right != NULL)
        buffer.push(current_Node->right);
    }
    else if(current_Node->left == prev_Node){
      if(current_Node->right != NULL)
        buffer.push(current_Node->right);
    }
    else
    {
      nums.push_back(current_Node->val);
      buffer.pop();
    }
    prev_Node = current_Node;
  }
}

void  ConnectTreeNodes(BinaryTreeNode* parent, BinaryTreeNode* left_node, BinaryTreeNode* right_node)
{
  if(parent != NULL)
  {
    parent->left = left_node;
    parent->right = right_node;
  }
}


