#include<cstdio>
using namespace std;

int main() {
  int sh, sm;
  scanf("%d:%d", &sh, &sm);
  int st = sh*60+sm;

  int th, tm;
  scanf("%d:%d", &th, &tm);
  int tt = th*60+tm;

  int pt = st-tt;
  if (pt < 0)
    pt += 24*60;

  printf("%02d:%02d\n", pt/60, pt%60);

  return 0;
}
