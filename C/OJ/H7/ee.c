#include <stdio.h>
int main() {
  int N, bit = 1;
  scanf("%d", &N);
  for (int k = 0; k < N; k++)
    bit *= 10;
  for (int g = bit / 10; g < bit; g++) {
    int h = g * g;
    if (h % 10 == g || h % 100 == g || h % 1000 == g || h % 10000 == g ||
        h % 100000 == g || h % 1000000 == g)
      printf("%d\n", g);
  }
}
