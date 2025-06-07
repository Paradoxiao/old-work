#ifndef SNACK_H
#define SNACK_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
struct xOy {
  int x;
  int y;
};
class Snack {
private:
  struct Node {
    xOy data;
    Node *next;
    Node(xOy data) : data(data), next(nullptr){};
  };
  Node *head;
  Node *tail;
  int length;
  friend struct Map;

public:
  Snack() : head(nullptr), tail(nullptr), length(0){};
  ~Snack() {
    while (head) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }
  void add(xOy data) {
    Node *newNode = new Node(data);
    length++;
    if (!length) {
      head = newNode;
      tail = newNode;
      return;
    }
    tail->next = newNode;
    tail = newNode;
  }
  void extend(xOy data) {
    Node *newNode = new Node(data);
    length++;
    newNode->next = head;
    head = newNode;
  }
  void pop() {
    if (!length) {
      return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    length--;
  }
  void push(xOy data) {
    pop();
    add(data);
  }
};
std::string null = "  ";
struct Map {
  xOy food;
  Snack snack;
  std::vector<std::vector<std::string>> map;
  int x, y;
  Map(int x, int y) : map(x, std::vector<std::string>(y, null)), x(x), y(y) {}
  void fresh() {
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        map[i][j] = "  ";
      }
    }
    map[food.x][food.y] = "食";
    Snack::Node *temp = snack.head;
    while (temp) {
      map[temp->data.x][temp->data.y] = "蛇";
      temp = temp->next;
    }
    for (int i = 0; i < x; i++) {
      map[i][0] = "墙";
      map[i][y - 1] = "墙";
    }
    for (int i = 0; i < y; i++) {
      map[0][i] = "墙";
      map[x - 1][i] = "墙";
    }
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        std::cout << map[i][j];
      }
      std::cout << std::endl;
    }
  }
  void move_up() {
    xOy temp = snack.head->data;
    if (temp.x == 1) {
      temp.x = x - 2;
    } else {
      temp.x--;
    }
    snack.push(temp);
    fresh();
  }
  void move_down() {
    xOy temp = snack.head->data;
    if (temp.x == x - 2) {
      temp.x = 1;
    } else {
      temp.x++;
    }
    snack.push(temp);
    fresh();
  }
  void move_left() {
    xOy temp = snack.head->data;
    if (temp.y == 1) {
      temp.y = y - 2;
    } else {
      temp.y--;
    }
    snack.push(temp);
    fresh();
  }
  void move_right() {
    xOy temp = snack.head->data;
    if (temp.y == y - 2) {
      temp.y = 1;
    } else {
      temp.y++;
    }
    snack.push(temp);
    fresh();
  }
};
xOy get_rand(int x, int y) {
  xOy temp;
  temp.x = rand() % (x - 2) + 1;
  temp.y = rand() % (y - 2) + 1;
  return temp;
}
#endif // SNACK_H