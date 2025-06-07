#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int m;
  int n;
  struct Node *next;
} listNode;
void add_Node(listNode **now, int m, int n, int *Nodes) {
  listNode *new = (listNode *)malloc(sizeof(listNode));
  if (!*now) {
    *now = new;
    (*now)->next = *now;
    (*now)->m = m;
    (*now)->n = n;
    *Nodes += 1;
    return;
  }
  listNode *temp = (*now)->next;
  new->next = temp;
  (*now)->next = new;
  *now = new;
  new->m = m;
  new->n = n;
  *Nodes += 1;
}
void del_Node(listNode **now, int Nodes) {
  while (Nodes-- > 1) {
    int n = (*now)->m;
    for (int i = 0; i < n - 1; i++)
      (*now) = (*now)->next;
    printf(" %d %d\n", (*now)->next->m, (*now)->next->n);
    listNode *temp = (*now)->next;
    (*now)->next = temp->next;
    free(temp);
    (*now) = (*now)->next;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    listNode *now = NULL;
    int Nodes = 0;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      int j;
      scanf("%d", &j);
      add_Node(&now, j, i + 1, &Nodes);
    }
    now = now->next;
    del_Node(&now, Nodes);
  }
  return 0;
}