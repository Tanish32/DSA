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
  int nodesNum = 0, reqSum = 0;
  scanf("%d", &nodesNum);
  Node *head = takeInputs(nodesNum);
  // Quesiton logic
  Node *start = head;
  Node *end = head;
  int a = 1, aNew = 0, b = 1, bNew = 0;
  while (end->next != NULL) {
    end = end->next;
  }
  int sumF = head->data, sumE = end->data;
  while (start != end) {
    if (sumF > sumE) {
      sumE += end->prev->data;
      end = end->prev;
      b++;
    } else if (sumF < sumE) {
      sumF += start->next->data;
      start = start->next;
      a++;

    } else {
      aNew = a;
      bNew = b;

      sumE += end->prev->data;
      end = end->prev;
      sumF += start->next->data;
      start = start->next;
      a++;
      b++;
    }
  }
  printf("%d %d", aNew, bNew);

  //   To print the array
  //   Node *ptr = head;
  //   for (int i = 0; i < nodesNum + 2; i++) {
  //     printf("%d ", ptr->data);
  //     ptr = ptr->next;
  //   }
  return 0;
}
