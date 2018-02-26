/*
This method is incorrect and will fail edge cases where there are multiple answers AND the first string contains them in different order.
eg. strings { "abc", "ba" "aab" }
The result is "b", whereas the question asks for "a".
However, this method is simpler (does not require keeping track of stringlengths) and passes the current (2018-02-20) intermediate exam.
*/

#include <unistd.h>
#include <stdlib.h>

int stringLength(char *s) {
	int ret = 0;
	while (*s++)
		ret++;
	return ret;
}

int getMinIndex(int ac, char* av[]) {

	int minLen = ~0u >> 1;
	int minIdx = 1;
	for (int i = 1; i < ac; i++) {
		int tmp = stringLength(av[i]);
		if (minLen > tmp) {
			minLen = tmp;
			minIdx = i;
		}
	}
	return minIdx;
}

int unfit(char* a, char* b, int len) {

	for (int i = 0; i < len; i++) {
		if (a[i] != b[i]) {
			if (*(b + 1)) {
				b++;
				i = -1;
			} else {
				return 1;
			}
		}
	}
	return 0;
}

int findLargestMatchSize(char* key, int ac, char* av[]) {

	int len = stringLength(key);

	for (int i = 0; i < ac; i++) {
		if (unfit(key, av[i], len)) {
			if (len > 1) {
				len--;
				i = -1;
			} else {
				return -1;
			}
		}
	}
	return len;
}

int main(int ac, char* av[]) {

	if (ac <= 2) {
		if (ac == 2)
			write(1, av[1], stringLength(av[1]));
		write(1, "\n", 1); 
		return 0;
	}
	int minIdx = getMinIndex(ac, av);
	if (minIdx != 1) {
		char* tmp = av[minIdx];
		av[minIdx] = av[1];
		av[1] = tmp;
	}

	char* key = av[1]; // I hate using av[1] over and over
	int currIdx = 0;
	int maxLen = -1, maxIdx = -1;

	for (int i = 2; i < ac; i++) {
		int tmp = findLargestMatchSize(key + currIdx, ac - 2, av + 2);
		if (maxLen < tmp) {
			maxLen = tmp;
			maxIdx = currIdx;
		}
		currIdx++;
		i = 1;
		if (key[currIdx] == 0)
			break;
	}
	if (maxIdx > -1)
		write(1, key + maxIdx, maxLen);
	write(1, "\n", 1);
	return 0;
}

/*
STR_MAXLENOC
Assignment name  : str_maxlenoc
Expected files   : str_maxlenoc.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes one or more strings and displays, followed by a
newline, the longest string that appears in every parameter. If more that one
string qualifies, it will display the one that appears first in the first
parameter. Note that the empty string technically appears in any string.

If there are no parameters, the program displays \n.

Examples:

$>./str_maxlenoc ab bac abacabccabcb
a
$>./str_maxlenoc bonjour salut bonjour bonjour
u
$>./str_maxlenoc xoxAoxo xoxAox  oxAox oxo  A ooxAoxx oxooxo Axo | cat -e
$
$>./str_maxlenoc bosdsdfnjodur atehhellosd afkuonjosurafg headfgllosf fghellosag afdfbosnjourafg
os
$>./str_maxlenoc | cat -e
$
*/
