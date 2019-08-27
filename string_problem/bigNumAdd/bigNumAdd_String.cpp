

/*
 *
 *  大数加法的 string形式
 */

#include <string>
#include <iostream>

using namespace std;

string bigNumAdd_String(string& stringA, string& stringB)
{
    //保证A长度大于等于B
    if(stringA.size() < stringB.size()){
        string temp = stringA;
        stringA = stringB;
        stringB = temp;
     Alength = stringA.size(), Blength = stringB.size();
    }

    int flag = 0, sumBit = 0, a,b;
    while (Alength>0){
        a = stringA[Alength-1] - '0';
        //判断短字符串是否结束
        if(Blength>0)
            b = stringB[Blength-1] - '0';
        else b = 0;
        sumBit = a+b+flag;
        //判断是否有进位
        if(sumBit>=10){
            sumBit = sumBit%10;
            flag = 1;
        } else flag = 0;

        //写入字符串A中
        stringA[Alength-1] = sumBit+'0';
        Alength--, Blength--;
    }
    if(flag == 1)//如果最高位进位，长度会增加1
        stringA = "1"+stringA;
    return  stringA;
}


int main()
{
    string stringNum1 = "999";
    string stringNum2 = "11111";
    string result = bigNumAdd_String(stringNum1, stringNum2);
    cout << result << endl;
    return 0;
}

/*
 * 解题思路：
 * 1 先保证 A长度不小于B
 *
 * 2 从末尾开始，根据A长度递减循环
 *      注意判断B是否结束
 *      注意判断是否有进位
 *      写入字符串A
 *      下标左移
 *    注意最高位的标志位，如果进位了，前面要加个1
 *
 * 测试用例：
 * 98765
 * 11111
 * ----------
 * 109876
 *
 * 999
 * 11111
 * -------
 * 12110
 *
 */