#include <stdlib.h>

typedef struct s_node {
    void          *content;
    struct s_node *next;
} Node;

typedef struct s_stack {
    struct s_node *top;
} Stack;

Stack* init(void) {
	Stack* s = malloc(sizeof(Stack));
	s->top = 0;
	return s;
}

void* pop(struct s_stack *stack) {
	if (!stack->top)
		return 0;
	Node* tmp = stack->top;
	void* content = tmp->content;
	stack->top = tmp->next;
	free(tmp);
	return content;
}

void push(struct s_stack *stack, void *content) {
	Node* new = malloc(sizeof(Node));
	new->content = content;
	new->next = stack->top;
	stack->top = new;
}

void *peek(struct s_stack *stack) {
	if (!stack->top)
		return 0;
	return stack->top->content;
}

int isEmpty(struct s_stack *stack) {
	if (!stack->top)
		return 1;
	return 0;
}

/************
  Test Main
************/

#include <stdio.h>
int main() {

	Stack* s = init();

	printf("Empty? %d\n", isEmpty(s));
	puts("Pushing 'Hello'");
	push(s, "Hello");
	printf("Empty? %d\n", isEmpty(s));
	printf("Peeking: %s\n", peek(s));
	puts("Pushing 'World'");
	push(s, "World");
	printf("Empty? %d\n", isEmpty(s));
	printf("Peeking: %s\n", peek(s));
	puts("Pushing ':)'");
	push(s, ":)");
	printf("Empty? %d\n", isEmpty(s));
	printf("Peeking: %s\n", peek(s));

	printf("Popped: %s\n", pop(s));
	printf("Popped: %s\n", pop(s));
	printf("Popped: %s\n", pop(s));
	printf("Popped: %s\n", pop(s));
	printf("Empty? %d\n", isEmpty(s));

	return 0;
}

/*
STACK
Assignment name  : stack
Expected files   : stack.c
Allowed functions: malloc free
--------------------------------------------------------------------------------
Implement a stack data structure in C, using the following structures in your
code:
    struct s_node {
        void          *content;
        struct s_node *next;
    };
    struct s_stack {
        struct s_node *top;
    };
A stack uses LIFO (last-in fist-out) ordering :
the most recent item added to the stack is the first item to be removed.
Implement 5 functions for the following stack operations :
    - init() : Initialize the stack.
      The top pointer is set to NULL.
    - pop(stack) : Remove the top item from the stack and return it.
      If the stack is empty, the function returns NULL.
    - push(stack, item) : Add an item to the top of the stack.
    - peek(stack) : Return the top of the stack.
      If the stack is empty, the function returns NULL.
    - isEmpty(stack) : Return 1 if the stack is empty, 0 otherwise.
These functions must be declared as follows:
    struct s_stack *init(void);
    void *pop(struct s_stack *stack);
    void push(struct s_stack *stack, void *content);
    void *peek(struct s_stack *stack);
    int isEmpty(struct s_stack *stack);
*/