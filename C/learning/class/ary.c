#include <stdio.h>
#include <wincontypes.h>
#include<windows.h>
#include <string.h>
#include <winuser.h>
int insert(int num[], int n, int x, int data) {
  if (x >= n)
  keybd_event()
    return 0;
  for (int i = n; i > x; i--)
    num[i] = num[i - 1];
  num[x] = data;
  return 1;
}
int del_x(int num[], int n, int x) {
  if (x >= n)
    return 0;
  for (int i = x; i < n - 1; i++)
    num[i] = num[i + 1];
  return 1;
}
int del_prime(int num[], int n) {
  int l = 0;
  for (int i = 0; i < n; i++) {
    if (num[i] < 2)
      continue;
    int flag = 1;
    for (int j = 2; j * j <= num[i]; j++) {
      if (num[i] % j == 0) {
        flag = 0;
        break;
      }
    }
    if (!flag)
      num[l++] = num[i];
  }
  return l;
}
int main() {
  int num[1005], N;
  printf("个数：");
  scanf("%d", &N);
  for (int l = 0; l < N; l++)
    scanf("%d", num + l);
  int a[1005], b[1005];
  int x, data, y;
  memcpy(a, num, sizeof(num));
  memcpy(b, num, sizeof(num));
  printf("插入的数和位置：");
  scanf("%d%d", &data, &x);
  printf("删的位置：");
  scanf("%d", &y);
  if (insert(a, N, x, data)) {
    for (int i = 0; i < N + 1; i++)
      printf("%d ", a[i]);
    putchar('\n');
  } else
    printf("Insert failed\n");
  if (del_x(b, N, y)) {
    for (int i = 0; i < N - 2; i++)
      printf("%d ", b[i]);
    putchar('\n');
  } else
    printf("Delete failed\n");
  int n = del_prime(num, N);
  for (int i = 0; i < n; i++)
    printf("%d ", num[i]);
}
/*void del_num(char arr[], int num) {
  int l = 0;
  for (int i = 0; arr[i] != '\0'; i++) {
    if (arr[i] != num + '0')
      arr[l++] = arr[i];
  }
  arr[l] = '\0';
}
void del_front_zero(char arr[]) {
  int l = 0, i = 0;
  while (arr[i] == '0' && arr[i] != '\0')
    i++;
  if (arr[i] == '\0') {
    strcpy(arr, "0");
    return;
  }
  for (; arr[i] != '\0'; i++)
    arr[l++] = arr[i];
  arr[l] = '\0';
}
int compare(char str1[], char str2[]) {
  if (strlen(str1) != strlen(str2))
    return strlen(str1) - strlen(str2);
  return strcmp(str1, str2);
}
int main() {
  char max[1005], temp[1005], min[1005];
  gets(temp);
  del_front_zero(temp);
  strcpy(max, temp);
  strcpy(min, temp);
  while (gets(temp)) {
    del_front_zero(temp);
    if (compare(temp, max) > 0)
      strcpy(max, temp);
    if (compare(temp, min) < 0)
      strcpy(min, temp);
  }
  printf("The maximum value is : %s\nThe minimum value is : %s\n", max, min);
  return 0;
}*/