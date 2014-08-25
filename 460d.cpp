#include <iostream>
using namespace std;

int main() {
  long long l, r;
  int k;
  cin >> l >> r >> k;

  if (k == 1) {
    cout << l << '\n' << 1 << '\n' << l << '\n';
  }
  else if (k == 2) {
    if (l%2 == 0) {
      cout << 1 << '\n' << 2 << '\n' << l << ' ' << l+1 << '\n';
    }
    else {
      if (r != l+1) {
        cout << 1 << '\n' << 2 << '\n' << l+1 << ' ' << l+2 << '\n';
      }
      else {
        if ((l^r) < l) {
          cout << (l^r) << '\n' << 2 << '\n' << l << ' ' << r << '\n';
        }
        else {
          cout << l << '\n' << 1 << '\n' << l << '\n';
        }
      }
    }
  }
  else if (k == 3) {
    if (l == 1) {
      cout << 0 << '\n' << 3 << '\n' << 1 << ' ' << 2 << ' ' << 3 << '\n';
    }
    else {
      if (l%2 == 0) {
        cout << 1 << '\n' << 2 << '\n' << l << ' ' << l+1 << '\n';
      }
      else {
        cout << 1 << '\n' << 2 << '\n' << l+1 << ' ' << l+2 << '\n';
      }
    }
  }
  else if (k == 4) {
    if (l == 1) {
      cout << 0 << '\n' << 3 << '\n' << 1 << ' ' << 2 << ' ' << 3 << '\n';
    }
    else {
      if (l%2 == 0) {
        cout << 0 << '\n' << 4 << '\n' << l << ' ' << l+1 << ' ' << l+2 << ' ' << l+3 <<'\n';
      }
      else {
        cout << 1 << '\n' << 2 << '\n' << l+1 << ' ' << l+2 << '\n';
      }
    }
  }
  else {
    if (l == 1) {
      cout << 0 << '\n' << 3 << '\n' << 1 << ' ' << 2 << ' ' << 3 << '\n';
    }
    else {
      if (l%2 == 0) {
        cout << 0 << '\n' << 4 << '\n' << l << ' ' << l+1 << ' ' << l+2 << ' ' << l+3 <<'\n';
      }
      else {
        cout << 0 << '\n' << 4 << '\n' << l+1 << ' ' << l+2 << ' ' << l+3 << ' ' << l+4 <<'\n';
      }
    }
  }

  return 0;
}
