#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v(n, 0);
  int i, j, k;
  for (i=0; i<n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());

  int t;
  cin >> t;
  int m = 0;
  for (i=0; i<n; i=j) {
    for (j=i+1; j<n && v[i]==v[j]; j++) ;
    for (k=j; k<n && v[k]-v[i]<=t; k++) ;
    if (m < k-i)
      m = k-i;
  }

  cout << m << endl;
  return 0;
}
