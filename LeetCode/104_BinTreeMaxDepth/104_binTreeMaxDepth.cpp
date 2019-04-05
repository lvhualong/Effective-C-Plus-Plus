//
// Created by hualong on 2019/4/5.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 * ************************************************
 * 问题描述：
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数
 *  给定二叉树 [3,9,20,null,null,15,7]， 返回最大深度为3
 * ************************************************
 */
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} //构造函数
};

class Solution {
public:
// 方法描述：
    int maxDepth(TreeNode* root)
    {
        if(root == nullptr)//空树
            return 0;
        return (max(maxDepth(root->left),  maxDepth(root->right)) + 1);

    }

    //使用数组元素初始化一个二叉树
    TreeNode* initBTree(int elements[], int size) {
        if (size < 1) {
            return NULL;
        }
        //动态申请size大小的指针数组
        TreeNode **nodes = new TreeNode *[size];
        //将int数据转换为TreeNode节点
        for (int i = 0; i < size; i++) {
            if (elements[i] == 0) {
                nodes[i] = nullptr;
            } else {
                nodes[i] = new TreeNode(elements[i]);
            }
        }
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(nodes[0]);

        TreeNode *node;
        int index = 1;
        while (index < size) {
            node = nodeQueue.front();
            nodeQueue.pop();
            nodeQueue.push(nodes[index++]);
            node->left = nodeQueue.back();
            nodeQueue.push(nodes[index++]);
            node->right = nodeQueue.back();
        }
        return nodes[0];
    }

};


int main()
{
    //输入 [3,9,20,0,0,15,7] // 0表示 null
//    int input[] = {3,9,20,0,0,15,7};  //7个元素
    int input[] = { 1, 2, 3, 4, 0, 5, 6, 0, 7 }; //9个元素

    Solution solution;
    TreeNode* root = solution.initBTree(input,9);
    int output  =  solution.maxDepth(root);

    cout << "the depth of the tree is " << output  << endl;

    return 0;
}




/* *********************************************
 * 测试用例：
 * { 1, 2, 3, 4, 0, 5, 6, 0, 7 }  ==> return 4
 *   1
    / \
   2   3
  /   / \
 4   5  6
  \
   7
输入：[3,9,20,null,null,15,7] ==> return 3
    3
   / \
  9  20
    /  \
   15   7
 * *********************************************
 */