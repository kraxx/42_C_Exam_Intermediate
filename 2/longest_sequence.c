typedef struct s_node {
    int value;
    struct s_node* left;
    struct s_node* right;
} Node;

#define MAX(a, b) (a > b ? a : b)

int recurse(Node* node, int parentVal, int depth) {

    if (!node)
        return 0;

    int current = 1;

    if (node->value == parentVal + 1)
        current = depth + 1;

    return MAX(MAX(recurse(node->left, node->value, current), recurse(node->right, node->value, current)), current);
}

int longest_sequence(Node* root) {

	return recurse(root, ~0u >> 1, 0);
}

/************
  Test Main
************/

#include <stdio.h>
#include <stdlib.h>
Node* b(int v) {
    Node* new = malloc(sizeof(Node));
    new->value = v;
    new->left = 0;
    new->right = 0;
    return new;
}
int main() {
    Node* n = b(10);
    n->left = b(5);
    n->left->left = b(6);
    n->left->left->left = b(7);
    n->left->left->right = b(13);
    n->left->right = b(9);
    printf("%d\n", longest_sequence(n));

    Node* m = b(5);
    m->left = b(6);
    m->right = b(4);
    m->right->left = b(9);
    m->right->left->left = b(3);
    m->right->left->right = b(2);
    m->right->right = b(3);
    m->right->right->right = b(2);
    printf("%d\n", longest_sequence(m));

    Node* o = b(30);
    o->left = b(15);
    o->left->left = b(61);
    o->right = b(41);
    o->right->right = b(80);
    printf("%d\n", longest_sequence(o));

    printf("%d\n", longest_sequence(0));

    return 0; 
}

/*
LONGEST_SEQUENCE
Assignment name  : longest_sequence
Expected files   : longest_sequence.c
Allowed functions: 
--------------------------------------------------------------------------------

Given the root node of a binary tree, create a function that return the length of the longest path which comprises of nodes with consecutive values in increasing order.
Every node is considered as a path of length 1.

The binary tree uses the following node structure :

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

The function must be declared as follows:

int	longest_sequence(struct s_node *node);


Example 1:

       10
       /
      5
     / \
    /   \
   6    9
  / \
 /   \
7   13

In this case, it should return 3 (because the longest consecutive sequence is: 5 -> 6 -> 7).

Example 2:

   5
  / \
 /   \
6     4
    /  \
   9    3
 /  \    \
3    2    2

In this case, your function return 2 (because the longest consecutive sequence is: 5 -> 6 ).

Example 3: 

    30
    / \
   /   \
  15   41
 /     /
61    80

In this case, it should return 1.

Example 4:

NULL

In this case, as the root node is null, your function should return 0.
*/