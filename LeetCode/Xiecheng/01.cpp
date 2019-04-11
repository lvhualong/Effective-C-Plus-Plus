
/*
 * **********************************************
 * 腾讯笔试第1题： 数字拆分游戏
 *  最初只有一个整数N
 *
 *  接下来每一轮中对现有的每一个数进行下面两个操作之一：
 *  1. 数字减1
 *  2. 把其中一个数字拆分成更小的两个数字之和
 *  但拆分操作只允许至多k次
 *  现在想知道，把N完全消去(全部拆分成1)，需要多少轮操作
 *
 * 满足 1<=n<=100     0<=k<=100
 *
 * 测试用例：
 * 输入: 5 2
 * 输出：4
 *
 * 解决思路：
 * 先对最大数字拆分，
 * 后面的每次减1即可
 * *********************************************
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    unsigned int  allocationTimes(vector<unsigned  int>& nums){
        unsigned int median = 0 ;
        sort(nums.begin(), nums.end());
        median = nums[nums.size()/2];
        for(int i=0; i<median; i++)
        {
            nums[i] = median/nums[i];
        }
        for(int i=median+1; i<nums.end(); i++)
        {
            nums[i] = nums[i]/median;
        }


    }

};

int main()
{
    unsigned  int n=3;
    vector<unsigned  int> nums;
    cin >> n;
    int temp;
    while(cin >> temp)
        nums.pop_back(temp);

    Solution solution;
    int cost = solution.splitNum(n,k);

    cout << cost <<endl;

    return 0;
}


