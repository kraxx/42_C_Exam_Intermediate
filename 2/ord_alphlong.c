#include <stdlib.h>
#include <unistd.h>

int isAlpha(char c) {
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

int arrLen(char **arr) {
	int ret = 0;
	while (*arr++)
		ret++;
	return ret;
}

char toSmall(char c) {
	if ('A' <= c && c <= 'Z')
		return c + 32;
	return c;
}

int stringLength(char *s) {
	int ret = 0;
	while (*s++)
		ret++;
	return ret;
}

char* stringDupe(char* src, int len) {

	char* dst = malloc(len + 1);
	for (int i = 0; i < len; i++)
		dst[i] = src[i];
	dst[len] = 0;
	return dst;
}

int stringComp(char* a, char* b) {

	while (*a && *b)
		if (toSmall(*a++) - toSmall(*b++) != 0)
			return toSmall(*(a - 1)) - toSmall(*(b - 1));
	return 0;
}

void sortArr(char** arr) {
	int len = arrLen(arr);
	for (int i = 0; i < len - 1; i++) {
		if (stringComp(arr[i], arr[i + 1]) > 0) {
			char* tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = 0;
		}
	}
}

int main(int ac, char* av[]) {
	if (ac != 2) {
		write(1, "\n", 1);
		return 0;
	}
	char *arr[1000][1000] = {{0}};
	char* s = av[1];
	while (*s) {
		int len = 0;
		while (isAlpha(*s)) {
			len++;
			s++;
		}
		if (len > 0) {
			for (int i = 0; i < 1000; i++) {
				if (arr[len][i] == 0) {
					arr[len][i] = stringDupe(s - len, len);
					break;
				}
			}
		}
		if (*s)
			s++;
	}
	for (int i = 0; i < 1000; i++) {
		if (*arr[i]) {
			sortArr(arr[i]);
			int first = 1;
			for (int j = 0; j < 1000; j++) {
				if (arr[i][j]) {
					if (first) {
						first = 0;
					} else {
						write(1, " ", 1);
					}
					write(1, arr[i][j], i);
				}
				else
					break;
			}
			write(1, "\n", 1);
		}
	}
	return 0;
}

/*
ORD_ALPHLONG
Assignment name  : ord_alphlong
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------
Write a program that takes a string as a parameter and prints its words sorted
in order of their length first and then in alphabetical order on each line:
when we say alphabetical order we ignore the case of letters.
For example aA and Aa are the same but the  original order must remain
(lower and upper case are the same in alphabetical order). If there are
duplicates, they must remain.
If number of parameters is different from 1, the program prints 
\n.
There will be only spaces, tabs and alphanumeric caracters in strings.
You'll print only one space between each word. Nothing before the first and 
after the last word of each line.
Examples:
$>./ord_alphlong
$
$>./ord_alphlong "De son baton il frappa la pierre et l eau jaillit" | cat -e
l$
De et il la$
eau son$
baton$
frappa pierre$
jaillit$
$>./ord_alphlong "A a b B cc ca cd" | cat -e
A a b B$
ca cc cd$
$>./ord_alphlong "Pour l Imperium de l humanite" | cat -e
l l$
de$
Pour$
humanite Imperium$
$>
*/