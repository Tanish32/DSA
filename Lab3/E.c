#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};
typedef struct node Node;

Node *append(Node *head, int data) {
  Node *temp = malloc(sizeof(Node));
  if (head == NULL) {
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    head = temp;
    return temp;
  } else {
    Node *ptr = head;
    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    ptr->next = temp;
    temp->data = data;
    temp->prev = ptr;
    temp->next = NULL;
    return head;
  }
}
Node *takeInputs(int nodesNum) {
  int a = 0, b = 0;
  scanf("%d", &a);
  Node *firstHead = append(NULL, a);
  for (int i = 1, a = 0; i < nodesNum; i++) {

    scanf("%d", &a);
    append(firstHead, a);
  }
  return firstHead;
}
int main() {
  // Initializing array
  int nodesNum = 0, cycles = 0;
  scanf("%d", &nodesNum);
  scanf("%d", &cycles);
  Node *head = takeInputs(nodesNum);
  // Quesiton logic
  Node *start = head;
  for (int i = 0; i < nodesNum-cycles; i++) {
    start = head;
    append(head, start->data);
    head = head->next;
    free(start);
  }
  //   To print the array
    Node *ptr = head;
    for (int i = 0; i < nodesNum ; i++) {
      printf("%d ", ptr->data);
      ptr = ptr->next;
    }

  return 0;
}
