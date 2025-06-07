#ifndef MYLIST_H
#define MYLIST_H
template <class T> class MyList {
private:
  struct Node {
    T data;
    Node *next, *prev;
    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
  };
  Node *now;
  unsigned long long size;

public:
  MyList(void) : size(0), now(nullptr) {}
  ~MyList(void) {
    if (!now)
      return;
    Node *tmp = now;
    do {
      Node *next = now->next;
      delete now;
      now = next;
    } while (now != tmp);
  }
  unsigned long long get_size(void) { return size; }
  T get_now(void) {
    if (!now)
      return T();
    return now->data;
  }
  void add_Node(T data) {
    Node *new_node = new Node(data);
    if (!now) {
      now = new_node;
      now->next = now;
      now->prev = now;
      return;
    }
    new_node->next = now->next;
    new_node->prev = now;
    now->next->prev = new_node;
    now->next = new_node;
    now = new_node;
    size++;
  }
  void del_now_move_next(void) {
    if (!now)
      return;
    Node *tmp = now;
    now->prev->next = now->next;
    now->next->prev = now->prev;
    now = now->next;
    delete tmp;
    size--;
  }
  void del_now_move_prev(void) {
    if (!now)
      return;
    Node *tmp = now;
    now->prev->next = now->next;
    now->next->prev = now->prev;
    now = now->prev;
    delete tmp;
    size--;
  }
  void del_next(void) {
    if (!now)
      return;
    Node *tmp = now->next;
    now->next = now->next->next;
    now->next->prev = now;
    delete tmp;
    size--;
  }
  void del_prev(void) {
    if (!now)
      return;
    Node *tmp = now->prev;
    now->prev = now->prev->prev;
    now->prev->next = now;
    delete tmp;
    size--;
  }
  void move_next(void) {
    if (!now)
      return;
    now = now->next;
  }
  void move_prev(void) {
    if (!now)
      return;
    now = now->prev;
  }
  void clear(void) {
    if (!now)
      return;
    Node *tmp = now;
    do {
      Node *next = now->next;
      delete now;
      now = next;
    } while (now != tmp);
    size = 0;
  }
};
#endif