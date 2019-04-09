
/*
 * **********************************************
 * 腾讯笔试第三题：
 *  一个包含n个数字的数组，对数组进行k次操作：
 *  每次操作如下：
 *  首先找出数组中最小的非0数字x, 输出它，
 *  然后把数组中所有非零数字都减去x,
 *  如果数组中的数字都是0,那么就输出0
 * 满足 n>=1  k<=10^5     1 < = ai <= 10^9
 * 输入:
 * 第一行  n k
 * 第二行  n个元素
 *
 * 输出：k行 每行一个整数
 *
 * 测试示例：
 * 4 1
 * 5 5  7 2
 *
 *输出：
 * 2
 *
 * 解决思路：
 * 每次先找到数组中最小元素  for  或者 使用排序算法 [注意是非0的最小元素]
 * 每次把前n-1数字都减去最后一个数字
 * *********************************************
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    void min_cost(vector<int>& nums, int k){
    while(k--){
        sort(nums.begin(), nums.end()); //排序 最小值放在前面
        //找出最小值
        int min_index = 0;
        while(nums[min_index] == 0) {
            min_index++;
            if(min_index == nums.size()-1)
            {
                cout << 0 << endl;
                break;
            }
        }
        if(min_index != nums.size()-1)
        cout << nums[min_index] << endl;
        //更新数组中非零元素
        for(int j=min_index+1; j<nums.size(); j++) {
            if (nums[j] != 0)
                nums[j] -= nums[min_index];
         }
        }
    }
};


int main()
{
    vector<int> nums;
    int n, k;
    cin >> n >>k;
    for(int i=0; i<n; i++) {
        int temp; cin >> temp;
        nums.push_back(temp);
    }

//    vector<int>   input={5, 5, 7, 2};

    Solution solution;
    solution.min_cost(nums, k);


    return 0;
}

/*
 * **************************************************
 *  测试用例：
 *  4 5
 *  1 2 3 0
 *
 *  4 3
 *  -1 2 3 0
 * **************************************************
 */
