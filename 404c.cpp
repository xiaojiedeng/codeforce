#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  int d = 0;
  vector<vector<int> > V(n, vector<int>());
  int v;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v);
    V[v].push_back(i);
    if (d < v)
      d = v;
  }

  int m = 0;
  bool bflag = (V[0].size()==1);
  for (int i = 1; bflag && i <= d; i++) {
    int kk = (i==1) ? k : k-1;
    long long a = V[i].size();
    long long b = V[i-1].size();
    b *= kk;
    if (a > b)
      bflag = false;
    else
      m += V[i].size();
  }

  if (!bflag) {
    printf("-1\n");
    return 0;
  }

  printf("%d\n", m);
  //int a, b;
  //a = 1;
  for (int i = 1; i <= d; i++) {
    int kk = (i==1) ? k : k-1;
    //b = a+V[i-1].size();
    for (int j = 0; j < V[i].size(); j++)
      printf("%d %d\n", V[i-1][j/kk], V[i][j]);
    //a = b;
  }

  return 0;
}

