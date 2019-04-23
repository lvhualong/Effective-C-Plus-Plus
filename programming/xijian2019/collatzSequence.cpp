
/* *********************************************************
 * 问题描述：
 * 定义一个 collatzSequence序列
 * 
 * *********************************************************
 */

#include <iostream>
#include <vector>
using namespace std;
bool collatzSequence(const int num, vector<int>& sequence) {
    if(num <= 0) return false ;

    sequence.push_back(num);
    if(num == 1) return  true;

    if(num&0x1) //奇数
        collatzSequence(3*num+1, sequence);
    else
        collatzSequence(num>>1, sequence);
}

int main() {
    vector<int> CollatzSequence;
    int num;
    cin >> num;
    if(num&0x1 == 0) //偶数
        num = num-1;

    bool status = collatzSequence(num, CollatzSequence);
    if (status == true) {
        cout << "the longest size: " << CollatzSequence.size() << endl;
        for (auto num:CollatzSequence)
       cout << " " << num;
    cout << endl;
    }
    return 0;
}

/* *********************************************************
  * 测试示例：
 * 5
 * 5 16 8 4 2 1
 * *********************************************************
 */