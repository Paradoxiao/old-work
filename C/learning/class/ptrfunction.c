#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef double (*fn)(double);
double Fun(double (*a)(double), double (*b)(double), double x) {
  return b(x) - a(x);
  return (*b)(x) - (*a)(x);
}
int main() {
  double x;
  scanf("%lf", &x);
  fn a[2] = {sin, cos};
  double (*ptr[10])(double);
  printf("%lf", Fun(a[0], a[1], x));
  return 0;
}