typedef struct s_node {
  int value;
  struct s_node **nodes;
} Node;

int height_tree(struct s_node *root) {

    if (!root)
        return 0;

    int max = 0;
    while (*root->nodes) {
        int tmp = 1 + height_tree(*root->nodes);
        if (max < tmp)
            max = tmp;
        root->nodes++;
    }
    return max;
}

/************
  Test Main
************/

#include <stdlib.h>
#include <stdio.h>
Node* b(int v) {
    Node* new = malloc(sizeof(Node));
    new->value = v;
    new->nodes = malloc(100000);
    return new;
}
int main() {

    Node* r = b(94);
    r->nodes[0] = b(34);
    r->nodes[1] = b(52);

    r->nodes[0]->nodes[0] = b(1);
    r->nodes[0]->nodes[1] = b(99);
    r->nodes[0]->nodes[2] = b(11);

    r->nodes[0]->nodes[1]->nodes[0] = b(13);

    printf("%d\n", height_tree(r));

    return 0;
}

/*
HEIGHT_TREE
Assignment name  : height_tree
Expected files   : height_tree.c
Allowed functions: 
--------------------------------------------------------------------------------
Implement a function to calculate the height of an n-ary tree.
Your should use the following node structure in your code for the n-ary tree:
    struct s_node {
        int           value;
        struct s_node **nodes;
    };
In this struct nodes is a null-terminated array.
Note that the height of a tree is the number of EDGES on the longest path from
the root node to a leaf. A tree with a single node will have a height of 0.
An empty tree should have height -1;
The function must be declared as follows:
    int height_tree(struct s_node *root);
EXAMPLE:
The Input Tree :
       94
           / \
          /   \
         34   52
        / \ \
       /   \     \
      1    99    11
         /
        /
           13
Output : 3
*/