#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  char C[102][102];
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      C[i][j] = '*';

  for (int i = 0; i < n/2+1; i++) {
    for (int j = 0; j <= i; j++) {
      C[i][n/2-j] = 'D';
      C[i][n/2+j] = 'D';
      C[n-1-i][n/2-j] = 'D';
      C[n-1-i][n/2+j] = 'D';
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << C[i][j];
    cout << endl;
  }

  return 0;
}
