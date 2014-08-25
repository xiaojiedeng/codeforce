#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ST {
  int i;
  int n;
};

bool cmp(const ST &a, const ST &b) {
  return a.n < b.n;
}

int main() {
  string s;
  vector<ST> V;
  for (int i = 0; i < 4; i++) {
    cin >> s;
    ST st;
    st.i = i;
    st.n = s.size()-2;
    V.push_back(st);
  }
  sort(V.begin(), V.end(), cmp);

  char r = 'A';
  if (V[0].n*2 <= V[1].n && V[2].n*2 > V[3].n)
    r += V[0].i;
  else if (V[0].n*2 > V[1].n && V[2].n*2 <= V[3].n)
    r += V[3].i;
  else
    r = 'C';
  cout << r << endl;

  return 0;
}
