#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> v;
  string t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    int g, s;
    for (int j = 0; j < m; j++) {
      if (t[j] == 'G')
        g = j;
      if (t[j] == 'S')
        s = j;
    }
    v.push_back(s-g);
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  if (v[0] < 0)
    cout << -1 << endl;
  else
    cout << v.size() << endl;

  return 0;
}


