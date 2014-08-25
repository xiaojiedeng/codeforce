#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int a, b, t;
  int m = 1;

  cin >> a >> b;
  if (a < b) {
    t = b;
    b = a;
    a = t;
    m = 2;
  }

  for (int i = 3; i <= n; i++) {
    cin >> t;
    if (t >= a) {
      b = a;
      a = t;
      m = i;
    }
    else if (t >= b) {
      b = t;
    }
  }

  cout << m << ' ' << b << endl;
  return 0;
}
  
