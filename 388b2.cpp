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
    while (k>1 && k%i==0) {
      v.push_back(i);
      n += i;
      k /= i;
    }
  }
  if (k > 1) {
    v.push_back(k);
    n += k;
  }


  if (v.size() == 0) {
    printf("2\nNY\nYN\n");
    return 0;
  }

  printf("%d\n", n+2);
  //1
  printf("NN");
  for (int j = 0; j < v[0]; j++)
    printf("Y");
  for (int j = 0; j < n-v[0]; j++)
    printf("N");
  printf("\n");
  //2
  printf("NN");
  for (int j = 0; j < n-v.back(); j++)
    printf("N");
  for (int j = 0; j < v.back(); j++)
    printf("Y");
  printf("\n");

  //3 -- n+2
  int a, b, c, d;
  a = b = c = d = 0;
  for (size_t i = 0; i < v.size(); i++) {
    a += b;
    b = (i==0) ? 0 : v[i-1];
    c = (i==v.size()-1) ? 0 : v[i+1];
    d = n-a-b-c-v[i];

    for (int k = 0; k < v[i]; k++) {
      if (i == 0)
        printf("Y");
      else
        printf("N");
      if (i == v.size()-1)
        printf("Y");
      else
        printf("N");

      for (int j = 0; j < a; j++)
        printf("N");
      for (int j = 0; j < b; j++)
        printf("Y");
      for (int j = 0; j < v[i]; j++)
        printf("N");
      for (int j = 0; j < c; j++)
        printf("Y");
      for (int j = 0; j < d; j++)
        printf("N");
      printf("\n");
    }
  }

  return 0;
}
