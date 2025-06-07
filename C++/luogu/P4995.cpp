#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int len(int a, int b) {
  return (a - b) * (a - b);
}
bool have(vector<bool> arrive) {
  for (bool i : arrive)
    if (!i)
      return true;
  return false;
}
int main() {
  int n, total = 0, now = 0, flag = 0;
  cin >> n;
  vector<int> stones(n + 1);
  stones[0] = 0;
  for (int i = 1; i < n + 1; i++)
    cin >> stones[i];
  sort(stones.begin(), stones.end());
  vector<bool> arrive(n, 0);
  while (have(arrive)) {
    int i;
    if (flag++ % 2)
      for (i = 0; arrive[i]; i++)
        ;
    else
      for (i = n; arrive[i]; i--)
        ;
    total += len(stones[now], stones[i]);
    arrive[now] = 1;
    arrive[i] = 1;
    now = i;
  }
  cout << total;
  return 0;
}
