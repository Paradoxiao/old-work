#include <cstdio>
#include <iostream>
using namespace std;
class List {
private:
  struct Node {
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
  };
  class iterator {
  private:
    Node *ptr;

  public:
    iterator(Node *ptr) : ptr(ptr) {}
    bool operator!=(iterator other) {
      return ptr != other.ptr;
    }
    iterator operator++() {
      ptr = ptr->next;
      return *this;
    }
    int operator*() {
      return ptr->data;
    }
  };

private:
  Node *head, *now, *tail;

public:
  List(void) : head(nullptr), now(nullptr), tail(nullptr) {}
  void add(int data) {
    Node *newNode = new Node(data);
    if (!head) {
      head = now = tail = newNode;
      return;
    }
    tail->next = newNode;
    tail = newNode;
  }
  iterator begin() {
    return iterator(head);
  }
  iterator end() {
    return iterator(nullptr);
  }
};
int main() {
  List a;
  for (int i = 0; i < 10; i++)
    a.add(i);
  for (int i : a)
    cout << i << " ";
  cout << endl;
  for (int i : a)
    cout << i << " ";
  return 0;
}