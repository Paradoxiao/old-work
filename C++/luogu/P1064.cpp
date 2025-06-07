#include <cstdio>
using namespace std;
int main() {
  int a;
  scanf("%d", &a);
  for (int i = 0; i <= a; i++) {
    int n;
    scanf("%d", &n);
    if (i != a) {
      if (n) {
        if (i && n > 0)
          putchar('+');
        if (n != 1 && n != -1)
          printf("%d", n);
        if (n == -1)
          putchar('-');
        printf("x^%d", a - i);
      }
    } else
      printf(n > 0 ? "+%d" : "%d", n);
  }
  return 0;
}