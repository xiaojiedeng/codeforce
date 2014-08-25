#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  int d = 0;
  int c = n;
  int r = 0;

  while (c > 0) {
    d += c;
    n = c + r;
    c = n / m;
    r = n % m;
  }

  cout << d << endl;
}
