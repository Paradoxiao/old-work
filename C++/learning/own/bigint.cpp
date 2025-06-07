#include <fstream>
#include <iostream>
#define len 10000
using namespace std;
struct big_int {
private:
  long long data[len] = {0};
  int bit = 0;

public:
  big_int() {}
  big_int(long long num) {
    data[0] = num;
    bit++;
    for (int i = 0; data[i] > 9; i++) {
      data[i + 1] = data[i] / 10;
      data[i] %= 10;
      bit++;
    }
  }
  void output(fstream *T) {
    for (int i = bit - 1; i >= 0; i--)
      *T << data[i];
  }
  void operator=(long long other) {
    big_int temp(other);
    *this = temp;
  }
  bool operator==(const big_int other) {
    if (bit != other.bit)
      return 0;
    for (int i = 0; i < len; i++)
      if (data[i] != other.data[i])
        return 0;
    return 1;
  }
  bool operator>(const big_int other) {
    if (bit < other.bit)
      return 0;
    if (bit > other.bit)
      return 1;
    for (int i = bit - 1; i >= 0; i--)
      if (data[i] > other.data[i])
        return 1;
    return 0;
  }
  bool operator<(const big_int other) {
    if (bit > other.bit)
      return 0;
    if (bit < other.bit)
      return 1;
    for (int i = bit - 1; i >= 0; i--)
      if (data[i] < other.data[i])
        return 1;
    return 0;
  }
  big_int operator+(const big_int other) {
    bit = bit > other.bit ? bit : other.bit;
    for (int i = 0; i < bit; i++)
      data[i] += other.data[i];
    carry();
    return *this;
  }
  big_int operator+(long long other) {
    data[0] += other;
    carry();
    return *this;
  }
  big_int operator*(long long n) {
    for (int i = 0; i < bit; i++)
      data[i] *= n;
    carry();
    return *this;
  }
  big_int operator*=(long long n) { return *this * n; }

private:
  void carry(void) {
    for (int i = 0; i < bit; i++)
      if (data[i] / 10) {
        data[i + 1] += data[i] / 10;
        data[i] %= 10;
      }
    int i = len;
    while (!data[--i])
      ;
    if (i != bit - 1) {
      bit = i + 1;
      carry();
    }
  }
};
int main() {
  fstream out;
  out.open("2^x.txt");
  big_int x = 1;
  for (int i = 1; i < 10001; i++) {
    x *= 2;
    out << '<' << i << '>';
    x.output(&out);
    out << endl;
  }
  out.close();
  return 0;
}

// struct big_int {
// public:
//   int data[10000] = {0};

// private:
//   int bit = 0;
//   int sign = 1;

// public:
//   big_int(long long a) {
//     if (a < 0) {
//       sign = -1;
//       a = -a;
//     }
//     int i = 0;
//     do {
//       data[i] = a % 10;
//       data[++i] = a /= 10;
//       bit++;
//     } while (a > 9);
//   }
//   void output(void) {
//     if (sign == -1)
//       cout << '-';
//     for (int i = bit; i >= 0; i--)
//       cout << data[i] << ' ';
//   }
//   bool operator==(const big_int other) {
//     if (sign != other.sign)
//       return 0;
//     if (bit != other.bit)
//       return 0;
//     for (int i = 0; i < bit; i++)
//       if (data[i] != other.data[i])
//         return 0;
//     return 1;
//   }
//   bool operator>(const big_int other) {
//     if (sign > other.sign)
//       return 1;
//     if (sign < other.sign)
//       return 0;
//     if (bit > other.bit)
//       return sign > 0 ? 1 : 0;
//     if (bit < other.bit)
//       return sign > 0 ? 0 : 1;
//     for (int i = bit; i >= 0; i--)
//       if (data[i] > other.data[i])
//         return sign > 0 ? 1 : 0;
//     return 0;
//   }
//   bool operator<(const big_int other) {
//     if (sign > other.sign)
//       return 0;
//     if (sign < other.sign)
//       return 1;
//     if (bit > other.bit)
//       return sign > 0 ? 0 : 1;
//     if (bit < other.bit)
//       return sign > 0 ? 1 : 0;
//     for (int i = bit; i >= 0; i--)
//       if (data[i] > other.data[i])
//         return sign > 0 ? 0 : 1;
//     return 0;
//   }
//   big_int operator+(const big_int other) {
//     bit = bit > other.bit ? bit : other.bit;
//     for (int i = 0; i < bit; i++)
//       data[i] += other.data[i];
//     carry();
//     return *this;
//   }

// private:
//   void carry(void) {
//     for (int i = 0; i < bit; i++)
//       if (data[i] > 9) {
//         data[i + 1] += data[i] / 10;
//         data[i] %= 10;
//       }
//     if (data[bit]) {
//       bit++;
//       carry();
//     }
//   }
// };