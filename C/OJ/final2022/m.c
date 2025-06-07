#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int n;
  struct Node *next;
} listNode;
void add_Node(listNode **now, int n, int *Nodes) {
  listNode *new = (listNode *)malloc(sizeof(listNode));
  if (!*now) {
    *now = new;
    (*now)->next = *now;
    (*now)->n = n;
    *Nodes += 1;
    return;
  }
  listNode *temp = (*now)->next;
  new->next = temp;
  (*now)->next = new;
  *now = new;
  new->n = n;
  *Nodes += 1;
}
void del_Node(listNode **now, int Nodes, int n) {
  while (Nodes-- > 1) {
    for (int i = 0; i < n - 2; i++)
      (*now) = (*now)->next;
    listNode *temp = (*now)->next;
    (*now)->next = temp->next;
    free(temp);
    (*now) = (*now)->next;
  }
}
int main() {
  int m, n;
  while (scanf("%d %d", &m, &n) != EOF) {
    listNode *now = NULL;
    int Nodes = 0;
    for (int i = 0; i < m; i++) {
      add_Node(&now, i + 1, &Nodes);
    }
    now = now->next;
    del_Node(&now, Nodes, n);
    printf("%d\n", now->n);
    free(now);
  }
  return 0;
}