#include <stdio.h>
int main() {
  int N, bit = 1, flag = 1;
  while (scanf("%d", &N) != EOF) {
    for (int k = 0; k < N; k++) {
      bit *= 10;
    }
    for (int g = bit / 10; g < bit; g++) {
      int h = g * g;
      if (h % 10 == g || h % 100 == g || h % 1000 == g || h % 10000 == g ||
          h % 100000 == g || h % 1000000 == g) {
        if (flag) {
          printf("%d", g);
          flag = 0;
        } else
          printf(" %d", g);
      }
    }
    printf("\n");
    bit = flag = 1;
  }
}
