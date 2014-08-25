#include <cstdio>
#include <vector>
using namespace std;

const long long P = 1000000007ll;
int main() {
  int n, m;
  //cin >> n >> m;
  scanf("%d %d", &n, &m);

  vector<long long> v(n, 0);
  for (int i = 0; i < n; i++)
    scanf("%I64d", &v[i]);

  int l, r, k;
  while (m--) {
    //cin >> l >> r >> k;
    scanf("%d %d %d", &l, &r, &k);
    l--; r--;

    long long t = 1;
    for (int j = l; j <= r; j++) {
      v[j] = (v[j]+t)%P;
      t = (t*(k+1+j-l)/(1+j-l))%P;
    }

  }
  for (int i = 0; i < n; i++)
    printf("%I64d ", v[i]);
  printf("\n");
  //cout << v[i] << ' ';
  //cout << endl;

  return 0;
}
