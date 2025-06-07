#ifndef MyQueue_H
#define MyQueue_H
template <class T> class MyQueue {
private:
  struct Node {
    T data;
    Node *next, *prev;
    Node(T data) : data(data), next(nullptr) {}
  };
  Node *front, *back, *now;
  unsigned long long size;

public:
  MyQueue(void) : size(0), front(nullptr), back(nullptr) {}
  ~MyQueue(void) {
    if (!front)
      return;
    Node *tmp = front;
    do {
      Node *next = front->next;
      delete front;
      front = next;
    } while (front != tmp);
  }
  unsigned long long get_size(void) { return size; }
  T get_front(void) {
    if (!front)
      return T();
    return front->data;
  }
  T get_back(void) {
    if (!back)
      return T();
    return back->data;
  }
  void push(T data) {
    Node *new_node = new Node(data);
    if (!front) {
      front = new_node;
      back = new_node;
      return;
    }
    back->next = new_node;
    back = new_node;
    size++;
  }
  void pop(void) {
    if (!front)
      return;
    Node *tmp = front;
    front = front->next;
    delete tmp;
    size--;
  }
  void change_front(T data) {
    if (!front)
      return;
    front->data = data;
  }
  void change_back(T data) {
    if (!back)
      return;
    back->data = data;
  }
  void change_now(T data) {
    if (!now)
      return;
    now->data = data;
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
  void move_front(void) { now = front; }
  void move_back(void) { now = back; }
  T get_now(void) {
    if (!now)
      return T();
    return now->data;
  }
  void change_length(unsigned long long length) {
    if (size < length) {
      for (unsigned long long i = size; i < length; i++)
        push(T());
    } else if (size > length) {
      for (unsigned long long i = size; i > length; i--)
        pop();
    }
  }
};
#endif