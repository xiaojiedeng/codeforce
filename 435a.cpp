#include <iostream>
using namespace std;

int main() {
  int n, m;
  int a;
  int b = 0;

  cin >> n >> m;
  int mm = 0;
  for (int i=0; i<n; i++) {
    cin >> a;
    if (a > mm) {
      b++;
      mm = m-a;
    }
    else {
      mm = mm-a;
    }
  }

  cout << b << endl;

  return 0;
}
