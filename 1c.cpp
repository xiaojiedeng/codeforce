#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  double x1, y1;
  double x2, y2;
  double x3, y3;
  cin >> x1 >> y1;
  cin >> x2 >> y2;
  cin >> x3 >> y3;

  double a, b;
  double x0, y0;
  a = ((x1-x2)*(y1-y3)-(x1-x3)*(y1-y2))*2;
  if (a != 0) {
    b = (x1*x1-x2*x2+y1*y1-y2*y2)*(y1-y3) - (x1*x1-x3*x3+y1*y1-y3*y3)*(y1-y2);
    x0 = b/a;
    if (y1 != y2)
      y0 = (x1*x1-x2*x2+y1*y1-y2*y2-2*x0*(x1-x2))/(y1-y2)/2;
    else
      y0 = (x1*x1-x3*x3+y1*y1-y3*y3-2*x0*(x1-x3))/(y1-y3)/2;
  }
  else {
    a = ((y1-y2)*(x1-x3)-(y1-y3)*(x1-x2))*2;
    b = (x1*x1-x2*x2+y1*y1-y2*y2)*(x1-x3) - (x1*x1-x3*x3+y1*y1-y3*y3)*(x1-x2);
    y0 = b/a;
    if (x1 != x2)
      y0 = (x1*x1-x2*x2+y1*y1-y2*y2-2*y0*(y1-y2))/(x1-x2)/2;
    else
      y0 = (x1*x1-x3*x3+y1*y1-y3*y3-2*y0*(y1-y3))/(x1-x3)/2;
  }

  double x01, x02, x03, y01, y02, y03;
  x01=x0-x1, y01=y0-y1;
  x02=x0-x2, y02=y0-y2;
  x03=x0-x3, y03=y0-y3;

  double c1, c2, c3, r;
  r = sqrt(x01*x01+y01*y01);
  c1 = acos((x01*x02+y01*y02)/r/r);
  c2 = acos((x02*x03+y02*y03)/r/r);
  c3 = acos((x03*x01+y03*y01)/r/r);

  const double PI = 3.1415926535;
  const double ERR = 1e-6;
  int i;
  for (i = 3; i <= 100 ; i++) {
    double t = 2*PI/i;
    int j;
    for (j = 1; j < i; j++)
      if (abs(t*j-c1) < ERR)
        break;
    if (j == i)
      continue;

    for (j = 1; j < i; j++)
      if (abs(t*j-c2) < ERR)
        break;
    if (j == i)
      continue;

    for (j = 1; j < i; j++)
      if (abs(t*j-c3) < ERR)
        break;
    if (j == i)
      continue;

    break;
  }


  double area = r*r*sin(2*PI/i)*i/2;

  //cout << x0 << '\t' << y0 << '\t' << i << '\t' << area << endl;

  cout << fixed << setprecision(8) << area << endl;

  return 0;

}

