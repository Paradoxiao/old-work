#include <stdio.h>
int fac(int n) {
  if (n == 1 || n == 0)
    return 1;
  else
    return fac(n - 2) + fac(n - 1);
}
int main() {
  int n;
  printf("Enter the number of terms: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("%d ", fac(i));
  }
  return 0;
}