#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int l = 1; l < n-i; l++)
      putchar(' ');
    for (int l = 0; l <= i; l++)
      putchar('*');
    putchar('\n');
  }
  return 0;
}