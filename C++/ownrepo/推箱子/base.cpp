#include <iostream>
#include <windows.h>
using namespace std;
struct xOy {
  int x;
  int y;
};
bool operator==(xOy a, xOy b) {
  if (a.x == b.x and a.y == b.y)
    return true;
  else
    return false;
}
struct listNode {
  int a;
  listNode *next;
  listNode(void) {
    a = 0;
    next = NULL;
  }
};
class list {
private:
  listNode *top;

public:
  listNode *now;
  list(int a, int b) {
    top = NULL;
    now = NULL;
    for (int i = 0; i < a * b; i++) {
      listNode *newNode = new listNode();
      if (!top) {
        top = newNode;
        top->next = top;
      } else {
        listNode *temp = top->next;
        top->next = newNode;
        newNode->next = temp;
        top = top->next;
      }
    }
  }
  ~list(void) {
    listNode *temp;
    while (top) {
      temp = top;
      top = top->next;
      delete temp;
    }
  }
  void change(int data, int x, int y, int hang) {
    now = top->next;
    for (int i = 0; i < y; i++)
      for (int l = 0; l < hang; l++)
        now = now->next;
    for (int i = 0; i < x; i++)
      now = now->next;
    now->a = data;
  }
  int view(int x, int y, int hang) {
    now = top->next;
    for (int i = 0; i < y; i++)
      for (int l = 0; l < hang; l++)
        now = now->next;
    for (int i = 0; i < x; i++)
      now = now->next;
    return now->a;
  }
};
class keyevent {
private:
  bool lock;

public:
  keyevent(void) { lock = false; }
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
void up(xOy &xy, xOy &temp) {
  temp = xy;
  if (xy.y > 1)
    xy.y -= 1;
}
void left(xOy &xy, xOy &temp) {
  temp = xy;
  if (xy.x > 1)
    xy.x -= 1;
}
void down(xOy &xy, xOy &temp, xOy &area) {
  temp = xy;
  if (xy.y < area.y - 1)
    xy.y += 1;
}
void right(xOy &xy, xOy &temp, xOy &area) {
  temp = xy;
  if (xy.x < area.x - 1)
    xy.x += 1;
}
void press(xOy &person, xOy &preperson, xOy &box, xOy &prebox, xOy &area) {
  if (person.y - 1 == preperson.y) {
    down(box, prebox, area);
    if (prebox == box)
      person = preperson;
  }
  if (person.y + 1 == preperson.y) {
    up(box, prebox);
    if (prebox == box)
      person = preperson;
  }
  if (person.x - 1 == preperson.x) {
    right(box, prebox, area);
    if (prebox == box)
      person = preperson;
  }
  if (person.x + 1 == preperson.x) {
    left(box, prebox);
    if (prebox == box)
      person = preperson;
  }
}
void draw(int a) {
  switch (a) {
  case 0:
    cout << "  ";
    break;
  case 1:
    cout << "ǽ";
    break;
  case 2:
    cout << "��";
    break;
  case 3:
    cout << "��";
    break;
  case 4:
    cout << "��";
    break;
  }
  // if(a==0)cout<<"
  // ";if(a==1)cout<<"ǽ";if(a==2)cout<<"��";if(a==3)cout<<"��";if(a==4)cout<<"��";
}
void fresh(xOy &person, xOy &box, xOy &base, list &area, int x, int y) {
  system("cls");
  for (int a, b = 0; b < y; b++) {
    for (a = 0; a < x; a++) {
      area.change(0, a, b, x);
    }
  }
  area.change(2, person.x, person.y, x);
  area.change(3, box.x, box.y, x);
  area.change(4, base.x, base.y, x);
  for (int a = 0; a <= x; a++) {
    area.change(1, a, 0, x);
    area.change(1, a, y, x);
  }
  for (int b = 0; b <= y; b++) {
    area.change(1, 0, b, x);
    area.change(1, x, b, x);
  }
  for (int a, b = 0; b <= y; b++) {
    for (a = 0; a <= x; a++)
      draw(area.view(a, b, x));
    cout << endl;
  }
}
/*
void random(xOy a,int xx,int yy)
{
        srand(21478);
        do
        a.x=rand()%xx;
        while(a.x<=1);
        do
        a.y=rand()%yy;
        while(a.y<=1);
}
*/
