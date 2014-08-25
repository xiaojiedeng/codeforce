#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int t;
  int xa, ya, xb, yb;
  bool flag = false;
  for (xa = 1; xa < a-1; xa++) {
    t = a*a-xa*xa;
    ya = round(sqrt(t));
    if (t != ya*ya)
      continue;

    double c = -1.0*xa/ya;
    xb = -round(sqrt(1.0*b*b/(1.0+c*c)));
    yb = round(c*xb);
    if (xb*xb+yb*yb != b*b)
      continue;

    if (xa == xb || ya == yb)
      continue;

    flag = true;
    break;
  }

  if (flag) {
    cout << "YES" << endl;
    cout << 0 << " " << 0 << endl;
    cout << xa << " " << ya << endl;
    cout << xb << " " << yb << endl;
  }
  else {
    cout << "NO" << endl;
  }

  return 0;
}
