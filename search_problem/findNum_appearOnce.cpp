//
// Created by hualong on 2019/3/30.
// 题目来源：剑指offer

/*
 *  首先这道题限定了时间复杂度和空间复杂度，所以暴力方法和 利用hash表的方法都被排除了
 *  如果只有一个num出现一次，其他出席那两次，那么只要所有元素异或一下就能出来了， 因为自己与自己异或是零
 *
 *  但是如果有两个数都是只出现一次，那么可以排除其他元素，但是可能这两个元素会相互干扰，
 *  我们需要根据异或重新分组，再进行异或，才能找到结果
 *
 */

/*
 *  part1: 只有其中一个出现过奇数次，其他出现过偶数次
 *
 *  使用异或操作就能找出
 */


/*
 * part2: 其中两个出现过奇数次，其他出现过偶数次
 *  先异或，再分组
 */

/*
 * part3: 其中一个出现过一次，其他出现过三次
 *  出现三次不像前面出现两次，我们可以使用异或，
 *  出现三次我们要从二进制思考，看如何想办法了
 *
 *  int 型数组占4个字节，总共32位
 *  我们定义一个长度为32的数组，我们把每一个数 按照二进制进行相加，
 *  如果哪一位能够被3整除，说明它出现了三次，如果不能被3整除，说明它出现了两次
 */


#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

//part1 如果数组中仅有一个数字出现两次 find it------------------------------------------------
void findTheOnlyOnceNum(vector<int> nums, int& result)
{
    int resultOR = 0;
    for(int num : nums)
    {
        resultOR ^= num;
    }
    result = resultOR;
}

//part2 数组中有两个数字出现一次---------------------------------------------------------------

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


// part3 其中一个数出现一次，其他数都出现三次 ----------------------------------------
int findNumAppearOnce(vector<int> nums)
{
    vector<int> bitSum(32);
    for(int num : nums)
    {
        for(size_t i=0; i<bitSum.size(); i++)
        {
            bitSum[i] += (num>>i) & 0x1;
        }
    }

    int result = 0;
    for(size_t j=0; j<bitSum.size(); j++)
    {
        if(bitSum[j]%3 != 0)
            result = result | 1 << j; //1左移j位后 或在原来的结果上
    }
    return  result;
}


int main()
{
    vector<int> test_nums_1{1,1,2,2,3,4,4,5,5};
    vector<int> test_nums_2{1,1,2,3,3,5,6,6};
    vector<int> test_3{1,1,1,8,3,3,3};

    int result, result_a, result_b;
    findTheOnlyOnceNum(test_nums_1, result);
    findNumsAppearOnce(test_nums_2, result_a, result_b);

    cout << result << endl;
    cout << result_a << " " << result_b << endl;

    int result_3 = findNumAppearOnce(test_3);
    cout << "the result: " << result_3 << endl;
    return 0;
}
