
/* *********************************************************
 * 问题描述：与上一题相反，这一题是已知桌子上的牌，推算原来手里的牌
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
#include <algorithm>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}

class Solution{
public:
    // pair是source 与重排序之后的序列的组合
    vector<pair<int,int>> function(deque<int>&  nums){
        vector<pair<int,int>> result;
        deque<int> value_in = nums; //不断插入删除的序列

        while(nums.size() >0){
            int source, target;
            source = value_in.front();
            value_in.pop_front();

            target = nums.front();
            nums.pop_front(); //第一个元素删除
            nums.push_back(nums.front()); //第二个元素插到队尾
            nums.pop_front();

            result.push_back(make_pair(source,target));
        }


        //输出

        cout << "the first source:" << endl;
        for(auto num:result)
            cout << num.first << " ";
        cout << endl;

        cout << "the second target:" << endl;
        for(auto num:result)
            cout << num.second << " ";
        cout << endl;

        sort(result.begin(), result.end(), comp);
        cout << "\n after sorted \n" << endl;

        cout << "the first source:" << endl;
        for(auto num:result)
            cout << num.first << " ";
        cout << endl;

        cout << "the second target:" << endl;
        for(auto num:result)
            cout << num.second << " ";
        cout << endl;

        return result;
    }
};

int main() {
    Solution solution;

    deque<int> nums{1,2,3,4,5,6,7,8,9,10,11,12,13};

    solution.function(nums);
//    std::cout << " " << std::endl;

    return 0;

}
/* *********************************************************
 * 解题思路：
 * 将原来的source 按照以一张输出，第二张插底，得到一个同样长度的target，
 * 将两个序列组合成一个pair, pair<source,target>
 *
 *  将pair排序， 按照第二维度 target,排序，然后输出排序后的第一维度就对了
 *
 * ----------------------------------
 * 测试示例：
 * 1 2 3 4 5 6 7 8 9 10 11 12 13
 * 1 12 2 8 3 11 4 9 5 13 6 10 7
 * *********************************************************
 */