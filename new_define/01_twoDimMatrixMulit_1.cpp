
/* *********************************************************
 * 问题描述：定义二维矩阵乘法
 * A m*n  B n*k
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
    //M*N * N*K
    void twoDimMatrixMulit(const double* A, const double* B, double* AxB, int M, int N, int K){
        for(int m=0; m<M; m++) {
            for (int k = 0; k < K; k++) {
                double temp = 0;
                for(int n=0; n<N; n++)
                    temp += A[m*N+n]*B[n*K+k];  //对应元素相乘 相加
                AxB[m*K+k] = temp; //放到指定位置
            }
        }
    }
};


int main() {
    const double A[] = {1,2,3,4,5,6};
    const double B[] = {1,2,3,4,5,6};
    Solution solution;
    double *AB;
    solution.twoDimMatrixMulit(A, B, AB, 3, 2, 3);

    for(int i=0; i<3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << AB[i*3+j];
        }
        cout << endl;
    }
    return 0;

}
/* *********************************************************
 * 解题思路：
 * 矩阵乘法
 *  屡清楚 相乘相加的维度
 *  以及对应输出后的维度
 * ----------------------------------
 * 测试示例：
 * 1 2
 * 3 4
 * 5 6
 *
 * 1 2 3
 * 4 5 6
 *
 * 输出：
 *  9 12 15
 *  19 26 33
 *  29 40 51
 * *********************************************************
 */