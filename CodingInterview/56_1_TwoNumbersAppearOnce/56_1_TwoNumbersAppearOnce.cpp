//
// Created by LAB540 on 2019/8/3.
//

// 面试题56（一）：数组中只出现一次的两个数字
// 题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
// 找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是 O(1)。
// 例如{2,4,3,6,3,2,5,5}

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

//判断num 某一位是否为1
bool isBit1(int num, int bit)
{
    return  (num >> bit) & 1;
}

//找到右起第一位为1的位
int theFisrtBit1(int num)
{
    int indexBit = 0;
    while((num & 0x1) ==0 && indexBit< 8* sizeof(int)) {
        num = num >> 1;
        indexBit++;
    }
    return  indexBit;
}


// 如果数组中仅有一个数字出现两次 find it
void findTheOnlyOnceNum(vector<int> nums, int& result)
{
    int resultOR = 0;
    for(int num : nums)
    {
        resultOR ^= num;
    }
    result = resultOR;
}

// 如果数组中有两个数字出现两次 find it
void findNumsAppearOnce(vector<int> nums,  int& result_a, int& result_b)
{
    int resoluteOR = 0;
    //先得到一个初步的异或结果
    for(int num : nums)
        resoluteOR ^= num;

    //再分别分组异或
    int indexBit = theFisrtBit1(resoluteOR);
    result_a = result_b = 0;
    for(int num : nums)
    {
        if(isBit1(num, indexBit))
            result_a ^= num;
        else
            result_b ^= num;
    }
}


int main()
{
    vector<int> test_nums_1{1,1,2,2,3,4,4,5,5};
    vector<int> test_nums_2{1,1,2,3,3,5,6,6};

    int result, result_a, result_b;
    findTheOnlyOnceNum(test_nums_1, result);
    findNumsAppearOnce(test_nums_2, result_a, result_b);

    cout << result << endl;
    cout << result_a << " " << result_b << endl;

    return 0;
}

/*
 *  首先这道题限定了时间复杂度和空间复杂度，所以暴力方法和 利用hash表的方法都被排除了
 *  如果只有一个num出现一次，其他出席那两次，那么只要所有元素异或一下就能出来了， 因为自己与自己异或是零
 *  但是如果有两个数都是只出现一次，那么可以排除其他元素，但是可能这两个元素会相互干扰，
 *  我们需要根据异或重新分组，再进行异或，才能找到结果
 *
 */