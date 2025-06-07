#include <stdio.h>
int main() {
  long long a;
  scanf("%lld", &a);
  for (long long i = 2; i < a; i++) {
    if (a % i == 0) {
      printf("NO");
      return 0;
    }
  }
  printf("YES");
  return 0;
}