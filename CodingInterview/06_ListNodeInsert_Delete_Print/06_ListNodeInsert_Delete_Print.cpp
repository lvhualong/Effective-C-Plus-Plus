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
    ListNode* next;
    ListNode(int x) : value(x),next(nullptr){}
};

class Solution {
public:
    // 方法描述：在ListNode尾节点插入一个节点 【新建一个节点，空链表直接插入，非空链表，找到尾节点插入】
    ListNode* addToTail(ListNode* pHead, int value){ //pHead 是指向 ListNode的头指针

        ListNode* pNew = new ListNode(value);

        if(pHead == nullptr)
            pHead = pNew;
        else{
            ListNode* pNode = pHead;
            while(pNode->next != nullptr){
                pNode = pNode->next; //找到原链表的尾节点
            }
            pNode->next = pNew;
        }
        return pNew;
    }

    //在链表中的指定节点后面插入一个新节点
    ListNode* insertNode(ListNode* pNode, int value){
        ListNode* pNew = new ListNode(value);

        if(pNode == nullptr)
            pNode = pNew;
        else{
            pNew->next = pNode->next;
            pNode->next = pNew;
        }
        return pNew;
    }


    //根据node的值删除节点
    void removeNode(ListNode* pHead, int value){
        if(pHead == nullptr) return;

        //想找到要删除
        ListNode* pToDelete = nullptr;
        if((pHead)->value == value){
            pToDelete = pHead;
            pHead = (pHead)->next;
        } else{
            ListNode* pNode = pHead;
            while((pNode->next != nullptr) && (pNode->next->value != value))
                pNode = pNode->next;
            if(pNode->next != nullptr && pNode->next->value == value) {
                pToDelete = pNode->next;
                pNode->next = pNode->next->next;
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
            pNode = pNode->next;
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
    solution.insertNode(testNodes->next->next, 10);
    solution.print_Node(testNodes);

    return 0;
}





/* *********************************************
 * 测试用例：
 *
 * *********************************************
 */