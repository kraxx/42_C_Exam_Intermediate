#include <stdlib.h>

typedef struct s_node {
    int           data;
    struct s_node *next;
    struct s_node *other;
} Node;

Node* clone_list(Node* node) {

    if (!node)
        return 0;

    Node* original = node;
    Node* temp;

    // Clone list in-between original
    while (original) {
        temp = original->next;
        original->next = malloc(sizeof(Node));
        original->next->data = original->data;
        original->next->other = 0;
        original->next->next = temp;
        original = temp;
    }

    original = node;

    // Set other pointers for cloned list
    while (original) {
        if (original->other)
            original->next->other = original->other->next;
        if (original->next)
            original = original->next->next;
        else
            break;
    }

    original = node;
    Node* copy = node->next;
    Node* copyHead = copy;

    while (original && copy) {
        if (original->next)
            original->next = original->next->next;
        if (copy->next)
            copy->next = copy->next->next;
        original = original->next;
        copy = copy->next;
    }
    return copyHead;
}

/************
  Test Main
************/

#include <stdio.h>
Node* b(int v) {
    Node* new = malloc(sizeof(Node));
    new->data = v;
    new->next = 0;
    new->other = 0;
    return new;
}
int main() {
    Node* a = b(1);
    a->next = b(2);
    a->next->next = b(3);
    a->next->next->next = b(4);
    a->next->next->next->next = b(5);
    a->next->next->next->next->next = b(6);
    a->next->next->next->next->next->next = b(7);

    Node* a2 = a->next;
    Node* a3 = a2->next;
    Node* a4 = a3->next;
    Node* a5 = a4->next;
    Node* a6 = a5->next;
    Node* a7 = a6->next;

    a2->other = a7;
    a3->other = a;
    a5->other = a5;
    a7->other = a4;

    Node* clone = clone_list(a);
    Node* original = a;
    puts("Original:");
    while (original) {
        printf("Val: %d | Other: %d\n", original->data, original->other ? original->other->data : -1);
        original = original->next;
    }
    puts("Clone:");
    while (clone) {
        printf("Val: %d | Other: %d\n", clone->data, clone->other ? clone->other->data : -1);
        clone = clone->next;
    }
    return 0;
}


/*
CLONE_LIST
Assignment name  : clone_list
Expected files   : clone_list.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Given a linked list with the following structure :
    struct s_node {
        int           data;
        struct s_node *next;
        struct s_node *other;
    };
where :
    - next pointer points to the next node.
    - other pointer points to any node in the list (another node, itself or NULL).
Write a function to create a copy of this list (allocate new memory).
You cannot modify the structure, you cannot modify the list you are given.
The function must be declared as follows:
    struct s_node *clone_list(struct s_node *node);
*/
