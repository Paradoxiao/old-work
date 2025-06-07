#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long a, b, c, base, sn = 1;
  scanf("%llu %llu %llu", &a, &b, &c);
  printf("%llu^%llu mod %llu", a, b, c);
  base = a;
  while (b) {
    if (b & 1)
      sn *= base;
    base *= base;
    b >>= 1;
  }
  printf("=%llu", sn % c);
  return 0;
}