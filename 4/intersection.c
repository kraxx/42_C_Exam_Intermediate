typedef struct s_node {
    void *content;
    struct s_node *next;
} Node;

void* intersection(Node* lst1, Node* lst2) {

	while (lst1) {
		Node* tmp = lst2;
		while (tmp) {
			if (lst1 == tmp)
				return lst1;
			tmp = tmp->next;
		}
		lst1 = lst1->next;
	}
	return 0;
}

/************
  Test Main
************/

#include <stdio.h>
#include <stdlib.h>
Node* b(void* v) {
	Node* new = malloc(sizeof(Node));
	new->content = v;
	new->next = 0;
	return new;
}
int main() {
	Node* a = b("a");
	a->next = b("b");
	a->next->next = b("c");
	a->next->next->next = b("d");
	a->next->next->next->next = b("e");
	a->next->next->next->next->next = b("f");

	Node* c = b("g");
	c->next = b("h");
	c->next->next = b("i");
	c->next->next->next = b("j");
	c->next->next->next->next = b("k");
	c->next->next->next->next->next = b("l");

	Node* ret = intersection(a, c);
	printf("%s\n", ret ? ret->content : 0);

	c->next->next = a->next->next->next;
	ret = intersection(a, c);
	printf("%s\n", ret ? ret->content : 0);

	return 0;
}

/*
INTERSECTION
Assignment name  : intersection
Expected files   : intersection.c
Allowed functions: 
--------------------------------------------------------------------------------
Given two singly linked lists, determine if the two lists intersect.
Return the intersecting node.
The intersection is defined based on reference, not value.
That is, if the kth node of the first linked list is the exact same node
(by reference) as the jth node of the second linked list, then they are
intersecting.
The linked lists will use the following structure :
    struct s_node {
        void *content;
        struct s_node *next;
    };
The function must be declared as follows:
    void *intersection(struct s_node *lst1, struct s_node *lst2);
If the two linked lists are not intersecting, the function returns NULL.
The function does not modify the two linked list.
*/