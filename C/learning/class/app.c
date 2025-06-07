#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  freopen("out.txt", "w", stdout);
  for (int l = 1; l <= 19; l++) {
    printf("|| h %% %.0lf == g", pow(10, l));
  }

  return 0;
}