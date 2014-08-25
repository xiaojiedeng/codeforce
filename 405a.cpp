#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> V(n, 0);

  for (int i = 0; i < n; i++)
    cin >> V[i];
  sort(V.begin(), V.end());
  for (int i = 0; i < n; i++)
    cout << V[i] << ' ';
  cout << endl;

  return 0;
}
