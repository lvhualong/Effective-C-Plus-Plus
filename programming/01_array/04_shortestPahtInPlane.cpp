
/*
 * **********************************************
 * 华为笔试第2题： 从原点出发到平面上5点的最短距离
 *
 * 以蜂巢为平面原点的5片花丛A B C D E的坐标，
 * 从出发到返回蜂巢最短路径的长度取整数，丢弃小数点后面的整数
 *
 * 测试用例：
 * 输入:
 * 200 0 200 10 200 50 200 30 200 25
 *
 * 输出：
 * 456
 * *********************************************
 */
#include <iostream>
#include <cmath> //sqrt  pow
#include <vector>
#include <algorithm> //next_permutation 全排列算法
using namespace std;

typedef pair<int,int>  coordinate;

class Solution {
public:
    //算一个排列的路径长度
    int onePath(const vector<coordinate> points)
    {
        int cost = distanceTowPoints(pair<int,int>(0,0),points.front()); //原点到第一个点
        for(int i=0; i<points.size()-1; i++)
            cost += distanceTowPoints(points[i], points[i+1]);
        cost += distanceTowPoints(pair<int,int>(0,0),points.back()); //最后一个点回到原点
        return cost;
    }

    int minPath(vector<coordinate> points){
         int minCost=100000;
         sort(points.begin(),points.end()); //先排序
         while(next_permutation(points.begin(),points.end())) //遍历全排列
         {
             int costPath = onePath(points);
             if(costPath < minCost)
                 minCost = costPath;
         }
         return minCost;
    }

private:
    //求两个点的距离 取整
    int distanceTowPoints(const coordinate& point1, const coordinate& point2)
    {
        return (int)sqrt(pow((point1.first-point2.first),2) + pow((point1.second-point2.second),2));
    }


};

int main()
{
//    200 0 200 10 200 50 200 30 200 25
    vector<pair<int,int>> points(5);
//    points.push_back(pair<int,int>(200,0));
//    points.push_back(pair<int,int>(200,10));
//    points.push_back(pair<int,int>(200,50));
//    points.push_back(pair<int,int>(200,30));
//    points.push_back(pair<int,int>(200,25));
    for(int i=0; i<5; i++){ //注意这种方式下标引用，一定要想分配内存空间
        cin >> points[i].first >> points[i].second;
    }

    Solution solution;
    int minPathCost = solution.minPath(points);

    cout << "the min path cost is " << minPathCost << endl;
    return 0;
}

/*
 * *************************************************
 * 测试示例:
 *
 * 200 0 200 10 200 50 200 30 200 25
 * 456
 *
 * 解题思路：
 * 总共只有5个点，所以可以采用全排列，遍历排列中的每一种情况
 * 原点 0 0 作为一个特殊的点，从这个点出发，最后回到这个点
 *
 *
 * 实现： 先实现一个计算两点距离并取整的函数
 * 然后写一个排列中一种情况的路径
 * 最后使用全排列算法，next_next_permutation 遍历所有情况，取最小的那个
 * *************************************************
 */

