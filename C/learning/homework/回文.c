#include <stdio.h>
int main() {
  int num, temp, num2 = 0;
  scanf("%d", &num);
  temp = num;
  while (num != 0) {
    num2 *= 10;
    num2 += num % 10;
    num /= 10;
  }
  temp == num2 ? puts("YES") : puts("NO");
  return 0;
}