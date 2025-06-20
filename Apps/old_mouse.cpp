#include <iostream>
#include <windows.h>
#define click mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0)
using namespace std;
int main() {
  POINT p[6], q[6];
  int b, sleep = 0;
  cin >> sleep;
  for (int i = 0; i < 6; i++)
    p[i].x = 0, p[i].y = 0, q[i].x = 0, q[i].y = 0;
  while (true) {
    for (int i = 0; i < 6; i++) {
      b = i + '1';
      if (GetAsyncKeyState(b)) {
        GetCursorPos(&p[i]);
        if (p[a].x != q[a].x || p[a].y != q[a].y) {
          cout << i << ":" << endl
               << "x " << p[i].x << " " << "y " << p[i].y << endl;
          q[i].x = p[i].x, q[i].y = p[i].y;
        }
        Sleep(sleep);
      }
    }
    if (getAsyncKeyState('r'))
      for (int i = 0; i < 6; i++)
        p[i].x = 0, p[i].y = 0, q[i].x = 0, q[i].y = 0;
  }
  if (getAsyncKeyState('s'))
    cin >> sleep;
  while (GetAsyncKeyState('0')) {
    for (int i = 0; i < 6; i++)
      if (p[i].x != 0 || p[i].y != 0) {
        GetCursorPos(&p[i]);
        click;
        Sleep(sleep);
      }
  }
  while (GetAsyncKeyState('8')) {
    click;
    Sleep(sleep);
  }
  if (GetAsyncKeyState('7'))
    while (true) {
      click;
      Sleep(sleep);
      if (GetAsyncKeyState('9'))
        break;
    }
  if (GetAsyncKeyState(VK_ESCAPE))
    break;
  Sleep(sleep);
}
return 0;
}
