
/* *********************************************************
 * 问题描述：
 *
 *
 * *********************************************************
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int hammingDistance(const vector<bool>& num1, const vector<bool>& num2) {
        int count = 0;
        if (num1.size() != num2.size())
            return 0;
        for (int i = 0; i < num1.size(); i++) {
            if (num1[i] ^ num2[i])
                count++;
        }
        return count;
    }
};

int main() {
    vector<bool> Num1{1,1,0,0,1,0};
    vector<bool> Num2{0,1,0,0,1,1};
    Solution solution;
    int Count = solution.hammingDistance(Num1, Num2);
    cout << "Hanming distance: " << Count << endl;
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