#include <cstdio>
using namespace std;

int main() {
  double a, d;
  scanf("%lf %lf", &a, &d);

  int n;
  scanf("%d", &n);

  double x = 0;
  double a4 = 4*a;
  double a2 = 2*a;
  double a3 = 3*a;

  while (n--) {
    x += d;

    if (x >= a4) {
      int c = x/a4;
      x -= c*a4;
    }
    if (x < a)
      printf("%.10f %.10f\n", x, 0.);
    else if (x < a2)
      printf("%.10f %.10f\n", a, x-a);
    else if (x < a3)
      printf("%.10f %.10f\n", a3-x, a);
    else
      printf("%.10f %.10f\n", 0., a4-x);
  }

  return 0;
}
