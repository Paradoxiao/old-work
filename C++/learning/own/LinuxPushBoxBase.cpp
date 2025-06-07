#include <iostream>
#include <termios.h>
#include <vector>
using namespace std;
struct xOy {
  int x;
  int y;
};
class list {
private:
  vector<vector<int>> data;

public:
  list(int x, int y) {
    data.resize(x + 1);
    for (int i = 0; i < x + 1; i++)
      data[i].resize(y + 1);
  }
  void change(int value, int x, int y) { data[x][y] = value; }
  int view(int x, int y) { return data[x][y]; }
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
  switch (a) {
  case 0:
    cout << "  ";
    break;
  case 1:
    cout << "墙";
    break;
  case 2:
    cout << "人";
    break;
  case 3:
    cout << "箱";
    break;
  case 4:
    cout << "洞";
    break;
  }
}
void fresh(xOy &person, xOy &box, xOy &base, list &area, int x, int y) {
  system("clear");
  for (int a, b = 0; b < y; b++) {
    for (a = 0; a < x; a++) {
      area.change(0, a, b);
    }
  }
  area.change(2, person.x, person.y);
  area.change(3, box.x, box.y);
  area.change(4, base.x, base.y);
  for (int a = 0; a <= x; a++) {
    area.change(1, a, 0);
    area.change(1, a, y);
  }
  for (int b = 0; b <= y; b++) {
    area.change(1, 0, b);
    area.change(1, x, b);
  }
  for (int a, b = 0; b <= y; b++) {
    for (a = 0; a <= x; a++)
      draw(area.view(a, b));
    cout << endl;
  }
}
int getrand(int min, int max) { return (rand() % (max - min + 1)) + min; }
int main() {
  xOy area, person, box, base, preperson, prebox;
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
  srand(time(0));
CREATE:
  person.x = getrand(1, x - 1);
  person.y = getrand(1, y - 1);
  box.x = getrand(2, x - 2);
  box.y = getrand(2, y - 2);
  base.x = getrand(1, x - 1);
  base.y = getrand(1, y - 1);
  if (person == box or person == base or box == base)
    goto CREATE;
  system("set_color F");
  fresh(person, box, base, map, x, y);
  char ch;
  termios tms_old, tms_new;
  tcgetattr(0, &tms_old);
  tms_new = tms_old;
  tms_new.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(0, TCSANOW, &tms_new);
  while (true) {
    cin >> ch;
    if (ch == 'w') {
      up(person, preperson);
      if (person == box)
        press(person, preperson, box, prebox, area);
      fresh(person, box, base, map, x, y);
    }
    if (ch == 's') {
      down(person, preperson, area);
      if (person == box)
        press(person, preperson, box, prebox, area);
      fresh(person, box, base, map, x, y);
    }
    if (ch == 'a') {
      left(person, preperson);
      if (person == box)
        press(person, preperson, box, prebox, area);
      fresh(person, box, base, map, x, y);
    }
    if (ch == 'd') {
      right(person, preperson, area);
      if (person == box)
        press(person, preperson, box, prebox, area);
      fresh(person, box, base, map, x, y);
    }
    if (box == base) {
      cout << "\aYou Win!" << endl;
    }
    if (ch == 'q')
      return 0;
  }
  tcsetattr(0, TCSANOW, &tms_old);
  return 0;
}