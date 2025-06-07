#include "snack.cpp"
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  srand(time(0));
  int x = 10, y = 10;
  Map map(x, y);
  map.food = get_rand(x, y);
  map.snack.extend(get_rand(x, y));
  map.fresh();
  while (true) {
    char c;
    cin >> c;
    switch (c) {
    case 'w':
      map.move_up();
      break;
    case 's':
      map.move_down();
      break;
    case 'a':
      map.move_left();
      break;
    case 'd':
      map.move_right();
    }
    
  }
  return 0;
}