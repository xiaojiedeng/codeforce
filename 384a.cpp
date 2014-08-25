#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  if (n%2 == 0) {
    string s(n, '.');
    string t(n, '.');
    for (int i = 0; i < n; i += 2) {
      s[i] = 'C';
      t[i+1] = 'C';
    }
    cout << n*n/2 << endl;
    for (int i = 0; i < n; i += 2) {
      cout << s << endl;
      cout << t << endl;
    }
  }
  else {
    string s(n, '.');
    string t(n, '.');
    for (int i = 0; i < n-1; i += 2) {
      s[i] = 'C';
      t[i+1] = 'C';
    }
    s[n-1] = 'C';
    cout << n*(n/2) + (n+1)/2 << endl;
    for (int i = 0; i < n-1; i += 2) {
      cout << s << endl;
      cout << t << endl;
    }
    cout << s << endl;
  }

  return 0;
}
