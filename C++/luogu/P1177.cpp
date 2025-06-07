#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  vector<int> num(N);
  for (int &i : num)
    cin >> i;
  sort(num.begin(), num.end());
  for (int i : num)
    cout << i << " ";
  return 0;
}