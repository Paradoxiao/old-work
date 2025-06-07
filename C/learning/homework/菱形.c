#include <stdio.h>
#include <stdlib.h>
int main() {
  int n;
  scanf("%d", &n);
  n /= 2;
  for (int y = -n; y <= n; y++) {
    for (int x = -n; x <= n; x++)
      (abs(y) + abs(x) <= n) ? putchar('*') : putchar(' ');
    putchar('\n');
  }
  return 0;
}
/* #include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  freopen("fout.txt", "w", stdout);
  for (int y = -n; y <= n + 1; y++) {
    for (int x = -n; x <= n + 1; x++)
      (y * y + x * x <= n * n) ? putchar('*') : putchar(' ');
    putchar('\n');
  }
  return 0;
} */
/* #include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  for (int y = n; y > 0; y--) {
    for (int x = 0; x <= n; x++)
      (y <= x) ? putchar('*') : putchar(' ');
    putchar('\n');
  }
  return 0;
} */
/* #include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int l = 0; l < n - i; l++)
      putchar(' ');
    for (int l = 0; l <= i * 2; l++)
      putchar('*');
    putchar('\n');
  }
  for (int i = n; i > 0; i--) {
    for (int l = 0; l < n - i; l++)
      putchar(' ');
    for (int l = 0; l <= i * 2; l++)
      putchar('*');
    putchar('\n');
  }
  return 0;
} */
/* #include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    for (int l = 0; l <= n; l++) {
      if (i + l >= n)
        putchar('*');
    }
    putchar('\n');
  }
  return 0;
} */
