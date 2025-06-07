#include <stdio.h>
void Inputarray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
}
void Outputarray(int arr[], int n) {
  printf("%d", arr[1]);
  for (int i = 1; i < n; i++)
    printf(" %d\n", arr[i]);
}
int sum(int arr1[], int arr2[], int he[], int k, int m) {
  int i = 0;
  for (; i < k && i < m; i++)
    he[i] = arr1[i] + arr2[i];
  for (; i < k; i++)
    he[i] = arr1[i];
  for (; i < m; i++)
    he[i] = arr2[i];
  return i;
}
int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int A[1000], B[1000], C[1000];
  int k, m, n;
  while (scanf("%d", &k) != EOF) {
  }
  return 0;
}