#include <iostream>
#include <windows.h>
using namespace std;
struct place {
  POINT point;
  place *nextpl;
  place *lastpl;
  place(POINT &p) {
    nextpl, lastpl = NULL;
    point.x = p.x;
    point.y = p.y;
  }
};
class placelist {
private:
  int number;

public:
  place *top;
  placelist(void) {
    top = NULL;
    number = 0;
  }
  ~placelist(void) {
    place *temp = NULL;
    for (int i = 0; i < number; i++) {
      temp = top->nextpl;
      delete top;
      top = temp;
    };
  }
  void addpl(POINT &p) {
    place *newplace = new place(p);
    if (!top) {
      top = newplace;
      top->nextpl = top;
      top->lastpl;
      number = 1;
      return;
    }
    place *temp = top->nextpl;
    top->nextpl = newplace;
    newplace->lastpl = top;
    temp->lastpl = newplace;
    newplace->nextpl = temp;
    top = top->nextpl;
    number++;
  }
  void delpl(void) {
    if (number <= 1) {
      cout << "error" << endl;
      return;
    }
    place *temp = top->nextpl;
    temp->lastpl = top->lastpl;
    top->lastpl->nextpl = temp;
    top->nextpl = NULL;
    top->lastpl = NULL;
    delete top;
    top = temp;
    number -= 1;
  }
  void nextpoint(void) {
    if (!top) {
      cout << "error" << endl;
      return;
    }
    top = top->nextpl;
  }
  void lastpoint(void) {
    if (!top) {
      cout << "error" << endl;
      return;
    }
    top = top->lastpl;
  }
  int count(void) {
    return number;
  }
};
class keyevent {
private:
  bool lock;

public:
  keyevent(void) {
    lock = false;
  }
  bool press(int vk) {
    bool down = GetAsyncKeyState(vk) & 0x8000;
    if (!lock and down) {
      lock = true;
      return down;
    } else if (lock and !down) {
      lock = false;
      return false;
    }
    return false;
  }
};
void getpl(placelist &pllist, POINT &now) {
  POINT p;
  GetCursorPos(&p);
  pllist.addpl(p);
  now.x = p.x;
  now.y = p.y;
}
void show(placelist &pllist, POINT &now) {
  now.x = pllist.top->point.x;
  now.y = pllist.top->point.y;
  SetCursorPos(now.x, now.y);
}
void press(POINT now, int p) {
  SetCursorPos(now.x, now.y);
  /*
  keybd_event(VK_LBUTTON,0,0,0);
  keybd_event(VK_LBUTTON,0,KEYEVENTF_KEYUP,0);
  */
  mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
  Sleep(p);
}
void delpl(placelist &pllist, POINT &now) {
  pllist.delpl();
  now.x = pllist.top->point.x;
  now.y = pllist.top->point.y;
}
int main() {
  placelist points;
  int sleep;
  POINT now;
  keyevent q, p, up, down, del, home;
  cin >> sleep;
  while (true) {
    if (q.press(97)) {
      getpl(points, now);
    }
    while (GetAsyncKeyState(98) & 0x8000)
      press(now, sleep);
    while (GetAsyncKeyState(96) & 0x8000) {
      press(now, sleep);
      points.nextpoint();
      show(points, now);
    }
    if (up.press(VK_UP)) {
      points.lastpoint();
      show(points, now);
    }
    if (down.press(VK_DOWN)) {
      points.nextpoint();
      show(points, now);
    }
    if (GetAsyncKeyState(VK_ESCAPE))
      return 0;
    if (p.press(80))
      cin >> sleep;
    if (del.press(VK_DELETE))
      delpl(points, now);
    if (home.press(VK_HOME))
      GetCursorPos(&(points.top->point));
  }

  return 0;
}
