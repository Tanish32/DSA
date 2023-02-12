#include <stddef.h>

struct Node {
    int value;
    struct Node *prev;
    struct Node *nxt;
};

int two_nodes_add_up_to_target(struct Node *head, int target) {
    struct Node *start = head;
    struct Node *end = head;
    while (end->nxt != NULL) {
        end = end->nxt;
    }
    while (start != end) {
        if (start->value + end->value == target) {
            return 1;
        } else if (start->value + end->value < target) {
            start = start->nxt;
        } else {
            end = end->prev;
        }
    }
    return 0;
}
