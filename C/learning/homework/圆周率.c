#include <stdio.h>
long double getpi(int n) {
  double i = 0;
  double _abs = -1;
  double result = 0;
  for (i = 0; i < n; i++) {
    _abs = -_abs;
    result += 4 * _abs / (i * 2 + 1);
    printf("%lg %.10lf    %.10lf\n", i+1, result, result - 3.1415926535);
  }
  return result;
}
int main() {
  int n;
  scanf("%d", &n);
  getpi(n);
  return 0;
}