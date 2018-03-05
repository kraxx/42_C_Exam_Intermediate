typedef struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
} Node;

Node* recurse(Node* root) {

	if (!root)
		return 0;

	if (root->left) {

		Node* left = recurse(root->left);
		while (left->right)
			left = left->right;
		left->right = root;
		root->left = left;

	}
	if (root->right) {

		Node* right = recurse(root->right);
		while (right->left)
			right = right->left;
		right->left = root;
		root->right = right;
	}
	return root;
}

Node* convert_bst(Node* bst) {
	if (!bst)
		return 0;
	recurse(bst);
	Node* left = bst;
	Node* right = bst;
	while (left->left)
		left = left->left;
	while (right->right)
		right = right->right;
	left->left = right;
	right->right = left;
	return left;
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
	Node* r = b(8);
	r->left = b(4);
	r->left->left = b(2);
	r->left->left->left = b(1);
	r->left->left->right = b(3);

	r->left->right = b(6);
	r->left->right->left = b(5);
	r->left->right->right = b(7);

	r->right = b(12);
	r->right->left = b(10);
	r->right->left->left = b(9);
	r->right->left->right = b(11);
	
	r->right->right = b(14);
	r->right->right->left = b(13);
	r->right->right->right = b(15);

	r = convert_bst(r);
	for (int i = 0; i < 15; i++) {
		printf("%d\n", r->value);
		r = r->right;
	}
	for (int i = 0; i < 17; i++) {
		printf("%d\n", r->value);
		r = r->left;
	}
}

/*
CONVERT_BST
Assignment name  : convert_bst
Expected files   : convert_bst.c
Allowed functions: 
--------------------------------------------------------------------------------
A binary search tree (BST) is a binary tree in which every node fits
a specific ordering property :
all left descendants <= n < all right descendants
This must be true for each node n.
Implement a function to convert a binary search tree to a sorted, circular,
doubly-linked list.
This conversion must be in-place (using the tree nodes as the new list nodes).
The binary search tree uses the following node structure :
    struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
    };
The function must be declared as follows:
    struct s_node *convert_bst(struct s_node *bst);
The function must return a pointer to the smallest element of the sorted,
circular, doubly-linked list.
For each node of the linked list, the right pointer points to the next node
and the left pointer points to the previous node.
The sort is in increasing order.
*/