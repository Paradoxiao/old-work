#include <stdio.h>
#include <stdlib.h>

int main() {
  int balance;
  scanf("%d", &balance);

  char sign;
  int amount;
  while (scanf("%c%d", &sign, &amount) == 2) {
    if (sign == '-' || (sign == '\n' && amount < 0)) {
      balance -= abs(amount);
    } else {
      balance += amount;
    }
  }

  if (balance < 0) {
    printf("Yes");
  } else {
    printf("No");
  }

  return 0;
}