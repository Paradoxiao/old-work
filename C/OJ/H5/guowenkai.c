#include <stdio.h>
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    switch (n / 10) {
    case 10:
    case 9:
      printf("1\n");
      break;
    case 8:
      printf("2\n");
      break;
    case 7:
      printf("3\n");
      break;
    case 6:
      printf("4\n");
      break;
    default:
      if (n >= 0 && n <= 100)
        printf("0\n");
      else
        printf("error\n");
    }
    printf("?");
  }
  return 0;
}