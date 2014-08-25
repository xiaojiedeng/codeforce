#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    vector<int> v;
    for (int j = 1; j <= 12; j++) {
      if (12 % j != 0)
        continue;

      int l = 12/j;
      bool b = false;
      for (int i = 0; !b && i < l; i++) {
        b = true;
        for (int k = 0; b && k<j; k++)
          if (s[i+k*l] == 'O')
            b = false;
        if (b)
          v.push_back(j);
      }
    }

    cout << v.size();
    for (int i = 0; i < v.size(); i++)
      cout << " " << v[i] << "x" << 12/v[i];
    cout << endl;
  }

  return 0;
}
