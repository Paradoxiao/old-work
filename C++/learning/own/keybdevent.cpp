#include <iostream>
#include <stdio.h>
#include <termio.h>
using namespace std;
int main() {
  termios tms_old, tms_new;
  tcgetattr(0, &tms_old);
  tms_new = tms_old;
  tms_new.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(0, TCSANOW, &tms_new);
  int i = 0;
  while (1) {
    char ch = getchar();
    if (ch == '+')
      cout << ++i;
    if (ch == '-')
      cout << --i;
  }
  tcsetattr(0, TCSANOW, &tms_old);
  return 0;
}