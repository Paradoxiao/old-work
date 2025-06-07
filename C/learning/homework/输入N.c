#include <stdio.h>
int main() {
  int n, max, temp;
  freopen("fin.txt", "r", stdin);
  freopen("fout.txt", "w", stdout);
  scanf("%d %d", &n, &max);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &temp);
    max = max > temp ? max : temp;
  }
  printf("%d", max);
  return 0;
}