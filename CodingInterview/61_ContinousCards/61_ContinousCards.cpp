//
// Created by LAB540 on 2019/8/3.
//

// 面试题61：扑克牌的顺子
// 题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isContinous(vector<int> cards)
{
    if(cards.empty())
        return false;
    sort(cards.begin(), cards.end());

    int zeroCount = 0;
    int diff  = 0;
    int lastCard = cards.front();//第一个元素
    for(auto card : cards)
    {
        cout << "the element: "<< card << endl;
        if(card == 0)
            zeroCount++;
        else
        {
            if(card == lastCard)
                return false;
            if(lastCard != 0) //注意这个条件
                diff += (card - lastCard);
        }
        lastCard = card;
    }
    if(diff > zeroCount*2)
        return false;
    else
        return true;

}

/*
 * 解题思路：
 *  - 把抽取的扑克牌放在数组里
 *  - 排序
 *  - 判断零的个数 大小王通配
 *  - 判断是否有对子，计算所有相邻的差
 *
 */

int main()
{
    vector<int> test_card{1, 3, 0, 5, 0, 7};
    vector<int> test_card_1{1, 3, 0, 5, 0};
    vector<int> test_card_2{1, 3, 0, 5, 0, 3};

    bool resolute = isContinous(test_card_2);
    std::cout << "the resoult is: "<< resolute << endl;
    return 0;
}
