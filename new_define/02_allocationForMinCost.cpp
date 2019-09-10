

/*
 * **********************************************
 * 腾讯笔试第2题： 最小成本问题
 * 一条公路上分布着n个村庄，编号1~n,有些需要购进水果，有些需要贩卖水果
 * 设第i个村庄水果需求量为Ai, >0 表示需购进， < 表示需卖出
 * 所有村庄供需平衡，即 Ai之和等于0
 *  2<= n <=300000     -1000 <= Ai <= 1000
 * 求满足供需的最小费用
 *
 * 输入:
 * 第一行  5
 * 第二行  5, -4, 1, -3 ,1
 *
 * 输出：9
 * *********************************************
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int min_cost(vector<int>& nums){
        int cost = 0;
        for(int i=0; i< nums.size(); i++)
        {
                if(nums[i] > 0){
                    for(int j = i+1; j<nums.size();j++)
                        if(nums[j] < 0)
                        {
                            nums[j] += nums[i];
                            cost += ((j-i)*nums[i]);
                            break;
                        }
                }
                else{
                    for(int j = i+1; j<nums.size();j++)
                        if(nums[j] > 0)
                        {
                            nums[j] += nums[i];
                            cost += ((j-i)*(-nums[i]));
                            break;
                        }
                }
        }
        return  cost;
    }
};


int main()
{
    vector<int> A_value;
    int num_Village;
    cin >> num_Village;
    for(int i=0; i<num_Village; i++) {
        int temp;  cin >> temp;
        A_value.push_back(temp);
    }
//    vector<int>    A_value={5, -4, 1, -3 ,1};
    Solution solution;
    int cost = solution.min_cost(A_value);
    cout << cost <<endl;

    return 0;
}


