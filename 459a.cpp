#include <iostream>
using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int a, b;
  if (x1 == x2) {
    a = y1 - y2;
    if (a < 0)
      a = -a;
    if (x1 + a <= 1000) {
      cout << x1+a << ' ' << y1 << ' ';
      cout << x1+a << ' ' << y2 << endl;
    }
    else if (x1 - a >= -1000) {
      cout << x1-a << ' ' << y1 << ' ';
      cout << x1-a << ' ' << y2 << endl;
    }
    else {
      cout << -1 << endl;
    }
  }
  else if (y1 == y2) {
    a = x1 - x2;
    if (a < 0)
      a = -a;
    if (y1 + a <= 1000) {
      cout << x1 << ' ' << y1+a << ' ';
      cout << x2 << ' ' << y1+a << endl;
    }
    else if (y1 - a >= -1000) {
      cout << x1 << ' ' << y1-a << ' ';
      cout << x2 << ' ' << y1-a << endl;
    }
    else {
      cout << -1 << endl;
    }
  }
  else {
    a = x1 - x2;
    if (a < 0)
      a = -a;
    b = y1 - y2;
    if (b < 0)
      b = -b;
    if (a == b) {
      cout << x1 << ' ' << y2 << ' ';
      cout << x2 << ' ' << y1 << endl;
    }
    else {
      cout << -1 << endl;
    }
  }

  return 0;
}

