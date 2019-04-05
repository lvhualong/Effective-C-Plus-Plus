//
// Created by hualong on 2019/4/1.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * ************************************************
 * 问题描述：
 * 给出两个 非空 的链表用来表示两个非负的整数，们各自的位数是按照 逆序 的方式存储的，
 * 将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * @ 给定 (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * @ 返回值：7 -> 0 -> 8
 * @ 说明： 342 + 465 = 807
 * ************************************************
 */





 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next; //节点指针
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int valueL,valueR; valueL = valueR = 0;
        while(l1 != nullptr) {
            valueL += (l1->val);
        }

    }
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