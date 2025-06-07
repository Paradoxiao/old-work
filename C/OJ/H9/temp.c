#include <stdio.h>
#include <string.h>
typedef struct {
  int data[101][101];
  int m, n;
} matrix;
void matrixin(matrix *a) {
  for (int i = 0; i < a->m; i++)
    for (int j = 0; j < a->n; j++)
      scanf("%d", &a->data[i][j]);
}
int matrixmulti(matrix *a, matrix *b, matrix *c) {
  if (a->n != b->m)
    return 0;
  c->m = a->m;
  c->n = b->n;
  for (int i = 0; i < c->m; i++)
    for (int j = 0; j < c->n; j++) {
      c->data[i][j] = 0;
      for (int k = 0; k < a->n; k++)
        c->data[i][j] += a->data[i][k] * b->data[k][j];
    }
  return 1;
}
void matrixout(matrix *a) {
  for (int i = 0; i < a->m; i++) {
    for (int j = 0; j < a->n; j++)
      printf(j == 0 ? "%d" : " %d", a->data[i][j]);
    putchar('\n');
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
  matrix a, b, c;
  int m, n;
  scanf("%d %d", &m, &n);
  a.m = m;
  a.n = n;
  matrixin(&a);
  scanf("%d %d", &m, &n);
  b.m = m;
  b.n = n;
  matrixin(&b);
  scanf("%d %d", &m, &n);
  matrixmulti(&a, &b, &c);
  matrixout(&c);
  putchar('\n');
  while (m || n) {
    a.m = m;
    a.n = n;
    matrixin(&a);
    if (matrixmulti(&c, &a, &b)) {
      matrixout(&b);
      c = b;
    } else {
      puts("Not satisfied the definition of matrix multiplication!");
      c = a;
    }
    putchar('\n');
    scanf("%d %d", &m, &n);
  }
  return 0;
}