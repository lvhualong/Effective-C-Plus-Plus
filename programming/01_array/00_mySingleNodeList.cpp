//
// Created by hualong on 2019/4/1.
//
#include <iostream>
#include <vector>
using namespace std;
/*
 * ************************************************
 * 问题描述： 单链表的插入、删除、打印
 * ListNode* addToTail(ListNode* pHead, int value) 在链表的结尾插入节点
 * ListNode* insertNode(ListNode* pNode, int value) 在链表的指定node 后面插入节点
 *
 * void removeNode(ListNode* pHead, int value) 根据值删除链表中的某一个元素
 * void deleteNode(ListNode* pHead, ListNode* pToDelete) 根据位置删除链表中某一个元素 O(1)时间复杂度
 * void print_Node(ListNode* pHead) 打印链表中每个node的值
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

        if(pHead == nullptr) //空list
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

        if(pNode == nullptr) //空链表
            pNode = pNew;
        else{
            pNew->next = pNode->next;
            pNode->next = pNew;
        }
        return pNew;
    }


    //根据node的值删除节点(O(n)时间复杂度)
    void removeNode(ListNode* pHead, int value){
        if(pHead == nullptr) return;

        //想找到要删除
        ListNode* pToDelete = nullptr;
        if((pHead)->value == value){ //头结点
            pToDelete = pHead;
            pHead = (pHead)->next;
        } else{                     // 其他节点
            ListNode* pNode = pHead;
            while((pNode->next != nullptr) && (pNode->next->value != value))
                pNode = pNode->next;
            if(pNode->next != nullptr && pNode->next->value == value) {
                pToDelete = pNode->next;
                pNode->next = pNode->next->next;
            }
        }
        // delete
        if(pToDelete != nullptr){
            delete pToDelete;
            pToDelete = nullptr;
        }
    }

    //根据node的位置 删除节点
    void deleteNode(ListNode* pHead, ListNode* pToDelete)
    {
        //特殊输入处理
        if(pHead == nullptr || pToDelete == nullptr)
            return;

        // 删除非尾节点
        // 删除思路 复制pToDelete后一个节点到当前节点，删除后一个节点
        else if(pToDelete->next != nullptr)
        {
            ListNode* pNode = pToDelete->next;
            //复制
            pToDelete->value = pNode->value;
            pToDelete->next = pNode->next;

            delete pNode;
            pNode = nullptr;
        }
        // 删除尾节点
        // 遍历到结尾
        else{
            ListNode* pNode = pHead;
            while(pNode->next != pToDelete && pNode->next!= nullptr)
                pNode = pNode->next;
            pNode->next = nullptr;
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
    solution.deleteNode(testNodes, testNodes);
    solution.print_Node(testNodes);

    return 0;
}





/* *********************************************
 * 测试用例：
 *
 * *********************************************
 */