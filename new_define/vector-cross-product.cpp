
/*
 * 利用叉乘性质，进行一些点和线的判断
 *  叉乘 不仅与两个方向的向量都垂直，而且可以确定它的方向 所以 AxB = -BxA
 *
 * 1. 判断 一个点在直线左边还是右边
 * 2. 判断两条线段是否相交
 * 3. 判断一个点在三角形内还是三角形外
 *
 * https://blog.csdn.net/qiushangren/article/details/90475707
 *
 * 判断点的话，先以线段为端点，叉乘判断一下
 * 判断线段相交，先以ab为基准，判断一下c d点，再以线段cd为基准，判断一下a b点
 * 判断三角形的话，以ab为基准判断p, 以bc为基准判断p, 以ca为基准判断p, 这三个要是正都是正，要是负都是负， 如果有一个为0,说明在三角形上
 */

#include<iostream>

using namespace std;

typedef struct
{
  float x;
  float y;
} tPoint;

// ab x ap 在z轴的方向
// | i   j   k |
// | Ax  Ay  0 |
// | Bx  By  0 |
float cross(const tPoint &a, const tPoint &b, const tPoint &p)
{
  return (b.x - a.x)*(p.y - a.y) - (b.y - a.y)*(p.x - a.x);
}


bool toLeft(const tPoint &a, const tPoint &b, const tPoint &p)
{
  return cross(a, b, p) > 0;
}

bool isLineSegment(const tPoint &a, const tPoint &b, const tPoint &c, const tPoint &d)
{
  float  a1 = cross(a, b, c);
  float  a2 = cross(a, b, d);
  if(a1*a2 <0)
  {
    float c1 = cross(c, d, a);
    float c2 = cross(c, d, b);
    // float c2 = c1 + a2 - a1;
    if(c1*c2 <0)
      return true;
  }
  return false;
}


int inTriangle( const tPoint &a, const tPoint &b, const tPoint &c, const tPoint &p)
{
    float ap = cross(a, b, p);
    float bp = cross(b, c, p);
    float cp = cross(c, a, p);

    if(ap==0 ||bp==0 ||cp==0)
      return -1; //在三角形上

    if(ap*bp >0 && ap*cp >0)
      return 1; //在三角形内
    else
      return  0;

}



int main()
{
  tPoint p0, p1, p2, p3;
  cin >> p0.x;
  cin >> p0.y;
  cin >> p1.x;
  cin >> p1.y;
  cin >> p2.x;
  cin >> p2.y;
  cin >> p3.x;
  cin >> p3.y;

  cout << "is p2 in the left of p0p1 ? " << toLeft(p0, p1, p2) << endl;
  cout << "is p2p3 cross with p0p1 ? " << isLineSegment(p0, p1, p2, p3) << endl;
  cout <<  "is p3 in the triangle inter? " << inTriangle(p0,p1,p2,p3) << endl;
  return 0;

}