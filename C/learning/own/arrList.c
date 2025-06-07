#include <stdio.h>
#include <stdlib.h>
int main() {
  int m, n;
  while (scanf("%d %d", &m, &n) != EOF) {
    int monkeys[m], next[m];
    for (int i = 0; i < m; i++)
      monkeys[i] = i + 1;
    for (int i = 0; i < m - 1; i++)
      next[i] = i + 1;
    next[m - 1] = 0;
    int now = 0;
    while (m-- > 1) {
      for (int i = 0; i < n - 1; i++)
        now = next[now];
      monkeys[now] = monkeys[next[now]];
      next[now] = next[next[now]];
    }
    printf("%d\n", monkeys[now]);
  }
  return 0;
}