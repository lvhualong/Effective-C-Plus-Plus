
/*
 *  ************************************************
 *  问题描述： 大数的整形数组处理
 *  给定两个整形数组，数组中每个元素都是 0 - 9的整数
 *  定义两个数组的加法
 *
 *  A[1, 2, 3, 6]
 *  B[2, 3, 4, 5]
 *
 * 输出
 * C[3, 5, 8, 1]
 *  ************************************************
 */
#include <iostream>
#include<vector>
#include<deque>
using namespace std;

deque<int> bigNumAdd(vector<int>& numA, vector<int>& numB) {
    deque<int> sum;
    //为了方便处理，保证 A的长度 大于等于B
    if(numA.size() < numB.size()){
        vector<int> temp = numA;
        numA = numB;
        numB = temp;
    }
    int Alength = numA.size(), Blength = numB.size();
    int flag = 0; //进位标志
    int sumBit = 0; //一位求和
    while(Alength >0)
    {
        //B 短的字符串是否已经计算完了
        if(Blength > 0)
             sumBit = numA[Alength-1] + numB[Blength-1]+flag;
        else sumBit = numA[Alength-1] +flag;

        //是否进位
        if(sumBit>=10){
            sumBit = sumBit%10;
            flag = 1;
        } else flag = 0;

        sum.push_front(sumBit);
        Alength--; Blength--;
    }
    if(flag == 1) //最后一位是否进位
        sum.push_front(flag);
    return sum;
}

int main()
{
    vector<int> a{9,2,7};
    vector<int> b{7,5};
    deque<int> sum_value;
    sum_value = bigNumAdd(a,b);

    for(auto value:sum_value)
        cout << value << " ";
    return 0;
}

/*
 *  *******************************
 *  问题分析
 *  虽说是一个整形数组的加法定义，实则跟字符串加法定义十分类似
 *
 *  2 2 7
 *  7 5
 *  ==> 3 0 2
*  9 2 7
 *  7 5
 *  ==> 1 0 0 2
 * *******************************
 */