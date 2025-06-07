#include <iostream>
class abi {
private:
  int a, b;

public:
  abi() : a(0), b(0) {}
  abi(int a, int b) : a(a), b(b) {}
  abi(const abi &x) : a(x.a), b(x.b) {}
  abi(int real) : a(real), b(0) {}
  abi(const char str[]) { sscanf(str, "%d + %di", &a, &b); }
  void operator=(const abi x) {
    a = x.a;
    b = x.b;
  }
  void operator=(const char str[]) { sscanf(str, "%d + %di", &a, &b); }
  abi operator+(const abi x) { return abi(a + x.a, b + x.b); }
  abi operator-(const abi x) { return abi(a - x.a, b - x.b); }
  abi operator*(const abi x) {
    return abi(a * x.a - b * x.b, a * x.b + b * x.a);
  }
  abi operator/(const abi x) {
    int denominator = x.a * x.a + x.b * x.b;
    return abi((a * x.a + b * x.b) / denominator,
               (b * x.a - a * x.b) / denominator);
  }
  bool operator==(const abi x) { return a == x.a && b == x.b; }
  bool operator!=(const abi x) { return a != x.a || b != x.b; }
  friend std::istream &operator>>(std::istream &is, abi &x) {
    is >> x.a >> x.b;
    return is;
  }
  friend std::ostream &operator<<(std::ostream &os, const abi x) {
    if (x.b < 0)
      os << x.a << x.b << "i";
    if (x.b == 0)
      os << x.a;
    if (x.b > 0)
      os << x.a << "+" << x.b << "i";
    return os;
  }
};