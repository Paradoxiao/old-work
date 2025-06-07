#include <iostream>
using namespace std;
struct big_int {
  int bit[40] = {0};
  big_int(long long data) {
    int i = 0;
    while (data) {
      bit[i++] = data % 10;
      data /= 10;
    }
  }
  big_int operator+(big_int other) {
    for (int i = 0; i < 40; i++) {
      bit[i] += other.bit[i];
      if (bit[i] > 9) {
        bit[i + 1] = bit[i] / 10;
        bit[i] %= 10;
      }
    }
    return *this;
  }
  void print() {
    int i = 39;
    while (!bit[i])
      i--;
    for (; i >= 0; i--)
      cout << bit[i];
  }
};
int main() {
  long long a, b;
  cin >> a >> b;
  big_int aa(a), bb(b);
  aa.print();
  cout << endl;
  bb.print();
  cout << endl;
  (aa + bb).print();
  return 0;
}