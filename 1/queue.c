#include <stdlib.h>

typedef struct s_node {
    void          *content;
    struct s_node *next;
} Node;

typedef struct s_queue {
    struct s_node *first;
    struct s_node *last;
} Queue;

Queue* init(void) {
	Queue* q = malloc(sizeof(Queue));
	q->first = 0;
	q->last = 0;
	return q;
}

void enqueue(struct s_queue *queue, void *content) {
	Node* new = malloc(sizeof(Node));
	new->content = content;
	new->next = 0;
	if (!queue->first)
		queue->first = new;
	if (queue->last)
		queue->last->next = new;
	queue->last = new;
}

void* dequeue(struct s_queue *queue) {
	if (!queue->first)
		return 0;
	Node* tmp = queue->first;
	void* content = tmp->content;
	queue->first = tmp->next;
	if (!queue->first)
		queue->last = 0;
	free(tmp);
	return content;
}

void* peek(struct s_queue *queue) {
	if (!queue->first)
		return 0;
	return queue->first->content;
}

int isEmpty(struct s_queue *queue) {
	if (!queue->first)
		return 1;
	return 0;
}

/************
  Test Main
************/

#include <stdio.h>
int main() {

	Queue* q = init();

	printf("Empty? %d\n", isEmpty(q));
	printf("Enqueueing 'Hello'\n");
	enqueue(q, "Hello");
	printf("Empty? %d\n", isEmpty(q));
	printf("Peeking: %s\n", peek(q));
	printf("Enqueueing 'World'\n");
	enqueue(q, "World");
	printf("Empty? %d\n", isEmpty(q));
	printf("Peeking: %s\n", peek(q));
	printf("Enqueueing ':)'\n");
	enqueue(q, ":)");
	printf("Empty? %d\n", isEmpty(q));
	printf("Peeking: %s\n", peek(q));
	printf("Dequeue: %s\n", dequeue(q));
	printf("Dequeue: %s\n", dequeue(q));
	printf("Dequeue: %s\n", dequeue(q));
	printf("Dequeue: %s\n", dequeue(q));
	printf("Empty? %d\n", isEmpty(q));

	return 0;	
}


/*
QUEUE
Assignment name  : queue
Expected files   : queue.c
Allowed functions: malloc free
--------------------------------------------------------------------------------
Implement a queue data structure in C, using the following structures in your 
code:
    struct s_node {
        void *content;
        struct s_node *next;
    };
    struct s_queue {
        struct s_node *first;
        struct s_node *last;
    };
A queue uses FIFO (first-in fist-out) ordering :
items are removed from the data structure in the same order that they are added.
Implement 5 functions for the following queue operations :
    - init() : Initialize the queue.
      The first and last pointers are set to NULL.
    - enqueue(queue, item) : Add an item to the end of the queue.
    - dequeue(queue) : Remove the first item from the queue and return it.
      If the queue is empty, the function returns NULL.
    - peek(queue) : Return the first item of the queue.
      If the queue is empty, the function returns NULL.
    - isEmpty(queue) : Return 1 if the queue is empty, 0 otherwise.
These functions must be declared as follows:
    struct s_queue *init(void);
    void enqueue(struct s_queue *queue, void *content);
    void *dequeue(struct s_queue *queue);
    void *peek(struct s_queue *queue);
    int isEmpty(struct s_queue *queue);
*/
