//
// Created by hualong on 2019/4/1.
//
#include <iostream>
#include <vector>
using namespace std;
/*
 * ************************************************
 * 问题描述： 单链表的插入、删除

 * ************************************************
 */
struct ListNode{
    int value;
    ListNode* pred;
    ListNode* succ;
    //两种构造形式
    ListNode(int x) : value(x),pred(nullptr),succ(nullptr){}
    ListNode(int x, ListNode* p, ListNode* s) : value(x),pred(p),succ(s){}
};

class Solution {
public:
    // 方法描述：在ListNode尾节点插入一个节点 【新建一个节点，空链表直接插入，非空链表，找到尾节点插入】
    ListNode* addToTail(ListNode* pHead, int value){ //pHead 是指向 ListNode指针的指针

        ListNode* pNew = new ListNode(value);

        if(pHead == nullptr)
            pHead = pNew;
        else{
            ListNode* pNode = pHead;
            while(pNode->succ != nullptr){
                pNode = pNode->succ; //找到原链表的尾节点
            }
            pNode->succ = pNew;
            pNew->pred = pNode;
        }
        return pNew;
    }
    ListNode* insertAsPred(ListNode* pNode, int value)
    {
        ListNode* pNew = new ListNode(value, pNode->pred, pNode);
        pNode->pred->succ = pNew;
        pNode->pred = pNew;
        return pNew;
    }

    ListNode* insertAsSucc(ListNode* pNode, int value)
    {
        ListNode* pNew = new ListNode(value,pNode,pNode->succ);
        pNode->succ->pred = pNew;
        pNode->succ = pNew;
        return pNew;
    }

    //根据node的值删除节点
    void removeNode(ListNode* pHead, int value){
        if(pHead == nullptr) return;

        //想找到要删除
        ListNode* pToDelete = nullptr;
        if((pHead)->value == value){
            pToDelete = pHead;
            pHead = (pHead)->succ;
        } else{
            ListNode* pNode = pHead;
            while((pNode->succ != nullptr) && (pNode->succ->value != value))
                pNode = pNode->succ;
            if(pNode->succ != nullptr && pNode->succ->value == value) {
                pToDelete = pNode->succ;
                pNode->succ = pNode->succ->succ;
            }
        }
        if(pToDelete != nullptr){
            delete pToDelete;
            pToDelete = nullptr;
        }
    }

    void print_Node(ListNode* pHead)
    {
        if(pHead == nullptr) return;
        ListNode* pNode = pHead;
        cout << "The current ListNodes: ";
        while (pNode != nullptr)
        {
            cout << pNode->value << " ";
            pNode = pNode->succ;
        }
        cout << endl;
    }
};


int main()
{
    //输入
    vector<int> inputNums{1, 2, 3, 4, 5, 6};
    ListNode* testNodes = new ListNode(0);

    Solution solution;
    for(auto num:inputNums)
        solution.addToTail(testNodes, num);
    solution.print_Node(testNodes);
    solution.removeNode(testNodes, 5);
    solution.print_Node(testNodes);
    ListNode* position =  solution.insertAsSucc(testNodes->succ->succ, 100);
    solution.print_Node(testNodes);

    solution.insertAsPred(position, 300);
    solution.print_Node(testNodes);
    return 0;
}





/* *********************************************
 * 测试用例：
 * [-1,-2,-3,-4,-5]  -8  ==>  [2,4]
 *
 * *********************************************
 */