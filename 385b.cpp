#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  int j = -1;
  int m = 0;
  for (int i = 0; i <= n-4; i++) {
    if (s[i]=='b' && s[i+1]=='e' && s[i+2]=='a' && s[i+3]=='r') {
      m += (i-j)*(n-(i+3));
      j = i;
    }
  }
  cout << m << endl;
  return 0;
}
