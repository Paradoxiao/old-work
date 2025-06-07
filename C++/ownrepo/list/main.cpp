#include "list.cpp"
#include "queue.cpp"
#include <iostream>
int main() {
  MyList<int> data;
  for (int i = 0; i < 5; i++)
    data.add_Node(i);
  return 0;
}