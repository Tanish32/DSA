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
void currentSong() {}
int main() {
  // initializing doubly linked list
  int nodesNum = 0;
  scanf("%d", &nodesNum);
  int a = 0, b = 0;
  scanf("%d", &a);
  Node *head = append(NULL, a);
  for (int i = 1, a = 0; i < nodesNum; i++) {

    scanf("%d", &a);
    append(head, a);
  }
  Node *currentSong = head;
  while (b != 5) {
    scanf("%d", &b);
    switch (b) {
    case 1:
      scanf("%d", &a);
      append(head, a);
      break;
    case 2:
      printf("Current song: %d\n", currentSong->data);
      break;
    case 3:
      if (currentSong->next != NULL) {
        currentSong = currentSong->next;
      }
      break;
    case 4:
      if (currentSong != head) {
        currentSong = currentSong->prev;
      }
      break;
    case 5:
      b = 5;
      break;
    default:
      b = 5;
      printf("Invalid choice");
      break;
    }
  }
  // To print the array
  // Node *ptr = head;
  // for (int i = 0; i < nodesNum; i++) {
  //   printf("%d ", ptr->data);
  //   ptr = ptr->next;
  // }
}
