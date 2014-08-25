#include <iostream>
#include <vector>
using namespace std;

const long long P = 1000000007ll;
int main() {
  int n;
  cin >> n;

  vector<long long> v(n+1, 0);

  long long sum = 0;
  int p;
  for (int i = 1; i <= n; i++) {
    cin >> p;
    if (p != i)
      sum += (sum-v[p-1]);
    sum = (sum+P+2)%P;
    v[i] = sum;
  }
  cout << v[n] << endl;

  return 0;
}
