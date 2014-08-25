#include <iostream>
#include <vector>

using namespace std;

struct ST {
  int t, h, m;
  int v;
};

int main() {
  vector<ST> V;
  ST st;
  st.t = 0;
  st.h = 0;
  st.m = 2001;
  st.v = 0;
  V.push_back(st);

  int n, x;
  cin >> n >> x;
  
  for (int i = 1; i <= n; i++) {
    cin >> st.t >> st.h >> st.m;
    st.v = 0;
    V.push_back(st);
  }

  int h = x;
  int k = 0;
  int t = 0;
  int m = 0;
  while (1) {
    k = 0;
    for (int i = 1; i <= n; i++)
      if (V[i].v == 0 && V[i].t == t && V[i].h <= h && V[i].m < V[k].m)
        k = i;

    if (k == 0)
      break;

    m++;
    h += V[k].m;
    t = 1 - t;
    V[k].v = 1;
  }

  int mm = m;

  h = x;
  k = 0;
  t = 1;
  m = 0;
  while (1) {
    k = 0;
    for (int i = 1; i <= n; i++)
      if (V[i].v == 0 && V[i].t == t && V[i].h <= h && V[i].m < V[k].m)
        k = i;

    if (k == 0)
      break;

    m++;
    h += V[k].m;
    t = 1 - t;
    V[k].v = 1;
  }

  if (mm > m)
    m = mm;

  cout << m << endl;

  return 0;
}
