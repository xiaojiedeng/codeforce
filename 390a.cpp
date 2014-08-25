#include <iostream>
using namespace std;

int main() {
  int H[101] = {0};
  int V[101] = {0};

  int n, x, y;
  cin >> n;
  while (n--) {
    cin >> x >> y;
    V[x] = H[y] = 1;
  }

  x = y = 0;
  for (int i = 0; i <= 100; i++) {
    x += V[i];
    y += H[i];
  }
  cout << min(x, y) << endl;
  return 0;
}
  
