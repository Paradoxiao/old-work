#include <iostream>
#include <string>
using namespace std;
int main() {
  int a[2005] = {}, b[2005] = {}, c[2005] = {};
  string aa, bb;
  cin >> aa >> bb;
  for (int i = 0; i < aa.size(); i++)
    a[i] = aa[aa.size() - i - 1] - '0';
  for (int i = 0; i < bb.size(); i++)
    b[i] = bb[bb.size() - i - 1] - '0';
  for (int i = 0; i < bb.size(); i++)
    for (int j = 0; j < aa.size(); j++) {
      int temp = a[j] * b[i];
      c[i + j] += temp % 10;
      c[i + j + 1] += temp / 10;
    }
  for (int i = 0; i < 2004; i++)
    if (c[i] > 9) {
      c[i + 1] += c[i] / 10;
      c[i] %= 10;
    }
  int i = 2004;
  while (!c[i])
    i--;
  for (; i >= 0; i--)
    cout << c[i];
  return 0;
}