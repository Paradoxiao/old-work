#include <stdio.h>
int main() {
  char a = 'Y';
  printf("Y/n: ");
  scanf("%c", &a);
  if (a == 'Y' || a == '\n' || a == 'y')
    printf("Yes\n");
  else if (a == 'n' || a == 'N')
    printf("No\n");
  else
    printf("Invalid\n");
  return 0;
}