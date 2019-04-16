
/* *********************************************************
 * 问题描述：
 *
 *
 * *********************************************************
 */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;


class Solution{
public:
    void function(int num){

    }
};


void mult(const double* A, const double * B, double*AxB, const int M, const int N, const int K) {
    for (int m = 0; m < M; m++) {
        for (int k = 0; k < K; k++) {
            int tmp = 0;
            for (int n = 0; n < N; n++) {
                tmp += A[m*N + n] * B[n*K + k];
            }
            AxB[m*K + k] = tmp;
        }
    }
}
int main() {
    Solution solution;

    std::cout << " " << std::endl;

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