typedef struct s_node {
    int value;
    struct s_node *left;
    struct s_node *right;
} Node;

#define MAX(a, b) (a > b ? a : b)

int longest(Node* n) {
    if (!n)
        return 0;
    return MAX(longest(n->left), longest(n->right)) + 1;
}

int width_tree(Node* n) {

    if (!n)
        return 0;

    int width = longest(n->left) + longest(n->right) + 1;

    return MAX(MAX(width_tree(n->left), width_tree(n->right)), width);
}

/************
  Test Main
************/

#include <stdio.h>
#include <stdlib.h>
Node* b(int v) {
    Node* new = malloc(sizeof(Node));
    new->value = v;
    new->left = new->right = 0;
    return new;
}
int main() {
    Node* r = b(1);

    r->left = b(2);
    r->left->left = b(3);
    r->left->right = b(4);
    r->left->right->left = b(6);

    r->right = b(5);
    r->right->left = b(7);
    r->right->right = b(8);

    printf("%d\n", width_tree(r));

    Node* a = b(1);

    a->left = b(2);
    a->left->left = b(4);
    a->left->left->left = b(5);
    a->left->left->left->right = b(8);

    a->left->left->right = b(6);
    a->left->right = b(7);
    a->left->right->left = b(9);
    a->left->right->left->left = b(11);
    a->left->right->left->right = b(12);

    a->left->right->right = b(10);
    a->left->right->right->right = b(13);

    a->right = b(3);
    printf("%d\n", width_tree(a));

    Node* c = b(10);
    c->right = b(12);
    printf("%d\n", width_tree(c));

    Node *d = b(25);
    d->left = b(33);
    d->left->left = b(12);
    d->left->right = b(9);
    d->left->right->left = b(3);
    printf("%d\n", width_tree(d));

    Node *e = b(10);
    printf("%d\n", width_tree(e));

    return 0;
}

/*
WIDTH_TREE

Assignment name  : width_tree
Expected files   : width_tree.c
Allowed functions: 
--------------------------------------------------------------------------------

ALERT: OPTIMIZED SOLUTION REQUIRED.

Given the root node of a binary tree, create a function that returns the
'width' of the tree, which is the number of node present on the longest
path between two leaves in the tree.

The binary tree uses the following node structure :

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

The function must be declared as follows:

int	width_tree(struct s_node *n);

Consideration:

- Be careful: the naive solution won't work on our big input, you have to find
an optimized solution which will run in O(N) time (where N is the number of nodes).
- The values of each node does not matter.
- The bigger test we will do is about 250 000 nodes. It should run in less
than 2 seconds.

Example 1:

        1
      /   \
    2      \
   / \       \
 3    4       5
     /       /  \
    6       7    8

In this case, your function should return 6, 

because the longest path between two leaves is 6->4->2->1->5->7 (or finish by 8),
which contains 6 nodes, so the tree have a 'width' of 6.

Example 2:

         1
       /  \
     2     \
    / \     3
  4    \
 / \    \
5   6    7   
 \      / \
  8    9   10
      / \    \
     11   12  13

In this case, your function should return 7,

because the longest path between two leaves is 8->5->4->2->7->9->11 .

Example 3:

10
  \
   12

In this case, your function should return 2.

Example 4:

        25
      /   
    33     
   / \     
 12   9       
     /     
    3  
In this case, your function should return 4.

Example 5:

  10
(here is a root with no children)
In this case, your function should return 1.
*/