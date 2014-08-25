#include <iostream>
using namespace std;

int main() {
  int N, M;
  int x, y, z;
  int p;

  cin >> N >> M;
  cin >> x >> y >> z;
  cin >> p;

  x %= 4;
  y %= 2;
  z %= 4;
  int i, j, t, n, m;
  while (p--) {
    cin >> i >> j;
    n = N; m = M;
    switch (x) {
    case 1:
      t = j;
      j = n+1-i;
      i = t;

      t = n;
      n = m;
      m = t;
      break;
    case 2:
      i = n+1-i;
      j = m+1-j;
      break;
    case 3:
      t = i;
      i = m+1-j;
      j = t;

      t = n;
      n = m;
      m = t;
      break;
    }
    //cout << "1: " << i << " " << j << endl;

    if (y == 1)
      j = m+1-j;
    //cout << "2: " << i << " " << j << endl;

    switch (z) {
    case 3:
      t = j;
      j = n+1-i;
      i = t;
      break;
    case 2:
      i = n+1-i;
      j = m+1-j;
      break;
    case 1:
      t = i;
      i = m+1-j;
      j = t;
      break;
    }
    //cout << "3: " << i << " " << j << endl;

    cout << i << ' ' << j << endl;
  }
  return 0;
}
