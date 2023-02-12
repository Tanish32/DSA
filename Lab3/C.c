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
Node *nextRearrange(Node *head, Node *currentSong, int data) {
  Node *ptr = head;
  int dataFound = 0;
  while (ptr->next != NULL) {
    if (ptr->data == data) {
      dataFound++;
      break;
    }
    ptr = ptr->next;
  }
  if (dataFound) {
    // see if all prev have been corrected
    Node *temp = currentSong->next;
    currentSong->next = ptr;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    ptr->next = temp;
    ptr->prev = currentSong;
    temp->prev = ptr;
  } else {
    Node *addition = malloc(sizeof(Node));
    addition->data = data;
    addition->prev = currentSong;
    addition->next = currentSong->next;
    currentSong->next = addition;
    addition->next->prev = addition;
  }
  return head;
}
int main() {
  // Initializing array
  int nodesNum = 0, a = 0, b = 0, c = 0;
  scanf("%d", &nodesNum);
  Node *head = takeInputs(nodesNum);
  // Quesiton logic
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
    case 6:
      scanf("%d", &c);
      nextRearrange(head, currentSong, c);
      break;
    default:
      b = 5;
      printf("Invalid choice");
      break;
    }
  }
  //   To print the array
  Node *ptr = head;
  for (int i = 0; i < nodesNum + 2; i++) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}
