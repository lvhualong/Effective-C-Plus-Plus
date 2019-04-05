//
// Created by hualong on 2019/4/1.
//
#include <iostream>
using namespace std;
/*
 * ************************************************
>问题描述：
删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点
```
测试示例：
输入: head = [4,5,1,9], node = 5
输出: [4,1,9]
```
 * ************************************************
 */
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(nullptr){} //构造函数
};

class Solution {
public:
// 方法描述：
    void deleteNode(ListNode* node){
        if(!node || !node->next)
            return;
        node->val = node->next->val;
        node->next = node->next->next;
        return;
}


};


int main()
{
    //可以写一个有数组到链表的初始化
    // 然后使用链表的删除

    return 0;
}





/* *********************************************
 * 测试用例：
 * [-1,-2,-3,-4,-5]  -8  ==>  [2,4]
 *
 * *********************************************
 */