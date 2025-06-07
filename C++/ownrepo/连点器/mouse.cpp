#include <iostream>
#include <windows.h>
using namespace std;
int main() {
  while (true) {
    if (GetAsyncKeyState(VK_SPACE))
      for (;;) {
        mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        Sleep(1);
        if (GetAsyncKeyState(VK_PAUSE))
          return 0;
      }
  }
  return 0;
}
