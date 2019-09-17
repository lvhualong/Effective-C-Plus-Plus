//
// Created by LAB540 on 2019/8/28.
//

/*
 * 判断一个单向链表是否为回文链表，要求时间复杂度0(n), 空间复杂度O(1)
 *
 * 例如：
 * 1->2->2->1
 *
 * 输出true
 */

/*
 * 设计思路：
 * 1. 快慢指针找到链表中点
 * 2. 迭代法翻转后半部分链表  注意这里面有单链表的翻转
 * 3. 比较两部分链表
 */


#include <iostream>

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x):val(x),next(NULL){}
};

bool isPalindrome(ListNode* head)
{
  if (head == NULL || head->next == NULL) {
    return true;
  }
  ListNode* prev = NULL;
  ListNode* slow = head;
  ListNode* fast = head;

  //去找中间位置，同时把前面部分逆序
  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next; //快指针每次走两步，这样快指针走到结尾的时候，慢指针走到中间

    //单链表翻转
    ListNode* next = slow->next;
    slow->next = prev;
    prev = slow;

    //下一次迭代
    slow = next;
  }

  //这是为奇数时对s额外的操作
  if (fast != NULL) {
    slow = slow->next;
  }

  //开始判断回文
  // slow 刚好走到后半段， prev刚好走到前半段
  while (slow != NULL) {
    if (slow->val != prev->val) {
      return false;
    }
    slow = slow->next; //后半段
    prev = prev->next; //前半段
  }
  return true;
}



int main()
{

  return 0;
}