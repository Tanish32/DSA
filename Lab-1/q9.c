#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct Node_t
{
    int data;
    struct Node_t *next;
};
typedef struct Node_t Node;
// Creates a new node with given value and returns a pointer to it
Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
// Creates a new node with given value and adds it to
// the back of the given singly linked list,
// returns a pointer to the newly created node
Node *addToList(Node *head, int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        return newNode;
    }
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    return newNode;
}
// Creates a singly linked list by reading input and
// returns a pointer the head of the newly created linked list
Node *readList()
{
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);

        if (head == NULL)
        {
            head = addToList(head, x);
        }
        else
        {
            addToList(head, x);
        }
    }
    return head;
}
// Prints the values stored in the nodes of the given singly linked list
void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}
// Frees the memory dynamically allocated to
// all the nodes of the given singly linked list
void freeList(Node *head)
{
    Node *cur, *nxt;
    cur = head;
    while (cur != NULL)
    {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }
}
// Function definition goes here
struct bitsID
{
    char email[40];
    char branch[4];
    char id[13];
};
void printID(struct bitsID input)
{
    char id[13] = {0};
    for (int i = 0; i < 4; i++)
    {
        id[i] = input.email[i + 1];
        // printf("%c", id[i]);
        id[i + 8] = input.email[i + 5];
    }
    // printf("@%s@",input.branch);
    if (input.branch[0] == 'C' && input.branch[1] == 'S')
    {
        // printf("Hi");
        id[4] = 'A';
        id[5] = '7';
    }
    if (input.branch[0] == 'E' && input.branch[1] == 'C' && input.branch[2] == 'E')
    {
        id[4] = 'A';
        id[5] = 'A';
    }
    if (input.branch[0] == 'E' && input.branch[1] == 'E' && input.branch[2] == 'E')
    {
        id[4] = 'A';
        id[5] = '3';
    }
    id[6] = 'P';
    id[7] = 'S';
    id[12] = 'H';

    for (int i = 0; i < 13; i++)
    {
        printf("%c", id[i]);
    }
    printf("\n");
}

int main()
{
    struct bitsID input;
    // input.email = "f20200010@hyderabad.bits-pilani.ac.in";
    // input.branch = "CS";
    scanf("%s", input.email);
    scanf("%s", input.branch);
    // printf("%s", input.branch);
    printID(input);
    return 0;
}
