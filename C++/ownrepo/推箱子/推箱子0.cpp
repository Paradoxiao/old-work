#include "base.cpp"
#include <iostream>
#include <windows.h>

using namespace std;
int main() {
  xOy area, person, box, base, preperson, prebox;
  keyevent vkup, vkdown, vkleft, vkright;
  int x, y = 0;
  cout << "����x:";
  cin >> x;
  cout << "����y:";
  cin >> y;
  x++;
  y++;
  list map(x, y);
  area.x = x;
  area.y = y;
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
  fresh(person, box, base, map, x, y);
  while (true) {
    if (vkup.press(VK_UP)) {
      up(person, preperson);
      if (person == box)
        press(person, preperson, box, prebox, area);
      fresh(person, box, base, map, x, y);
    }
    if (vkdown.press(VK_DOWN)) {
      down(person, preperson, area);
      if (person == box)
        press(person, preperson, box, prebox, area);
      fresh(person, box, base, map, x, y);
    }
    if (vkleft.press(VK_LEFT)) {
      left(person, preperson);
      if (person == box)
        press(person, preperson, box, prebox, area);
      fresh(person, box, base, map, x, y);
    }
    if (vkright.press(VK_RIGHT)) {
      right(person, preperson, area);
      if (person == box)
        press(person, preperson, box, prebox, area);
      fresh(person, box, base, map, x, y);
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
