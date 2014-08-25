#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int a;
  int a1 = 0;
  int a2 = 0;

  for (int i=0; i<n; i++) {
    cin >> a;
    if (a == 100)
      a1++;
    else
      a2++;
  }

  if ((a1+2*a2)%2 == 1)
    cout << "NO" << endl;
  else if (a2%2 == 0)
    cout << "YES" << endl;
  else if (a1 == 0 || a1 == 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;

  return 0;
}
