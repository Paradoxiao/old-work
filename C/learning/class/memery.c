#include <stdio.h>
#include <stdlib.h>
int main() {
  int **p;
  p = malloc(5 * sizeof(int *));
  if (!p)
    return 1;
  for (int i = 0; i < 5; i++) {
    p[i] = malloc(sizeof(int) * (i + 1));
    for (int j = 0; j <= i; j++) {
      p[i][j] = i * 10 + j;
      printf("%d ", p[i][j]);
    }
    putchar('\n');
  }
  printf("%x %x %x %x %x %x", p, p[0], p[1], p[2], p[3], p[4]);
  return 0;
}