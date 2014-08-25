#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> k(n, 0);
  for (int i = 0; i < n; i++)
    cin >> k[i];

  int t = 51500;
  int m;
  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = 0; j < k[i]; j++) {
      cin >> m;
      s += m;
    }
    s = 5*s+15*k[i];
    if (s < t)
      t = s;
  }

  cout << t << endl;

  return 0;
}
