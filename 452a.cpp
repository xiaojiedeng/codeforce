#include <iostream>
using namespace std;

int main() {
  const char *S[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

  char T[8];
  int n;
  cin >> n >> T;
  for (int i = 0; i < sizeof(S)/sizeof(const char *); i++) {
    bool f = true;
    for (int j = 0; j < n; j++) {
      if (T[j] != '.' && T[j] != S[i][j]) {
        f = false;
        break;
      }
    }
    if (f) {
      cout << S[i] << endl;
      return 0;
    }
  }

}
