
/* *********************************************************
 * 问题描述：
 *
 * 
 * *********************************************************
 */

#include <iostream>
#include <vector>
#include <list>   //容易删改 方便前后删除
#include <deque>
using namespace std;

struct Point {
    double x, y;
};
struct BoundingBox {
    Point top_left, lower_right;
};

bool mycompX(Point& p1, Point& p2){
return p1.x < p2.x;
}
bool mycompY(Point& p1, Point& p2){
return p1.y < p2.y;
}


void CalBoundingBox(const std::vector<Point> &pts, BoundingBox *bb) {
    double min_x, max_y,   max_x, min_y;

    pts.sort(pts.begin(), pts.end(), mycompX);  //x 维度排序
    min_x = pts[0].x;
    max_x = *(pts.end()-1).x;

    pts.sort(pts.begin(), pts.end(), mycompY); //y 维度排序
    max_y =pts[0].y;
    min_y = *(pts.end()-1).y;


    bb->top_left.x = min_x;
    bb->top_left.y = max_y;
    bb->lower_right.x = max_x;
    bb->lower_right.y = min_y;

}

int main() {
    vector<Point>

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