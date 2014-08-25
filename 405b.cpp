#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int j = -1;
  int i = 0;
  while (i<n && s[i]!='R') {
    if (s[i] == 'L')
      j = i;
    i++;
  }

  int sum = i-1-j;
  if (i == n) {
    cout << sum << endl;
    return 0;
  }

  j = i++;
  while (i < n) {
    while (i<n && s[i]=='.')
      i++;
    if (i == n)
      break;
    if ((i-j)%2 == 0)
      sum++;
    j = i++;
    while (i<n && s[i]=='.')
      i++;
    
    sum += i-1-j;
    if (i == n)
      break;
    j = i++;
  }

  cout << sum << endl;
  return 0;
}
