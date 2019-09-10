
/* *********************************************************
 * 问题描述： 有限域问题
 *
 * 抽象代数中的有限域定理： 存在一个大小为q的有限域 当且仅当q是某个素数p的方幂， q= p^k  k>=1
 * 在同构意义下，相同大小的有限域只有一个，
 * 现在写一个程序，计算同构意义下不同有限域个数，对于一个给定输入n, 计算有多少个不同构的有限域，它们大小不超过n 的
 * ----------------------------------
 * 输入示例：
 * 1  -> 0
 * 37 -> 19
 * 【n=37  以下19个数可以表示成某个素数的方幂：2 3 4 5 7 8 9 11 13 16 19 23 25 27 29 31 32 37】
 * *********************************************************
 */

#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution{
public:
    int countPrime(int num){
        int count = 0 ;
        unordered_set<int> prime;
        if(num < 2) return 0;

        for(int i=2; i<=num; i++){
            if(isPrime(i)){
                cout << i << " ";
                if(prime.count(i) < 1) //如果哈希表中还没有
                    count++;
                prime.insert(i); //先将素数放入hash表中
                for(int prime_pow = i; prime_pow<num; prime_pow *= i)//判断素数的平方是不是在范围内
                    if(prime.count(prime_pow) < 1) //如果哈希表中还没有
                    {
                        cout << prime_pow << " ";
                        prime.insert(prime_pow); //将素数的方幂放入
                        count++;
                    }
                }
            }
        cout << endl;
        return count;
    }

private:
    bool isPrime(int num)//判断一个数是否为素数
    {
        if(num<2) return false;
        for(int i=2; i<(num/2); i++)
            if(num%i == 0) return false;
        return true;
    }

    bool isPrime_1(int num)
    {
        if(num<2) return false;
        for(int i=2; i<=(int)sqrt(num); i++)
            if(num%i == 0) return false;
        return true;
    }


};

int main() {

    int num = 37;
    Solution solution;
    cout << " the num: " << solution.countPrime(num) << endl;

    return 0;

}
/* *********************************************************
 * 解题思路：
 *
 * 翻译这道题，就是输入一个n 找出不大于n的素数和素数的方幂
 * 在num范围内
 * 先找素数
 * 再找素数的方幂
 *
 *  isPrime       循环使用 (int i=2; i<=(int)sqrt(num); i++)
 *  isPrime       循环使用 (int i=2; i<(num/2); i++)
 *
 * ----------------------------------
 * 测试示例：
 *  37
 *
 *
 * *********************************************************
 */