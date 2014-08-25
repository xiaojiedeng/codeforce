#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  vector<int> V;

  for (int i = 1; i < 9*9; i++) {
    double x = 1;
    for (int j = 0; j < a; j++)
      x *= i;
    x = x*b + c;
    if (x >= 1000000000)
      continue;
    int n = 0;
    int y = x;
    int z = x;
    while (y > 0) {
      n += y%10;
      y /= 10;
    }
    if (n == i)
      V.push_back(z);
  }

  sort(V.begin(), V.end());
  cout << V.size() << endl;
  for (int i = 0; i < V.size(); i++)
    cout << V[i] << ' ';
  cout << endl;
  return 0;
}
