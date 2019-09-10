

/*
 *  *******************************************
 *  问题描述：破解智力题问题  根游戏掉血一样
 *  问题描述： 每道题都有一个"脑力值门槛"，脑力值达到门槛才能破解这道题
 *  并且破解的过程中，需要消耗部分脑力值，破解顺序没有限制，消耗的脑力值不会恢复。
 *  现在问需要补充多少脑力值，才能破解所有谜题。
 *
 *  输入描述：
 *  第一行： T 表示数据组数
 *  对于每一组数组：
 *      第一行： 两个整数 N, K ,表示当前拥有的脑力值 和 谜题的个数
 *      以后K行，p1 p2两个整数，分别代表每道题的阈值门槛和需要消耗的脑力值
 *
 *  0<T<1000   0<N  K<50000      0<-p1,p2 < 10000
 * 测试用例：
 * 2
 * 0 2
 * 100 50
 * 50 50
 * 150 2
 * 100 50
 * 50 50
 *
 * 输出
 * 100
 * 0
 *  *******************************************
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct trouble{
    int thread =0 ;
    int bleed =0 ;
};

//二维 vector排序的需要
bool mycompT(trouble& p1, trouble& p2){
    return p1.thread < p2.thread;
}

class Solution{
public:
    int function(vector<trouble>& troubles, int& cur_value){
        int needs = 0;
        sort(troubles.begin(), troubles.end(), mycompT);
        while (troubles.size()>0) {
            if (cur_value >= troubles.back().thread) {
                cur_value = cur_value - troubles.back().bleed;
                troubles.pop_back(); //delete the last
            }

            if(troubles.size()>0){ //因为上面弹出了一个元素，所有要再次判断
                if (cur_value < troubles.back().thread) {
                     needs += troubles.back().thread - cur_value;
                     cur_value += needs;
                     continue;
            }
            }
        }
        cout << needs << endl;
        return needs;
    }
};

int main() {
    Solution solution;
    int T;
    int current_Value = 0 ;
    int nums;
    vector<trouble> troubles;
//    trouble troub1, troub2;
//    troub1.thread = 100; troub1.bleed=50;
//    troub2.thread = 50; troub2.bleed=50;
//    troubles.push_back(troub1);
//    troubles.push_back(troub2);

    cin >> T;
    for(int i=0; i<T; i++)
    {
        cin >> current_Value >> nums;
        for(int j=0; j<nums; j++)
        {
            trouble troub;
            cin >> troub.thread >> troub.bleed;
            troubles.push_back(troub);
        }
        solution.function(troubles, current_Value);
    }
//    solution.function(troubles, current_Value);
    return 0;
}



/* *********************************************************
 * 解题思路：
 *
 * 先处理输入，将输入处理一下， 记录每一组 currentValue, 以及每道智力题的阈值和掉血
 * 然后将每一组智力题，按照阈值排序，然后从结尾开始处理 (所以这题用vector比较好)
 *
 * 对于每一组，处理一个弹出一个
 * 每次先判断 currentValue 是否超过阈值，超过了就直接处理，没有的话，需要补充脑力值
 *
 *
 * ----------------------------------
 * 测试示例：
 * 测试用例：
 * 2
 * 0 2
 * 100 50
 * 50 50
 * 150 2
 * 100 50
 * 50 50
 *
 * 输出
 * 100
 * 0
 * *********************************************************
 */