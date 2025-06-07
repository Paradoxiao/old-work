#include <stdio.h>
void gold(int n) {
  long double a = 1, b = 1;
  int i;
  for (i = 0; i < n; i++) {
    if (i % 2 == 0) {
      a = a + b;
      printf("%d  %.20Lf\n", i, b / a);
    } else {
      b = a + b;
      printf("%d  %.20Lf\n", i, a / b);
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  gold(n);
  return 0;
}