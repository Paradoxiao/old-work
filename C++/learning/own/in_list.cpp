#include <iostream>
using namespace std;
class My_list {
private:
  struct Node {
    int data;
    Node *nextNode;
    Node *preNode;
    Node(int data) {
      nextNode = preNode = NULL;
      this->data = data;
    }
  };

private:
  Node *nowNode, *headNode;
  int n;

public:
  My_list(void) {
    n = 0;
    nowNode = headNode = NULL;
  }
  void addNode(int data) {
    Node *newNode = new Node(data);
    n++;
    if (!nowNode) {
      nowNode = newNode;
      nowNode->nextNode = nowNode;
      nowNode->preNode = nowNode;
      headNode = nowNode;
      return;
    }
    Node *temp = nowNode->nextNode;
    nowNode->nextNode = newNode;
    newNode->preNode = nowNode;
    temp->preNode = newNode;
    newNode->nextNode = temp;
    nowNode = newNode;
  }
  void delNode(int sign) {
    if (!sign || n <= 1) {
      cout << "Con't delete!" << endl;
      return;
    }
    nowNode->preNode->nextNode = nowNode->nextNode;
    nowNode->nextNode->preNode = nowNode->preNode;
    Node *temp = sign < 0 ? nowNode->preNode : nowNode->nextNode;
    delete nowNode;
    nowNode = temp;
    n--;
  }
  void output(void) {
    Node *temp = nowNode->nextNode;
    for (int i = 0; i < n; i++) {
      cout << temp->data << ' ';
      temp = temp->nextNode;
    }
  }
};
int main() {
  My_list data;
  for (int i = 0; i < 10; i++)
    data.addNode(i);
  data.output();
  return 0;
}