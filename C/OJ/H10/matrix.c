#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double data[55][55];
  int m, n;
} matrix;

void row_add(matrix *A, int from, int to, double times);
void matrix_in(matrix *A, int m, int n);
void matrix_out(matrix out);
void matrix_format(matrix *A);

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
  matrix a;
  matrix_in(&a, 4, 4);
  matrix_out(a);
  putchar('\n');
  matrix_format(&a);
  matrix_out(a);
  return 0;
}

void row_add(matrix *A, int from, int to, double times) {
  for (int i = 1; i <= A->n; i++)
    A->data[to][i] += A->data[from][i] * times;
}
void matrix_in(matrix *A, int m, int n) {
  A->m = m;
  A->n = n;
  for (int i = 1; i <= m; i++)
    for (int l = 1; l <= n; l++)
      scanf("%lf", &A->data[i][l]);
}
void matrix_out(matrix out) {
  for (int i = 1; i <= out.m; i++) {
    for (int l = 1; l <= out.n; l++)
      printf(l ? " %lg" : "%lg", out.data[i][l]);
    putchar('\n');
  }
}
void matrix_format(matrix *A) {
  for (int i = 1; i <= A->m; i++) {
    for (int l = i; l <= A->n; l++)
      A->data[i][l] /= A->data[i][i];
    for (int l = i + 1; l <= A->m; l++)
      row_add(A, i, l, -1 / A->data[i][i] * A->data[l][i]);
  }
  for (int i = A->m; i; i--)
    for (int l = i - 1; l; l--)
      row_add(A, i, l, -1 * A->data[l][i]);
}
