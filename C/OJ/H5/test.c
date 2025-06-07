#include <stdio.h>
int main() {
  printf("%llu %llu %llu %llu %d", sizeof(int), sizeof(short), sizeof(long),
         sizeof(long long), -11 / 10);
  for (int i = 0; i < 100; i++) {
    printf("?");
  }
  return 0;
}