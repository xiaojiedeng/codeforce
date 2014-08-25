#include <cstdio>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int t, v;
  scanf("%d", &v);
  t = v*v;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++)
      scanf("%d", &v);
    scanf("%d", &v);
    t += v*v;
    if (t==2)
      t = 0;
  }

  int q, i;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &i);
    if (i == 3)
      printf("%d", t);
    else {
      scanf("%d", &v);
      t = 1-t;
    }
  }
  printf("\n");
  return 0;
}


