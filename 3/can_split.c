typedef struct s_node 
{
    int value;
    struct s_node *left;
    struct s_node *right;
} Node;

int count(Node* n) {

    if (!n)
        return 0;
    return count(n->left) + count(n->right) + 1;
}

int checkIt(Node* n, int* canSplit, int totalNodes) {

    if (!n)
        return 0;

    int c = checkIt(n->left, canSplit, totalNodes) + checkIt(n->right, canSplit, totalNodes) + 1;
    if (totalNodes - c == c)
        *canSplit = 1;
    return c;
}

int can_split(struct s_node *n) {

    int totalNodes = count(n);
    if (totalNodes % 2)
        return 0;

    int canSplit = 0;
    checkIt(n, &canSplit, totalNodes);
    return canSplit;
}

/************
  Test Main
************/

#include <stdlib.h>
#include <stdio.h>
Node* b(int v) {
    Node* new = malloc(sizeof(Node));
    new->value = v;
    new->left = new->right = 0;
    return new;
}
int main() {
    Node* ex1 = b(28);
    ex1->left = b(51);
    ex1->left->left = b(26);
    ex1->left->left->left = b(76);
    ex1->left->left->right = b(13);
    ex1->left->right = b(48);

    printf("%d\n", can_split(ex1));

    Node* ex2 = b(30);
    ex2->left = b(15);
    ex2->left->left = b(61);
    ex2->right = b(41);
    ex2->right->right = b(80);

    printf("%d\n", can_split(ex2));

    
    Node* ex3 = b(10);
    ex3->left = b(12);

    printf("%d\n", can_split(ex3));

    Node* ex4 = b(5);
    ex4->left = b(1);
    ex4->right = b(6);
    ex4->right->left = b(7);
    ex4->right->left->left = b(3);
    ex4->right->left->left = b(2);
    ex4->right->right = b(4);
    ex4->right->right->right = b(8);

    printf("%d\n", can_split(ex4));

    return 0;
}
/*
CAN_SPLIT
Assignment name  : can_split
Expected files   : can_split.c
Allowed functions: 
--------------------------------------------------------------------------------
ALERT: OPTIMIZED SOLUTION REQUIRED.
Given the root node of a binary tree, create a function that returns 1 if, by
removing one edge of the tree, it can be splitted in two trees with the same
number of nodes (same 'size'). 
The binary tree uses the following node structure :
struct s_node 
{
    int value;
    struct s_node *left;
    struct s_node *right;
};
The function must be declared as follows:
int can_split(struct s_node *n);
Consideration:
- Be careful: the naive solution won't work on our big input, you have to find
an optimized solution which will run in O(N) time (where N is the number of nodes).
- The bigger test we will do is about 250 000 nodes. It should run in less
than 2 seconds.
Example 1:
       28
       /
      51
     / \
    /   \
   26   48
  / \
 /   \
76   13
In this case, it should return 1 (remove the edge between 51 and 26 will split the tree
in 2 trees with each a size of 3).
Example 2: 
    30
    / \
   /   \
  15   41
 /     /
61    80
In this case, it should return 0 (you can't split the tree and make 2 trees with the
same size).
Example 3:
10
  \
   12
In this case, your function return 1.
Example 4:
   5
  / \
 /   \
1     6    
    /  \
   7    4
 /  \    \
3    2    8
In this case, your function should return 0.
*/