//
// Created by LAB540 on 2019/8/4.
//

// 面试题54：二叉搜索树的第k个结点
// 题目：给定一棵二叉搜索树，请找出其中的第k大的结点。

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

    }
}

const BinaryTreeNode* KthNodeCore(const BinaryTreeNode* pRoot, unsigned int& k);

const BinaryTreeNode* KthNode(const BinaryTreeNode* pRoot, unsigned int k)
{
    if(pRoot == nullptr || k == 0)
        return nullptr;

    return KthNodeCore(pRoot, k);
}

//二叉搜索树是中序的，所以按照左中右的方式进行遍历
const BinaryTreeNode* KthNodeCore(const BinaryTreeNode* pRoot, unsigned int& k)
{
    const BinaryTreeNode* target = nullptr;

    if(pRoot->m_pLeft != nullptr)
        target = KthNodeCore(pRoot->m_pLeft, k);

    if(target == nullptr)
    {
        if(k == 1)
            target = pRoot;

        k--;
    }

    if(target == nullptr && pRoot->m_pRight != nullptr)
        target = KthNodeCore(pRoot->m_pRight, k);

    return target;
}

int main()
{
//            8
//        6      10
//       5 7    9  11

        BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
        BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
        BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
        BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
        BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
        BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
        BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

        ConnectTreeNodes(pNode8, pNode6, pNode10);
        ConnectTreeNodes(pNode6, pNode5, pNode7);
        ConnectTreeNodes(pNode10, pNode9, pNode11);

        const BinaryTreeNode* result = KthNode(pNode8, 1);

        std::cout << "the node value: " << result->m_nValue << std::endl;


    return 0;
}