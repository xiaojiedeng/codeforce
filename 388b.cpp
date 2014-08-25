#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
  int k;
  cin >> k;

  vector<int> v;
  vector<int> u;
  int n = 0;
  int m = 2;
  while (k > 1) {
    if (k%2 == 1) {
      m += 1;
      u.push_back(1);
    }
    else {
      u.push_back(0);
    }
    v.push_back(m);
    k /= 2;
    n += m;
  }

  if (v.size() == 0) {
    cout << "2\nNY\nYN" << endl;
    return 0;
  }

  n += 2;
  cout << n << endl;
  
  string s;

  // 1
  s = string(n, 'N');
  for (int j = 0; j < v[0]; j++)
    s[2+j] = 'Y';
  cout << s << endl;

  // 2
  s = string(n, 'N');
  for (int j = 0; j < v.back(); j++)
    s[n-1-j] = 'Y';
  cout << s << endl;

  //3 -- n+2
  m = 2;
  for (size_t i = 0; i < v.size(); i++) {
    s = string(n, 'N');
    if (i == 0)
      s[0] = 'Y';
    else 
      s[m-v[i-1]] = s[m-v[i-1]+1] = 'Y';

    if (i == v.size()-1)
      s[1] = 'Y';
    else {
      s[m+v[i]] = s[m+v[i]+1] = 'Y';
      if (u[i+1] == 1)
        s[m+v[i]+v[i+1]-1] = 'Y';
    }
    cout << s << endl << s << endl;

    if (v[i] == 2) {
      m += v[i];
      continue;
    }

    for (int j = 2; j < v[i]-1; j++) {
      s = string(n, 'N');
      s[m+j-v[i-1]] = 'Y';
      if (i == v.size()-1)
        s[1] = 'Y';
      else
        s[m+j+v[i]] = 'Y';
      cout << s << endl;
    }

    if (u[i] == 1) {
      s = string(n, 'N');
      if (i == 0)
        s[0] = 'Y';
      else
        s[m-v[i-1]] = s[m-v[i-1]+1] = 'Y';

      if (i == v.size()-1)
        s[1] = 'Y';
      else
        s[m+v[i]-1+v[i]] = 'Y';
      cout << s << endl;
    }
    else {
      s = string(n, 'N');
      s[m+v[i]-1-v[i-1]] = 'Y';
      if (i == v.size()-1)
        s[1] = 'Y';
      else
        s[m+v[i]-1+v[i]] = 'Y';
      cout << s << endl;
    }

    m += v[i];
  }

  return 0;
}
