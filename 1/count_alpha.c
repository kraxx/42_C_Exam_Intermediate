#include <stdio.h>

int isSmall(char c) {
	return 'a' <= c && c <= 'z';
}

int isCapital(char c) {
	return 'A' <= c && c <= 'Z';
}

int main(int ac, char* av[]) {
	if (ac == 2) {

		int tab[26] = {0};
		char* s = av[1] - 1;
		int first = 1;

		while (*(++s)) {
			if (isCapital(*s)) {
				*s += 32;
			}
			if (isSmall(*s)) {
				tab[*s - 'a']++;
			}
		}
		s = av[1] - 1;
		while (*(++s)) {
			if (tab[*s - 'a'] > 0) {
				if (first) {
					first = 0;
					printf("%d%c", tab[*s - 'a'], *s);
				}
				else
					printf(", %d%c", tab[*s - 'a'], *s);
				tab[*s - 'a'] = 0;
			}
		}
	}
	printf("\n");
	return 0;
}

/*
COUNT_APLHA
Assignment name  : count_alpha
Expected files   : count_alpha.c
Allowed functions: write, printf
--------------------------------------------------------------------------------

Write a program called count_alpha that takes a string and displays the number
of occurences of its alphabetical characters. Other characters are not counted.
The order is the order of occurence in the string. The display must be ended by
a newline.

The format is in the examples.

If the number of arguments is not 1, display only a newline.

Examples :
$> ./count_alpha abbcc
1a, 2b, 2c
$> ./count_alpha "abbcc"
1a, 2b, 2c
$> ./count_alpha "abbcc" "dddeef" | cat -e
$
$> ./count_alpha "My Hyze 47y 7." | cat -e
1m, 3y, 1h, 1z, 1e$
$> ./count_alpha "" | cat -e
$
*/