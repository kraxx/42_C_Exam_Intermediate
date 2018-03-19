#include <stdlib.h>
#include <unistd.h>

#define LIM 100

int myStrLen(char* s) {
	int ret = 0;
	while (*s++)
		ret++;
	return ret;
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

char* cheapItoa(int n) {
	int tmp = n;
	int len = 0;
	while (tmp > 0) {
		tmp /= 10;
		len++;
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

void longestPath(char matrix[LIM][LIM], int path[LIM], int pos, int chain, int* longest) {

	path[pos] = 1;
	for (int i = 0; i < LIM; i++) {
		if (matrix[pos][i] && path[i] == 0) {
			if (*longest < chain + 1)
				*longest = chain + 1;
			longestPath(matrix, path, i, chain + 1, longest);
		}
	}
	path[pos] = 0;
}

int main(int ac, char* av[]) {

	if (ac != 2) { write(1, "\n", 1); return 0; }

	char matrix[LIM][LIM] = {{0}};

	char* s = av[1];
	while (*s) {
		int src = cheapAtoi(&s);
		int dest = cheapAtoi(&s);
		matrix[src][dest] = 1;
		matrix[dest][src] = 1;
	}

	int longest = 2;
	int path[LIM] = {0};
	for (int i = 0; i < LIM; i++) {
		longestPath(matrix, path, i, 1, &longest);
	}

	char* ret = cheapItoa(longest);
	write(1, ret, myStrLen(ret));
	write(1, "\n", 1);
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