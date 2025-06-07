#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
struct bit_field {
  unsigned int a : 1;
  int b : 2;
  int c : 3;
};
struct num_list {
  int n;
  int num[];
};
union data {
  char a;
  int b;
  double c;
};
struct union_struct {
  union data data;
  int num;
};
struct function {
  int (*callback)(int);
  int flag;
};
struct circle {
  double r;
  double (*S)(struct circle *);
  double (*C)(struct circle *);
};
#define pi 3.14
double getS(struct circle *this) { return pi * this->r * this->r; }
double getC(struct circle *this) { return 2 * pi * this->r; }
struct point {
  int x;
  int y;
};
struct segment {
  struct point a;
  struct point b;
};
int main() {
  struct bit_field a;
  a.a = 1;
  printf("%lu", sizeof(a));
}