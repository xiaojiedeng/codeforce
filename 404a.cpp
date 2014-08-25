#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;
  char a = s[0];
  char b = s[1];
  
  bool flag = (a!=b);
  for (int i = 0; flag && i < n; i++) {
    if (s[i]!=a || s[n-1-i]!=a) {
      flag = false;
      break;
    }
    for (int j = 0; j < n; j++) {
      if (j==i || j==n-1-i)
        continue;
      if (s[j]!=b) {
        flag = false;
        break;
      }
    }
    if (!flag)
      break;

    if (i != n-1)
      cin >> s;
  }

  if (flag)
    cout << "YES"<< endl;
  else
    cout << "NO" << endl;
  return 0;
}
