//
// Created by LAB540 on 2019/8/3.
//


// 面试题63：股票的最大利润
// 题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股
// 票可能获得的利润是多少？例如一只股票在某些时间节点的价格为{9, 11, 8, 5,
// 7, 12, 16, 14}。如果我们能在价格为5的时候买入并在价格为16时卖出，则能
// 收获最大的利润11。
//
// 同时查找数组中的最大值和最小值之差


#include <vector>
#include <iostream>

using namespace std;

int maxProfile(const vector<int> history_prise)
{
    if(history_prise.size() < 2)
        return 0;

    int min = history_prise[0];
    int maxDiff = history_prise[1] - min;

    for(size_t i=1; i< history_prise.size(); i++)
    {
        if(history_prise[i] < min)
            min = history_prise[i];
        int currentDiff = history_prise[i] - min;
        if(maxDiff < currentDiff)
            maxDiff = currentDiff;
    }
    return maxDiff;
}

int main()
{
    vector<int> biaopu_500{9, 11,8 ,6, 13, 18};

    int max_profile = maxProfile(biaopu_500);
    std::cout << "the max profile: "<< max_profile << std::endl;
    return 0;
}