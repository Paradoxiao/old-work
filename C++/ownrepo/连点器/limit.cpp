#include <iostream>
#include <windows.h>
// #decline getkey(VK) GetAsyncKeyState(VK) and a==0
using namespace std;
struct place {
  POINT point;
  place *nextpl;
  place *lastpl;
  place(POINT &p) {
    nextpl = nullptr, lastpl = nullptr;
    point.x = p.x, point.y = p.y;
  }
};
class placelist {
private:
  place *top;
  int number;

public:
  placelist(void) {
    top = NULL;
    number = 0;
  }
  ~placelist(void) {
    place *temp = NULL;
    top = top->nextpl;
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
      top->lastpl = newplace;
      number = 1;
      return;
    }
    top = top->nextpl;
    place *temp = top->nextpl;
    top->nextpl = newplace;
    newplace->lastpl = top;
    temp->lastpl = newplace;
    newplace->nextpl = temp;
    number++;
  }
  void delpl(void) {
    if (number <= 1) {
      cout << "error" << endl;
      return;
    }
    // if(number==1){delete top;top=NULL;number=0;return;}
    place *temp = top->nextpl->nextpl;
    top->nextpl->nextpl = NULL;
    top->nextpl->lastpl = NULL;
    delete top->nextpl;
    temp->lastpl = top;
    top->nextpl = temp;
    top = top->lastpl;
    number -= 1;
  }
  POINT outpl(void) {
    POINT p;
    if (!top) {
      cout << "error" << endl;
      return p;
    }
    return top->nextpl->point;
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
  now.x = (pllist.outpl()).x;
  now.y = (pllist.outpl()).y;
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
  now.x = (pllist.outpl()).x;
  now.y = (pllist.outpl()).y;
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
      break;
    if (p.press(80)) {
      cin >> sleep;
    }
    if (del.press(VK_DELETE)) {
      delpl(points, now);
    }
    if (home.press(VK_HOME)) {
      delpl(points, now);
      getpl(points, now);
    }
  }

  return 0;
}
