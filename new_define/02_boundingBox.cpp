
/* *********************************************************
 * 问题描述：
 *
 * 
 * *********************************************************
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    double x, y;
    Point(double a, double b): x(a),y(b) {}
};
struct BoundingBox {
    Point top_left, lower_right;
    BoundingBox(Point pa, Point pb):top_left(pa),lower_right(pb){}
};

bool mycompX(Point& p1, Point& p2){
return p1.x < p2.x;
}
bool mycompY(Point& p1, Point& p2){
return p1.y < p2.y;
}



void CalBoundingBox(vector<Point>& pts, BoundingBox *bb) {
    double min_x=INT64_MAX, max_y=INT64_MIN,   max_x=INT64_MIN, min_y=INT64_MAX;
    for(auto point:pts)
    {
        if(point.x > max_x)  max_x = point.x;
        if(point.x < min_x)  min_x = point.x;

        if(point.y > max_y) max_y = point.y;
        if(point.y < min_y) min_y = point.y;
    }
    bb->top_left.x = min_x;  // 注意要为外面的指针分配所指对象，不然就是野指针了
    bb->top_left.y = max_y;
    bb->lower_right.x = max_x;
    bb->lower_right.y = min_y;

    //直接用二维数组排序做的
//    sort(pts.begin(), pts.end(), mycompX);  //x 维度排序
//    bb->top_left.x = pts.front().x;
//    bb->lower_right.x = pts.back().x;
//
//    sort(pts.begin(), pts.end(), mycompY); //y 维度排序
//    bb->top_left.y = pts.back().y;
//    bb->lower_right.y = pts.front().y;

    return;
}

int main() {
    vector<Point> Points;
    Points.push_back(Point(1,3));
    Points.push_back(Point(0,0));
    Points.push_back(Point(2,3));
    Points.push_back(Point(3,0));

    BoundingBox *box = new BoundingBox(Point(0,0),Point(0,0));
    CalBoundingBox(Points, box);

    cout << "The left top: " << box->top_left.x << " " << box->top_left.y << endl;
    cout << "The right lowest: " << box->lower_right.x << " " << box->lower_right.y << endl;

    delete box;
    return 0;
}
/* *********************************************************
 * 解题思路：
 *  想到的思路一：分别对二维数组的的x维度，y维度 排序，取 x的最值、y的最值
 *
 *  如果限定了const 的序列，那么就直接遍历一遍，求出四个最值
 *
 *  最后给指针复制即可，
 *  注意指针所指对象
 *
 * ----------------------------------
 * 测试示例：
 *  1 3  0 0 2 3  3 0
 *
 * *********************************************************
 */