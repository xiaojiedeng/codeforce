#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> x(n, 0);
  vector<int> v(n, 0);
  for (int i = 0; i < n; i++)
    cin >> x[i];
  sort(x.begin(), x.end());

  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] == 1)
      continue;
    sum++;
    v[i] = 1;
    int k = 1;
    for (int j = i+1; j < n; j++) {
      if (v[j]==1 || x[j]<k)
        continue;
      v[j] = 1;
      k++;
    }
  }
  cout << sum << endl;
  return 0;
}
