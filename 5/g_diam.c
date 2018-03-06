#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#define LIM 20

typedef struct Node {
	int v;
	struct Node* next;
} Node;

typedef struct Stack {
	Node* top;
} Stack;

int pop(Stack* stack) {
	if stack->top == 0 {
		return -1;
	}
	Node* retNode = stack->top;
	stack->top = stack->top->next;
	int ret = retNode->v;
	free(retNode);
	return ret;
}

void push(Stack* stack, int v) {
	Node* new = malloc(sizeof(Node));
	new->v = v;
	new->next = stack->top;
	stack->top = new;
}

int isEmpty(Stack* stack) {
	if (stack->top)
		return 0;
	return 1;
}

int isNum(char c) {
	return ('0' <= c && c <= '9');
}

int cheapAtoi(char** s) {
	int ret = 0;
	while (isNum(**s)) {
		ret *= 10;
		ret += **s - '0';
		(*s)++;
	}
	if (**s != 0)
		(*s)++;
	return ret;
}

char* cheapItoa(int n, int* len) {
	int tmp = n;
	while (tmp > 0) {
		tmp /= 10;
		*len++;
	}
	char* ret = malloc(len + 2);
	ret[len - 1] = '\n';
	ret[len] = 0;
	for (int i = len - 1; i >= 0; i--) {
		ret[i] = (n % 10) + '0';
		n /= 10;
	}
	return ret;
}

int longestPath(char[LIM][LIM] matrix) {

	int visited[LIM] = {0};
	int longest = 0;
	Stack* s;

	for (int i = 0; i < LIM; i++) {

		int len = 0;

		// Does this value exist
		for (int j = 0; j < LIM; j++) {
			if (matrix[i][j]) {
				push(s, i);
				break;
			}
		}
		while (!isEmpty(s)) {
			Node* node = pop(s);
			visited[node->v] = 1;
			for (int j = 0; j < LIM; j++) {
				if (matrix[i][j]) {
					push(s, i);
				}
			}
		}



	}

}

int main(int ac, char* av[]) {
	if (ac != 2) { write(1, "\n", 1); return 0; }

	char matrix[LIM][LIM] = {0};

	char* s = av[1];
	while (*s) {
		int src = cheapAtoi(&s);
		int dest = cheapAtoi(&s);
		matrix[src][dest] = 1;
		matrix[dest][src] = 1;
	}

	int len = 0;
	char* ret = longestPath(matrix, &len);

	write(1, ret, len);
	write(1, "\n", 1);

	/*
    ** Print matrix
	for (int i = 0; i < LIM; i++) {
		for (int j = 0; j < LIM; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	**
	*/

	return 0;
}

/*
G_DIAM
Assignment name  : g_diam
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a programe that takes a string. This string represents a graph and is
composed of series of links between this graph's nodes. Links are separated by
a single space. Nodes are represented by numbers, and links by two nodes
separated by a '-'. For exemple, if there is a link between nodes 2
and 3, it could be written as "2-3" or "3-2".

The program will display the number of nodes comprised in the longest chain,
followed by a '\n', given it's impossible to pass through a node more than once.

If the number of parameters is different from 1, the program displays a '\n'.

Examples:

$>./g_diam "17-5 5-8 8-2 2-8 2-8 17-21 21-2 5-2 2-6 6-14 6-12 12-19 19-14 14-42" | cat -e
10$
$>./g_diam "1-2 2-3 4-5 5-6 6-7 7-8 9-13 13-10 10-2 10-11 11-12 12-8 16-4 16-11 21-8 21-12 18-10 18-13 21-18" | cat -e
15$
*/