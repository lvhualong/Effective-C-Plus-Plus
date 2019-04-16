
/*
 * **********************************************
 * 华为笔试第3题： 二维平面切水果游戏
 *
 * 已知屏幕由40*50小方格组成，经过每个方格画出的直线最多有四条
 * 左上角坐标为(0,0)  右下角坐标为(39,49)
 *
 *第一行输入整数 N (0<N<=36)
 * 下面每行表示点的 x y 值
 * 测试用例：
 * 输入:
 * 2
 * 3 4
 * 2 2
 *
 * 输出：
 * 2
 *
 *
 * *********************************************
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

//定义一个二维点
struct Point{
    int x,y;
};

class Solution {
public:
    // 动态规划的思路
    int min_cut(vector<Point>& pts) {
        if (pts.size() <= 1)
            return pts.size();
        Point first = pts[0]; //取第一个元素
        vector<Point> row_cut, col_cut, left_cut, right_cut; //分别横竖左右切一刀之后的vector

        //横切
        for (auto point : pts) {
            if (point.y != first.y)
                row_cut.push_back(point);
        }
        int rowCount = min_cut(row_cut);

        //竖切
        for (auto point : pts) {
            if (point.x != first.x)
                col_cut.push_back(point);
        }
        int colCount = min_cut(col_cut);

        //左切
        for (auto point : pts) {
            if ((point.x - point.y) != (first.x - first.y))
                left_cut.push_back(point);
        }
        int leftCount = min_cut(left_cut);

        //右切
        for (auto point : pts) {
            if ((point.x + point.y) != (first.x + first.y))
                right_cut.push_back(point);
        }
        int rightCount = min_cut(right_cut);

        return  1+ min(min(min(rowCount, colCount), leftCount), rightCount); //选择四种切法总最优的
        //从这可以看出是动态规划了，K刀是最优的切法，那么当前选一个最优的，再结合K-1刀是最优的解，那么整个就是最优的
    }
    //贪心算法的思路：
    int greedy_cut(vector<Point>& pts){
        unordered_set<int> row, col, left, right;
        multiset<int> rowMul, colMul, leftMul, rightMul;

        for(auto point:pts)
        {
            //或者在这统计此处
            row.insert(point.y); rowMul.insert(point.y);
            col.insert(point.x); colMul.insert(point.x);
            left.insert(point.x-point.y); leftMul.insert(point.x-point.y);
            right.insert(point.x+point.y); rightMul.insert(point.x+point.y);
        }
        int min_value = min(min(min(row.size(), col.size()),left.size()),right.size());//看哪一刀切下去能消的最多

        //下面该分析执行这一刀之后，不断地递归
        if(min_value == row.size())
            //


    }
};

int main()
{
    int num;
    cin >> num;
    vector<Point> points(num);
    for(int i=0; i<num; i++)
        cin >> points[i].x >> points[i].y;

    Solution solution;
    cout << "The min cut Count: " << solution.min_cut(points) << endl;

    return 0;
}

/*
 * *************************************************
 * 解题思路：
 * 没有头绪，先用数学归纳法，从一般到特殊推
 * 1. 先画出一些方格， 横轴x轴，纵轴y轴 40*50的矩阵
 * 发现  每次横切 y坐标都是一样的， 竖切 x坐标都是一样的
 * 然后看左斜切 x-y都是一样的， 右斜切 x+y的坐标都是一样的
 *
 * 采用动态规划方法求解：
 * 对于一个点， 四种切法去除被切掉的点，即可获得下一次的点集，count+1即可
 *
 * 采用贪心算法 也可以做，要多举几个例子，仔细分析
 * 贪心算法 就想着每一步都采取一个最优策略
 * 可以构造四个 vector 分别存 x,y, x-y, x+y
 *
 * 测试示例:
 * 2
 * 3 4
 * 2 2
 *
 * *************************************************
 */

