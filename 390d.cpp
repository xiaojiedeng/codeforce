#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;

void print1(vector<int> &v) {
  for (int i = v.size()-1; i >= 0; i--) {
    for (int j = v[i]-1; j >= 0; j--) {
      for (int ii = 0; ii < i; ii++)
        cout << "(" << ii+1 << ", " << 1 << ") ";
      for (int jj = 0; jj <= j; jj++)
        cout << "(" << i+1 << ", " << jj+1 << ") ";
      cout << endl;
    }
  }
}
void print2(vector<int> &v) {
  for (int i = v.size()-1; i >= 0; i--) {
    for (int j = v[i]-1; j >= 0; j--) {
      for (int ii = 0; ii < i; ii++)
        cout << "(" << 1 << ", " << ii+1 << ") ";
      for (int jj = 0; jj <= j; jj++)
        cout << "(" << jj+1 << ", " << i+1 << ") ";
      cout << endl;
    }
  }
}

int main() {
  int n, m, k, l, t;
  cin >> n >> m >> k;

  vector<int> v;
  if (n <= m) {
    if (k <= (1+n)*n/2) {
      l = (sqrt(1+8*k)-1)/2;
      t = k - (1+l)*l/2;
      for (int i = 0; i < l; i++) {
        int j = (t-- > 0) ? l-i+1 : l-i;
        v.push_back(j);
      }
    }
    else if (k <= (1+n)*n/2 + (m-n)*n) {
      l = (k-(1+n)*n/2)/n;
      t = k-(1+n)*n/2-l*n;
      for (int i = 0; i < n; i++) {
        int j = (t-- > 0) ? n-i+l+1 : n-i+l;
        v.push_back(j);
      }
    }
    else {
      k -= (1+n)*n/2 + (m-n)*n;
      l = (2*n-1-sqrt((2*n-1)*(2*n-1)-8*k))/2;
      t = k - (n-1+n-l)*l/2;
      for (int i = 0; i < n; i++)
        v.push_back(m-i);
      int ii;
      for (int i = n-1; i >= 0; i--) {
        if (v[i]+l < m) {
          v[i] += l;
          ii = i;
        }
        else
          v[i] = m;
      }
      while (t-- > 0)
        v[ii++]++;
    }
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
      sum += i*v[i]+(1+v[i])*v[i]/2;
    cout << sum << endl;
    print1(v);
  }
  else {
    if (k <= (1+m)*m/2) {
      l = (sqrt(1+8*k)-1)/2;
      t = k - (1+l)*l/2;
      for (int i = 0; i < l; i++) {
        int j = (t-- > 0) ? l-i+1 : l-i;
        v.push_back(j);
      }
    }
    else if (k <= (1+m)*m/2 + (n-m)*m) {
      l = (k-(1+m)*m/2)/m;
      t = k-(1+m)*m/2-l*m;
      for (int i = 0; i < m; i++) {
        int j = (t-- > 0) ? m-i+l+1 : m-i+l;
        v.push_back(j);
      }
    }
    else {
      k -= (1+m)*m/2 + (n-m)*m;
      l = (2*n-1-sqrt((2*m-1)*(2*m-1)-8*k))/2;
      t = k - (m-1+m-l)*l/2;
      for (int i = 0; i < m; i++)
        v.push_back(n-i);
      int ii;
      for (int i = m-1; i >= 0; i--) {
        if (v[i]+l < n) {
          v[i] += l;
          ii = i;
        }
        else
          v[i] = n;
      }
      while (t-- > 0)
        v[ii++]++;
    }
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
      sum += i*v[i]+(1+v[i])*v[i]/2;
    cout << sum << endl;
    print2(v);
  }


  return 0;
}
