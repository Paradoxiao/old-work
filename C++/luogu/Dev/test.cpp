#include <bits/stdc++.h>
#include <queue>
using namespace std;
int main() {
  priority_queue<int> a;
  a.push(1);
  a.push(3);
  a.push(5);
  a.push(6);
  a.push(7);
  a.push(2);
  for (int i = 0; i < 10; i++) {
    cout << a.top() << " ";
    a.pop();
  }
  return 0;
}
