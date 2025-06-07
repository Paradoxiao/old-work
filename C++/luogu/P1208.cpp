#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct milk {
  int p, a, total;
  void pay() {
    total = a * p;
  }
};
bool cmp(milk a, milk b) {
  return a.p < b.p;
}
int main() {
  int n, m, i, cost = 0, sum = 0;
  cin >> n >> m;
  if (!n) {
    cout << 0;
    return 0;
  }
  vector<milk> mans(m);
  for (milk &i : mans) {
    cin >> i.p >> i.a;
    i.pay();
  };
  sort(mans.begin(), mans.end(), cmp);
  for (i = 0; i < m; i++) {
    if (sum + mans[i].a >= n)
      break;
    sum += mans[i].a;
    cost += mans[i].total;
  }
  cost += (n - sum) * mans[i].p;
  cout << cost;
  return 0;
}