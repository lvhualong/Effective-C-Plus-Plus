
/* *********************************************************
 * 问题描述：
 *
 *
 * ----------------------------------
 * 输入示例：
 *
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
 *
 *
 * ----------------------------------
 * 测试示例：
 *
 * *********************************************************
 */