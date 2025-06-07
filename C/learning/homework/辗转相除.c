#include <stdio.h>

int Max1(int a, int b) {
  if (a % b == 0)
    return b;
  return Max1(b, a % b);
}

int Max2(int m, int n) {
  int rem;
  while (n > 0) {
    rem = m % n;
    m = n;
    n = rem;
  }
  return m;
}

int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", Max2(a, b));
  printf("%d\n", Max1(a, b));
  return 0;
}