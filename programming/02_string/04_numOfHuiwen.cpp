
/* *********************************************************
 * 问题描述：
  定义回文字符串  例如 “level" "noon"
  若将某个十进制非负数N,转换成二进制后得到二进制序列具有回文性质，称该数位回文数
  例如 9  == 1001 说以9是回文数

  现在输入一个十进制整数N, 计算小于等于N的回文数的数量
  1<= N <= 10^18

 * ----------------------------------
 * 输入示例：
 * 6 --> 3
 *
 * 1 3 5
 *
 * *********************************************************
 */

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution{
public:
    bool isBinHuiwen(long  number) {
        vector<bool> binNum;
        bool bit;
        while (number) //先求二进制
        {
            bit = number & 0x1;
            binNum.push_back(bit); //这个二进制是反的，不过没关系，因为算回文
            number = number >> 1;
        }

        //判断回文
        vector<bool>::iterator front = binNum.begin();
        vector<bool>::iterator back = binNum.end();
        back--;//指向最后一个元素
        while(front < back) {
            if (*front != *back)
                return false;
            front++;
            back--;
        }
        return true;
    }

};

int main() {
    long  number = 80;
//    cin >> number;
    int count = 0;
    Solution solution;
    cout << "the bin huiwei numbers :";
    for(int i = 1; i<= number; i++) {
        bool status = solution.isBinHuiwen(i);
        if (status)
        {
            count++;
            cout << " " << i;
        }
    }
    cout << endl;
    cout<< "the count: " <<count<<endl;
    return 0;
}
