
/* *********************************************************
 * 问题描述：定义二维矩阵乘法
 * A m*n  B n*k
 *
 * *********************************************************
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  //M*N * N*K
  void twoDimMatrixMulit(vector<int>& A, vector<int>& B, vector<int>& AxB, int M, int N, int K){
    for(int m=0; m<M; m++) {
      for (int k = 0; k < K; k++) {
        double temp = 0;
        for(int n=0; n<N; n++) {
          temp += A[m * N + n] * B[n * K + k];  //对应元素相乘 相加
//          cout <<  m * N + n << " * " << n * K + k;
        }
        AxB[m*K+k] = temp; //放到指定位置
      }
    }
  }
};


int main() {
  vector<int> A ;
  vector<int> B;

  int x,y,z;
  cin >> x;
  cin >> y;
  cin >> z;

  for(int i=0; i<x; i++)
    for(int j=0; j<y; j++)
    {
      int temp; cin>>temp;
      A.push_back(temp);;
//       cout << "i*y+j: " << temp;
    }

  for(int i=0; i<y; i++)
    for(int j=0; j<z; j++)
    {
      int temp; cin>>temp;
      B.push_back(temp);
//      cout << "i*z+j: " << temp;
    }

  Solution solution;
  vector<int> AB;
  AB.resize(x*z); //注意初始化AB的尺寸
  solution.twoDimMatrixMulit(A, B, AB, x, y, z);

  for(int i=0; i<x; i++) {
    for (int j = 0; j < z; j++) {
      cout << AB[i*z+j] <<" ";
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