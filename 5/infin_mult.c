#include <stdlib.h>
#include <unistd.h>

int myStrLen(char* s) {
	int ret = 0;
	while (*s++)
		ret++;
	return ret;
}

int main(int ac, char* av[]) {
	
	if (ac != 3)
		return 0;

	char* s1 = av[1];
	char* s2 = av[2];
	int neg = 0;

	if (*s1 == '-' && *s2 == '-') {
		s1++;
		s2++;
	} else if (*s1 == '-' && *s2 != '-') {
		s1++;
		neg = 1;
	} else if (*s1 != '-' && *s2 == '-') {
		s2++;
		neg = 1;
	}

	int len1 = myStrLen(s1);
	int len2 = myStrLen(s2);

	int ret[len1 + len2];
	for (int i = 0; i < len1 + len2; i++)
		ret[i] = 0;

	int idx1 = 0, idx2 = 0;
	for (int i = len1 - 1; i >= 0; i--) {

		int carry = 0;
		int n1 = s1[i] - '0';

		idx2 = 0;
		for (int j = len2 - 1; j >= 0; j--) {

			int n2 = s2[j] - '0';
			int sum = (n1 * n2) + ret[idx1 + idx2] + carry;
			carry = sum / 10;
			ret[idx1 + idx2] = sum % 10;
			idx2++;
		}

		if (carry)
			ret[idx1 + idx2] += carry;

		idx1++;
	}
	int idx = len1 + len2 - 1;
	while (idx >= 0 && ret[idx] == 0)
		idx--;
	if (idx == -1) {
		write(1, "0\n", 2);
		return 0;
	}
	if (neg)
		write(1, "-", 1);
	while (idx >= 0) {
		char x = ret[idx] + '0';
		write(1, &x, 1);
		idx--;
	}
	write(1, "\n", 1);
	return 0;
}

/*
INFIN_MULT
Assignment name  : infin_mult
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------
Write a program that takes as a parameter two strings that represent two
numbers potentially infinit, and displays on stdout the result of the
multiplication of these two numbers, followed by a '\n'.
A negative number will always be prefixed by one and only one -. The only
characters that can be part of the strings are digits and the sign -.
Both parameters will always be well formated, and you will always have exactly
two parameters, no tricks.
Example:
$> ./infin_mult "879879087" "67548976597" | cat -e
59434931855952726939$
$> ./infin_mult "-876435" "987143265" | cat -e
-865166907460275$
$> ./infin_mult "-807965" "-34532" | cat -e
27900647380$
$> ./infin_mult "-807965" "0"
0
$>
*/