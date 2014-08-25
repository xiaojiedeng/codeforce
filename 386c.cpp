#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  int N[27] = {0};
  int A[26] = {0};
  int d = 0;
  for (int i = 0; i < s.size(); i++) {
    if (A[s[i]-'a'] == 0)
      d++;
    A[s[i]-'a']++;
    N[d]++;

    int AA[26];
    for (int j = 0; j < 26; j++)
      AA[j] = A[j];
    int dd = d;
    for (int j = 0; j < i; j++) {
      AA[s[j]-'a']--;
      if (AA[s[j]-'a'] == 0)
        dd--;
      N[dd]++;
    }
  }

  cout << d << endl;
  for (int i = 1; i <= d; i++)
    cout << N[i] << endl;

  return 0;
}


