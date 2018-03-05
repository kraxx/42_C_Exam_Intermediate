typedef struct s_node {
	int value;
	struct s_node *next;
} Node;

int is_looping(Node* node) {
	
	Node* n1 = node;
	Node* n2 = node;

	while (n1 && n2) {

		n1 = n1->next;
		n2 = n2->next;
		if (n2)
			n2 = n2->next;
		if (n1 && n2 && n1 == n2)
			return 1;
	}
	return 0;
}

/************
  Test Main
************/

#include <stdlib.h>
#include <stdio.h>
Node* b(int v) {
	Node* new = malloc(sizeof(Node));
	new->value = v;
	new->next = 0;
	return new;
}
int main() {

	Node* a = b(1);

	a->next = b(2);
	a->next->next = b(3);
	a->next->next->next = b(4);
	a->next->next->next->next = a;

	printf("%d\n", is_looping(a));

	Node* c = b(1);
	c->next = b(2);
	c->next->next = b(3);
	c->next->next->next = b(4);

	printf("%d\n", is_looping(c));
	
	return 0;
}

/*
IS_LOOPING
Assignment name  : is_looping
Expected files   : is_looping.c
Allowed functions: 
--------------------------------------------------------------------------------
ALERT: OPTIMIZED SOLUTION REQUIRED.
Given the first node of a linked list as parameter, create a function which
returns 1 if the linked list is looping, otherwise 0.
The linked list uses the following structure:
struct s_node {
    int value;
    struct s_node *next;
};
The function must be declared as follows:
int is_looping(struct s_node *node);
Considerations:
- Be careful: the naive solution won't work on our big input, you have to
find a solution with better complexity than O(N^2) time (where N is the
number of nodes).
- The values of each node does not matter.
- The bigger test we will do is on a linked list of 500.000 nodes, with the
beginning of the loop at the middle. It should run in less than 2 seconds.
Example 1:
1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |         v
          |         6
           \        |
            \______/
In this case, it should return 1 (at the node 3 begins the loop).
Example 2: 
12 -> 150 -> 30 -> 50 -> 345 -> 120
       ^                         |
       |                         v
       |                        200
        \                      /
         \____________________/
In this case, it should return 1 (the loop begins at node 150).
Example 3:
12 -> 150 -> 30 -> 50 -> 345 -> 120
In this case, it should return 0 (no loop begins).
Example 4:
12 -> 19 -> 14
            ^ \
            | |
            \/
In this case, it should return 1 (the loop begins at node 14).
*/