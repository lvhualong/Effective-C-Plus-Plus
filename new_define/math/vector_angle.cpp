//
// Created by hualong on 2019/4/27.
//

/*
 * 判断两个向量之间的夹角，请注意是[0,2PI], 还是[-PI, PI]
 */


#include <iostream>
#include <cmath>

using namespace std;

struct point
{
  int x;
  int y;
};

float getAngelOfTwoVector(point &pt1, point &pt2)
{
  float theta = atan2(pt1.x , pt1.y) - atan2(pt2.x , pt2.y);
  if (theta > M_PI)
    theta -= 2 * M_PI;
  if (theta < -M_PI)
    theta += 2 * M_PI;

  theta = theta * 180.0 / M_PI;
  if(pt2.y <=0)
    return theta+360;
  else;
  return theta;
}


double theta(point& a, point& b)
{
   double result = 0;
   int up = (a.x*b.x + a.y*b.y);
   double down = sqrt(a.x*a.x +a.y*a.y);
   double  theta = up/down;
//   cout << theta << endl;
   result = acos(theta);


   if(a.y <0  )
   return  (2*M_PI-result)*180/M_PI;

  else
    return  result*180/M_PI;
}


int main()
{
  point a, b;
  b.x = 1;
  b.y = 0;
  cin >> a.x;
  cin >> a.y;


  cout << getAngelOfTwoVector(b, a) << endl;
}
