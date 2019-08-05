//
// Created by LAB540 on 2019/8/4.
//

// 面试题55（二）：平衡二叉树
// 题目：输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中
// 任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

#include <cstdio>
#include <iostream>



struct BinaryTreeNode
{
    int                    m_nValue;
    BinaryTreeNode*        m_pLeft;
    BinaryTreeNode*        m_pRight;
};


BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;

//        if(pLeft != nullptr)
//            pLeft->m_pParent = pParent;
//        if(pRight != nullptr)
//            pRight->m_pParent = pParent;
    }
}



// ====================方法1 使用递归的方式====================
int TreeDepth(const BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return 0;

    int nLeft = TreeDepth(pRoot->m_pLeft);
    int nRight = TreeDepth(pRoot->m_pRight);

//    std::cout << nLeft << " " << nRight << std::endl;
    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

//这种方法可以利用上面求深度的方式，但是会重复遍历节点，效率不高
bool IsBalanced_Solution1(const BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return true;

    int left = TreeDepth(pRoot->m_pLeft);
    int right = TreeDepth(pRoot->m_pRight);
    int diff = left - right;
    if(diff > 1 || diff < -1)
        return false;

    return IsBalanced_Solution1(pRoot->m_pLeft)
           && IsBalanced_Solution1(pRoot->m_pRight);
}

// ====================方法2====================
// 采用后序遍历的方式
// 这样在遍历一个节点之前，已经遍历了它左右子树
// 只要在遍历每个节点的时候记录它的深度，就可以一边遍历，一边判断它是不是平衡的
bool IsBalanced(const BinaryTreeNode* pRoot, int* pDepth);

bool IsBalanced_Solution2(const BinaryTreeNode* pRoot)
{
    int depth = 0;
    return IsBalanced(pRoot, &depth);
}

bool IsBalanced(const BinaryTreeNode* pRoot, int* pDepth)
{
    if(pRoot == nullptr)
    {
        *pDepth = 0;
        return true;
    }

    int left, right;
    if(IsBalanced(pRoot->m_pLeft, &left)
       && IsBalanced(pRoot->m_pRight, &right))
    {
        int diff = left - right;
        if(diff <= 1 && diff >= -1)
        {
            *pDepth = 1 + (left > right ? left : right);
            return true;
        }
    }
    return false;
}


int main()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

// 完全二叉树
//             1
//         /      \
//        2        3
//       /\       / \
//      4  5     6   7

//    ConnectTreeNodes(pNode1, pNode2, pNode3);
//    ConnectTreeNodes(pNode2, pNode4, pNode5);
//    ConnectTreeNodes(pNode3, pNode6, pNode7);


    // 不是平衡二叉树
//             1
//         /      \
//        2        3
//       /\
//      4  5
//        /
//       6
    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode5, pNode6, nullptr);

    std::cout << "the depth: " << TreeDepth(pNode1)  << std::endl;
    bool result = IsBalanced_Solution1(pNode1);
    if(result)
        std::cout << "this tree is an balance tree" << std::endl;
    else
        std::cout << "this tree is not an balance tree" << std::endl;


}
/*
 * 解题思路
 */