#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> num(N);
  for (int &i : num)
    cin >> i;
  sort(num.begin(), num.end());
  auto last = unique(num.begin(), num.end());
  num.erase(last, num.end());
  cout << num.size() << endl;
  // cout<<last;
  for (int i : num)
    cout << i << ' ';
  return 0;
}
