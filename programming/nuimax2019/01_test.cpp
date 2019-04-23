
/* *********************************************************
 * 问题描述：
 *
 *
 * *********************************************************
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> strs;
    int nums;

    cin >> nums;
    for(int i=0; i<nums; i++)
    {
        string temp; cin >> temp;
        strs.push_back(temp);
    }
    sort(strs.begin(), strs.end());
    for(auto str:strs)
        cout << str << endl;
    return 0;
}
/* *********************************************************
 * 解题思路：
 *
 * ----------------------------------
 * 测试示例：
 *
 * *********************************************************
 */