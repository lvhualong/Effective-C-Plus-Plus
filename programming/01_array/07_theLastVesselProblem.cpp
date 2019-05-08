
/* *********************************************************
 * 问题描述：类似于数组的最大连续子数组和问题， 这是一个最大容器(矩形面积)问题
 *
 * 给定n个非负整数，a0, a1……，每个整数代表一个坐标(i, ai)
 * 根据这些坐标可以画出n个垂直于x轴的垂直线，每条线的端点(i,0)与(i, ai)
 * 在这些相中，找到两条垂线，和x轴一起组成可以盛水的容器，容器不可倾斜
 * 要求容器盛水最多，并输入最大值
 *
 * 注意：n最小为2， 要求写出算法为线性时间复杂度O(n)
 *
 *
 * 输入描述：
 * 输入多行，给出n个非负整数ai,
 * 数字用逗号分开，且逗号跟数字之间有任意空白字符
 * 1,
 * 8,  2,
 * 6, 5
 * 输出最大容量
 * 15
 *
 * 解释：
 * 5*(4-1) = 15
 * *********************************************************
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
class Solution {
public:
    //暴力方法  遍历所有子集呗 时间复杂度O(n^2)
    int getMaxArea(vector<int>& nums){
        int maxArea = 0;
        int area_temp = 0;
        for(int i=0; i<nums.size()-1; ++i)
            for(int j=i+1; j<nums.size(); ++j)
            {
                area_temp  = min(nums[i], nums[j])*(j-i);
                if(area_temp>maxArea)
                    maxArea = area_temp;
            }
        return  maxArea;
    }

    //贪心算法思路：
    int getMaxArea_greedy(vector<int>& nums)
    {
        vector<int>::iterator left = nums.begin();
        vector<int>::iterator right = nums.end()--;

        int x = right - left;
        int y = min(*left, *right);
        int area = x*y;
        while(left != right)
        {
            if(*left > *right) //每次移动小的那个
                right--;
            else
                left++;
            x = right - left;
            y = min(*left, *right);
            int tempArea = x*y;

            if(tempArea>area)
                area = tempArea;
        }
        return  area;
    }



    // 字符串切法，转换成整数
    void strToNum(string str, vector<int>& nums)
    {
        char* c_str = new char [str.length()+1];
        strcpy(c_str, str.c_str());
        char* c_value;
        c_value = strtok (c_str," ,.-");
        while(c_value != NULL)
        {
            int temp = (*c_value-'0');
            nums.push_back(temp);
            c_value = strtok (NULL,", ");
        }
        delete [] c_str;
    }
};

int main() {
    string input;
    vector<int> numbers;
    Solution solution;
    while(getline(cin, input))
    {
        if(input.back() == ',') {
            solution.strToNum(input, numbers);
        }
        else
        {
            solution.strToNum(input, numbers);
            break;
        }
    }
    cout << "the O(n^2) solution: " << solution.getMaxArea(numbers)<<endl;
    cout << "the O(n) solution: " << solution.getMaxArea(numbers)<<endl;

    return 0;
}
/* *********************************************************
 * 解题思路：
 *  暴力解法： 双重循环，列出所有两个边组合，取出最大容量
 *
 *  贪心算法： 先找出最大的横坐标，然后依次减小横坐标，变换纵坐标，
 *      注意每次移动一位，都是纵坐标小的那个移动
 * ----------------------------------
 * 测试示例：
 *
 * *********************************************************
 */