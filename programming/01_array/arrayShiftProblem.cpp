
/* *********************************************************
 * 问题描述：序列元素移位问题（考察数据vector deque）
 *
 * 桌上有一叠牌，从上往下，开始依次编号1~n
 * 当至少还剩两张牌的时候，进行一下操作：
 * 把第一张牌扔掉，然后把新的第一张放到牌的最后
 * 输入n  输出每次扔掉的牌，以及最后剩下的牌
 * ----------------------------------
 * 输入示例：
 * 第一行输入整数T，表示有T组测试数据
 * 接下来有T行，每一行表示一个整数n,代表这组数据中牌的张数
 * (1 <= T <= 200     1 <= n <= 1000)
 *
 * 2
 * 2
 * 7
 *
 * 1 2
 * 1 3 5 7 4 2 6
 * *********************************************************
 */

#include <iostream>
#include <vector>
#include <list>   //容易删改 方便前后删除
#include <deque>
using namespace std;


class Solution{
public:
    void function(int num){
        if(num < 1) return;
        vector<int> value_out; //要输出的元素序列
        deque<int> value_in; //不断插入删除的序列
        int temp = 0;
        while(temp++ < num)
            value_in.push_back(temp);

        while (value_in.size())
        {
            value_out.push_back(value_in.front()); //取第一个元素 删除
            value_in.pop_front(); //删除头
            value_in.push_back(value_in.front());//第二个元素放到最后
            value_in.pop_front();//删除头
        }
        //输出
        for(auto num:value_out)
            cout << num << " ";
        cout << endl;
    }
};

int main() {
    Solution solution;
    int countT;
    vector<int> nums;
    cin >> countT;
    while(countT--)
    {
        int temp; cin >> temp;
        nums.push_back(temp);
    }

    for(auto num:nums) {
        solution.function(num);
    }
//    std::cout << " " << std::endl;

    return 0;

}
/* *********************************************************
 * 解题思路：
 * 定义两个序列，
 * vector 来定义 value_out 一个存储要输出的牌的,因为它只是在末端不断插入就好
 * deque / list 来定义 value_in ,每次删除front元素，在back插入
 *
 * ----------------------------------
 * 测试示例：
 *
 * *********************************************************
 */