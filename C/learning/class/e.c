#include <stdio.h>
int main() {
  unsigned long long N, bit = 1;
  scanf("%llu", &N);
  for (unsigned long long k = 0; k < N; k++)
    bit *= 10;
  for (unsigned long long g = bit / 10; g < bit; g++) {
    unsigned long long h = g * g;
    if (h % 10 == g || h % 100 == g || h % 1000 == g || h % 10000 == g ||
        h % 100000 == g || h % 1000000 == g || h % 10000000 == g ||
        h % 100000000 == g || h % 1000000000 == g || h % 10000000000 == g ||
        h % 100000000000 == g || h % 1000000000000 == g ||
        h % 10000000000000 == g || h % 100000000000000 == g ||
        h % 1000000000000000 == g || h % 10000000000000000 == g ||
        h % 100000000000000000 == g || h % 1000000000000000000 == g)
      printf("%llu\n", g);
  }
}