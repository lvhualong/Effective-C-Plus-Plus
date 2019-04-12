
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
            bit = number & 1;
            number = number >> 1;
            binNum.push_back(bit);
//            cout << bit << " ";
        }
//        cout << endl;
        //判断回文
        vector<bool>::iterator front = binNum.begin();
        vector<bool>::iterator back = binNum.end()-1;
        while(front++ <= back--) {
            if (*front != *back)
                return false;
        }
        return true;
    }


};

int main() {
    long  number = 10;
//    cin >> number;
    int count = 1;
    Solution solution;
    while(number){
        if(solution.isBinHuiwen(number) == true) {
            count++;
            cout << number  << " is a huiwen number" << endl;
        }
        number--;
    }
    cout << "the bin huiwei number:";
    cout<<count<<endl;
    return 0;
}
