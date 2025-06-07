#include <stdio.h>
#include <stdlib.h>
int main() {
  for (int i = 0; i <= 50; i++)
    printf("%d:\e[%dm测试\e[0m\n", i, i);
  return 0;
}