#include <stdio.h>
#include <stdlib.h>
void print(int a, int b, int c, int d) {
  if (a == b || a == c || a == d || b == c || b == d || c == d)
    return;
  if (a < 0 || a > 3 || b < 0 || b > 3 || c < 0 || c > 3 || d < 0 || d > 3)
    return;
  int n[4];
  // while (1)//3,008,000,000
  for (n[0] = 1; n[0] <= 50; n[0]++)
    for (n[1] = 1; n[1] <= 50; n[1]++)
      for (n[2] = 1; n[2] <= 50; n[2]++)
        for (n[3] = ' '; n[3] <= '~'; n[3]++)
          printf("\e[%dm\e[%dm\e[%dm%c\e[0m", n[a], n[b], n[c], n[d]);
}
int main() {
  for (int a = 0; a < 4; a++)
    for (int b = 0; b < 4; b++)
      for (int c = 0; c < 4; c++)
        for (int d = 0; d < 4; d++)
          print(a, b, c, d);
  return 0;
}