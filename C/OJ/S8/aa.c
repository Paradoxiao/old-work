#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fomat(char *in, char *out) {
  int fl = 1;
  for (int i = 0; i < 1005; i++) {
    if (in[i] >= '0' && in[i] <= '9')
      fl = 0;
  }
  if (fl) {
    char tmp[] = "0";
    memcpy(out, tmp, sizeof(tmp));
    return;
  }
  char temp[1005];
  memset(temp, 0, sizeof(temp));
  int i = 0, j = 0, flag = 1;
  for (i = 0; i < 1005; i++) {
    if (in[i] == '0' && flag)
      continue;
    else {
      flag = 0;
      temp[j++] = in[i];
    }
  }
  memcpy(out, temp, sizeof(in));
}
void Compare(char *a, char *b, char *result) {
  int ii, i, ll, l, flag1 = 1, flag2 = 1;
  for (i = 0, ii = 0; ii < 1005; ii++)
    if (a[ii] == '0' && flag1) {
    } else {
      flag1 = 0;
      if (a[ii] >= '0' && a[ii] <= '9')
        i++;
    }
  for (l = 0, ll = 0; ll < 1005; ll++)
    if (b[ll] == '0' && flag2) {
    } else {
      flag2 = 0;
      if (b[ll] >= '0' && b[ll] <= '9')
        l++;
    }
  if (i > l) {
    memcpy(result, a, sizeof(char) * 1005);
    return;
  }
  if (l > i) {
    memcpy(result, b, sizeof(char) * 1005);
    return;
  }
  for (int k = 0; k < 1005; k++) {
    if (a[k] > b[k]) {
      memcpy(result, a, sizeof(char) * 1005);
      return;
    }
    if (a[k] < b[k]) {
      memcpy(result, b, sizeof(char) * 1005);
      return;
    }
  }
}
void compare(char *a, char *b, char *result) {
  int i, l, ii, ll, flag1 = 1, flag2 = 1;
  for (i = 0, ii = 0; ii < 1005; ii++)
    if (a[ii] == '0' && flag1) {
    } else {
      flag1 = 0;
      if (a[ii] >= '0' && a[ii] <= '9')
        i++;
    }
  for (l = 0, ll = 0; ll < 1005; ll++)
    if (b[ll] == '0' && flag2) {
    } else {
      flag2 = 0;
      if (b[ll] >= '0' && b[ll] <= '9')
        l++;
    }
  if (i > l) {
    memcpy(result, b, sizeof(char) * 1005);
    return;
  }
  if (l > i) {
    memcpy(result, a, sizeof(char) * 1005);
    return;
  }
  for (int k = 0; k < 1005; k++) {
    if (a[k] > b[k]) {
      memcpy(result, b, sizeof(char) * 1005);
      return;
    }
    if (a[k] < b[k]) {
      memcpy(result, a, sizeof(char) * 1005);
      return;
    }
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
  char num[1005], max[1005], min[1005];
  memset(num, '\0', sizeof(num));
  memset(max, '\0', sizeof(num));
  memset(min, '\0', sizeof(num));
  scanf("%s", num);
  memcpy(max, num, sizeof(num));
  memcpy(min, num, sizeof(num));
  while (scanf("%s", num) != EOF) {
    Compare(max, num, max);
    compare(min, num, min);
  }
  fomat(max, max);
  fomat(min, min);

  printf("The maximum value is : %s\nThe minimum value is : %s\n", max, min);
  return 0;
}