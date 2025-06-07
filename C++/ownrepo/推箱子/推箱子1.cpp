#include <iostream>
#include <windows.h>
using namespace std;
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
  if (a == 0)
    cout << "  ";
  if (a == 1)
    cout << "ǽ";
  if (a == 2)
    cout << "��";
  if (a == 3)
    cout << "��";
  if (a == 4)
    cout << "��";
}
void fresh(xOy &person, xOy &box, xOy &base, xOy &area) {
  int x = area.x + 2;
  int y = area.y + 2;
  system("cls");
  int map[x][y];
  for (int a, b = 0; b <= y; b++) {
    for (a = 0; a <= x; a++)
      map[a][b] = 0;
  }
  map[person.x][person.y] = 2;
  map[box.x][box.y] = 3;
  map[base.x][base.y] = 4;
  for (int a = 0; a <= x; a++) {
    map[a][0] = 1;
    map[a][y] = 1;
  }
  for (int b = 0; b <= y; b++) {
    map[0][b] = 1;
    map[x][b] = 1;
  }
  for (int a, b = 0; b <= y; b++) {
    for (a = 0; a <= x; a++)
      draw(map[a][b]);
    cout << endl;
  }
}
int main() {
  xOy person, box, base, area, preperson, prebox;
  keyevent vkup, vkdown, vkleft, vkright;
  cout << "����x:";
  cin >> area.x;
  cout << "����y:";
  cin >> area.y;
  cout << "��x:";
  cin >> person.x;
  cout << "��y:";
  cin >> person.y;
  cout << "����x:";
  cin >> box.x;
  cout << "����y:";
  cin >> box.y;
  cout << "Ŀ��x:";
  cin >> base.x;
  cout << "Ŀ��y:";
  cin >> base.y;
  system("color F");
  fresh(person, box, base, area);
  while (true) {
    if (vkup.press(VK_UP)) {
      up(person, preperson);
      if (person == box)
        press(person, preperson, box, prebox, area);
      fresh(person, box, base, area);
    }
    if (vkdown.press(VK_DOWN)) {
      down(person, preperson, area);
      if (person == box)
        press(person, preperson, box, prebox, area);
      fresh(person, box, base, area);
    }
    if (vkleft.press(VK_LEFT)) {
      left(person, preperson);
      if (person == box)
        press(person, preperson, box, prebox, area);
      fresh(person, box, base, area);
    }
    if (vkright.press(VK_RIGHT)) {
      right(person, preperson, area);
      if (person == box)
        press(person, preperson, box, prebox, area);
      fresh(person, box, base, area);
    }
    if (box == base) {
      system("color 0");
      system("color 1");
      system("color 2");
      system("color 3");
      system("color 4");
      system("color 5");
      system("color 6");
      system("color 7");
      system("color 8");
      system("color 9");
      system("color A");
      system("color B");
      system("color C");
      system("color D");
      system("color E");
      system("color F");
    }
    if (GetAsyncKeyState(VK_ESCAPE))
      return 0;
  }
  return 0;
}
