#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int N[26] = {0};
  for (size_t i = 0; i < s.size(); i++)
    N[s[i]-'a']++;
  
  string t;
  cin >> t;
  int M[26] = {0};
  for (size_t i = 0; i < t.size(); i++)
    M[t[i]-'a']++;

  int sum = 0;
  for (int i = 0; i < 26; i++) {
    if (M[i] == 0)
      continue;
    if (N[i] == 0) {
      sum = -1;
      break;
    }
    if (N[i] > M[i])
      sum += M[i];
    else
      sum += N[i];
  }
  cout << sum << endl;
  return 0;
}

