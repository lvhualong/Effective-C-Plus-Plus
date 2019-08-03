//
// Created by LAB540 on 2019/8/3.
//

// 面试题56（二）：数组中唯一只出现一次的数字
// 题目：在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。请
// 找出那个吃出现一次的数字。

#include <iostream>
#include <vector>

using  namespace std;

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
    vector<int> test{1,1,1,8,3,3,3};

    int result = findNumAppearOnce(test);
    cout << "the result: " << result << endl;
    return 0;
}






/*
 *  出现三次不像前面出现两次，我们可以使用异或，
 *  出现三次我们要从二进制思考，看如何想办法了
 *
 *  int 型数组占4个字节，总共32位
 *  我们定义一个长度为32的数组，我们把每一个数 按照二进制进行相加，
 *  如果哪一位能够被3整除，说明它出现了三次，如果不能被3整除，说明它出现了两次
 */