
/* *********************************************************
 * 问题描述：
// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。
 * ----------------------------------
 * 输入示例：
 * 3
 *
 * 1 2 3 …… 999
 *
 * *********************************************************
 */

#include <iostream>
#include <cstring>

using namespace std;

class Solution{
public:
    void print1ToMaxNum(int& n){
        char* numStr = new char[n+1]; //申请字符串数组
        //初始化
        memset(numStr, '0', n);
        numStr[n] = '\0';

        while(!increment(numStr))
            printNum(numStr);
        cout << endl;
        delete[] numStr;
    }
private:
    bool increment(char* number){
        bool isOverflow = false;//字符串溢出结束的标志
        int nTakeover = 0;  //是否进位
        int nLength = strlen(number);
        int currentNum = number[nLength-1] - '0';
        if(++currentNum >=10) //进位了
        {
            nTakeover = 1;
            for(int i=nLength-2; i>0; i--){
                int nSum = number[i]-'0'+nTakeover;
                if(nSum >=10) //前一位又进位了
                {
                    if(i==0)  isOverflow = true; //最高位进位了
                    nTakeover = 1;
                    continue;
                } else break;
            }
            number[nLength-1] = '0';
        }
        else number[nLength-1] = currentNum + '0'; //没有进位
        return isOverflow;
    }

    void printNum(char* number){
        bool isBeginning0 = true;//前面都是零元
        int nLength = strlen(number);
        for(int i=0; i<nLength; i++){
            if(isBeginning0 && number[i]!='0') //找出第一个非零元
                isBeginning0 = false;
            if(!isBeginning0)
                cout << number[i] ;
        }
        cout << " ";
    }

};

int main() {

    int num_length = 2;
    Solution solution;
    solution.print1ToMaxNum(num_length);

    return 0;

}
/* *********************************************************
 * 解题思路：
 * 字符串数组解法，申请一个字符串(length=n+1) 存储字符串
 * 每次类似于比分翻牌子似的 每次字符串+1
 * 打印字符串
 *
 * ----------------------------------
 * 测试示例：
 *
 * *********************************************************
 */