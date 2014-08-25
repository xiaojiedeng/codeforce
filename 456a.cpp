#include <cstdio>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int *A = new int[n+1];
  for (int i = 1; i <= n; i++)
    A[i] = 0;

  int a, b;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a, &b);
    if (A[a] == 0 || b < A[a])
      A[a] = b;
  }
  int c = 0;
  for (int i = 1; i <= n; i++) {
    if (A[i] == 0)
      continue;
    if (A[i] < c) {
      printf("Happy Alex\n");
      return 0;
    }
    c = A[i];
  }

  printf("Poor Alex\n");
  return 0;
}
