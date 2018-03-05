#include <stdio.h>

typedef     struct s_node {
    int           value;
    struct s_node *right;
    struct s_node *left;
} Node;

void doLeft(Node* root) {
    if (root->left) {
        printf(" %d", root->value);
        doLeft(root->left);
    }
}

void doBot(Node* root) {
    if (root->left)
        doBot(root->left);
    if (root->right)
        doBot(root->right);
    if (!root->left && !root->right)
        printf(" %d", root->value);        
}

void doRight(Node* root) {
    if (root->right) {
        doRight(root->right);
        printf(" %d", root->value);
    }
}

void perimeter(Node* root) {

    if (root)
        printf("%d", root->value);
    if (root->left) {
        doLeft(root->left);
        doBot(root->left);
    }
    if (root->right) {
        doBot(root->right);
        doRight(root->right);
    }
    printf("\n");
}

/************
  Test Main
************/
#include <stdlib.h>
Node* b(int v) {
    Node* new = malloc(sizeof(Node));
    new->value = v;
    new->left = new->right = 0;
    return new;
}
int main() {

    Node* r = b(92);
    
    r->left = b(85);
    r->left->left = b(79);
    r->left->right = b(10);
    r->left->right->left = b(39);
    r->left->right->left->left = b(35);
    r->left->right->left->left->left = b(96);

    r->right = b(26);
    r->right->right = b(64);
    r->right->right->left = b(40);
    r->right->right->left->left = b(88);
    r->right->right->left->left->left = b(12);
    r->right->right->left->left->left->left = b(58);

    r->right->right->left->left->right = b(55);
    r->right->right->left->left->right->left = b(58);
    r->right->right->left->left->right->right = b(41);

    r->right->right->left->right = b(10);
    r->right->right->left->right->left = b(52);
    r->right->right->left->right->left->left = b(22);
    r->right->right->left->right->left->right = b(35);

    r->right->right->left->right->right = b(87);
    r->right->right->left->right->right->right = b(31);


    r->right->right->right = b(78);
    r->right->right->right->left = b(2);
    r->right->right->right->left->left = b(33);
    r->right->right->right->left->left->right = b(55);

    r->right->right->right->left->right = b(11);
    r->right->right->right->left->right->left = b(99);

    r->right->right->right->right = b(85);
    r->right->right->right->right->right = b(51);

    perimeter(r);
    return 0;
}


/*
PERIMETER
Assignment name  : perimeter
Expected files   : perimeter.c
Allowed functions: printf
--------------------------------------------------------------------------------
Implement a function which prints the perimeter of a binary tree.
The perimeter is defined as follows :
- leftmost nodes from top to bottom
- leaf nodes from left to right
- rightmost nodes from bottom to top
The binary tree uses the following node structure :
    struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
    };
The function prints on the standard output the value of the nodes
seperated by a single space and with a new line at the end.
The function must be declared as follows:
    void perimeter(struct s_node *root);
EXAMPLE :
    For the following tree :
                     92
                     / \
                    /   \
                   85   26
                  /       \
                 79       64
                  \       / \
                  10     /   \
                  /     /     \
                 39    /       \
                /     /         \
               35    /           \
              /     /             \
             96    /               \
                  /                 \
                 40                 78
                / \                 / \
               /   \               /   \
              /     \             2    85
             /       \           / \     \
            /         \         /   \    51
           /           \       /     \
          /             \     33     11
         88             10     \     /
        / \             / \    55   99
       /   \           /   \
      12   55         52   87
     /     / \       / \     \
    58    /   \     /   \    31
         58   41   22   35
    the output would be :
    92 85 79 96 58 58 41 22 35 31 55 99 51 85 78 64 26
*/