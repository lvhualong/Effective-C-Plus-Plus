#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int result(int n, int m, int k)
{
  if(n < m)
    swap(n, m);
//  int dp[n][n];
  int min_sum = n+m;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    {
      long temp = (n-i)*(m-j);
      if(temp <= k)
      {
        int current_sum = i+j;
        if(current_sum < min_sum)
          min_sum = current_sum;
      }
    }
  return min_sum;
}

int result_2(int n, int m, int k)
{
  if(n < m)
    swap(n, m);
  int value = m*n-k;
  int min_sum = n+m;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    {
      long temp = n*i + m*j;
      if(temp >= value)
      {
        int current_sum = i+j;
        if(current_sum < min_sum)
          min_sum = current_sum;
      }
    }
  return min_sum;
}


int main() {

  long n=12,m=18,k=100;
  cin >> n >> m >> k;

  int output = result(n, m, k);
  cout << output << endl;

  return 0;

}