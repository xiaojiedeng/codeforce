#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int A[3000];
  int i = 0;
  while (i < n)
    cin >> A[i++];
  int B[3000];
  int j = 0;
  while (j < m)
    cin >> B[j++];

  i = j = 0;
  while (i < n && j < m) {
    while (j < m && A[i] > B[j])
      j++;
    if (j < m) {
      i++;
      j++;
    }
  }

  cout << n-i << endl;

  return 0;
}
