#include <stdio.h>
int main() {
  int N, i, t;
  scanf("%d", &N);
  for (i = 1, t = 1; i <= N; i++, t *= 10)
    ;
  // printf("%d", t);
  for (i = t / 10; i <= t - 1; i++) {
    if (i == (i * i) % t) // 是--->取余<---运算
      printf("%d\n", i);
  }
  return 0;
}
