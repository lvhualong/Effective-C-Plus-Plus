//
// Created by hualong on 2019/4/1.
//
#include <iostream>
#include <vector>
using namespace std;
/*
 * ************************************************
 * 问题描述：反转一个单向链表
测试示例：
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```
 * ************************************************
 */

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
// 方法描述： 迭代的方法
    ListNode* reverseList(ListNode* head){
    if(head == nullptr) return nullptr; //空链表
    ListNode *pCurrent, *pPre, *pNext; //注意这个地方容易引发歧义
    // 初始化链表
    pPre = head;
    pCurrent = pPre->next;

    while(pCurrent){
        pNext = pCurrent->next;//缓存下一个节点

        pCurrent->next = pPre; //reverse
        pPre = pCurrent;

        pCurrent = pNext; //下一个
    }
    head->next = nullptr; //原来的头结点是现在的尾节点
    head = pPre; //新的头结点 作为返回指针
        return  head;
}
//通过数组初始化一个单向链表
ListNode* init(vector<int> const& nums)

//通过一个链表，填充一个线性数组

};


int main()
{
    //输入
    vector<int> inputNums{-1,-2,-3,-4,-5};
    int realTarget = -8;
    vector<int> expectTarget{2,4};

    //输出
    vector<int> outputTarget;
    Solution solution;
    outputTarget  =  solution.twoSum(inputNums, realTarget);

    (outputTarget == expectTarget) ?  cout << "Successful! ^_^": cout << "failed -_-";
    cout << endl;


    return 0;
}





/* *********************************************
 * 测试用例：
 * [-1,-2,-3,-4,-5]  -8  ==>  [2,4]
 *
 * *********************************************
 */