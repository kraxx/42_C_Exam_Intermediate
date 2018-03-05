#include <unistd.h>
#include <stdlib.h>

#define SWAP(x, y) do { typeof(x) SWAP = x; x = y; y = SWAP; } while (0)

int myStrLen(char* s) {
	int ret = 0;
	while (*s++)
		ret++;
	return ret;
}

int biggest(char* s1, char* s2, int l1, int l2) {
	
	if (l1 > l2) {
		return 1;
	} else if (l1 < l2) {
		return 2;
	} else {
		while (*s1 == *s2) {
			if (*s1 == 0 && *s2 == 0)
				return -1;
			s1++;
			s2++;
		}
		if (*s1 > *s2)
			return 1;
		else
			return 2;
	}
}

void doSub(char* s1, char* s2) {

	int neg1 = 0, neg2 = 0;
	if (*s1 == '-') {
		s1++;
		neg1 = 1;
	} else {
		s2++;
		neg2 = 1;
	}
	while (*s1 == '0')
		s1++;
	while (*s2 == '0')
		s2++;

	int l1 = myStrLen(s1) - 1, l2 = myStrLen(s2) - 1;
	int big = biggest(s1, s2, l1 + 1, l2 + 1);

	int isNeg = 0;
	if (big == -1) {
		write(1, "0\n", 2);
		return;
	} else if (big == 1) {
		if (neg1)
			isNeg = 1;
	} else {
		SWAP(s1, s2);
		SWAP(l1, l2);
		if (neg2)
			isNeg = 1;
	}

	char ret[l1 + l2 + 2];
	for (int i = 0; i < l1 + l2 + 2; i++)
		ret[i] = 0;

	int idx = 0;
	while (l1 >= 0 && l2 >= 0) {
		if (s1[l1] < s2[l2]) {
			int inc = 1;
			while (s1[l1 - inc] == '0')
				inc++;
			s1[l1 - inc--] -= 1;
			while (inc > 0)
				s1[l1 - inc--] += 9;
			s1[l1] += 10;
		}
		int a = s1[l1], b = s2[l2];
		ret[idx++] = (a - b) + '0';
		l1--;
		l2--;
	}

	while (l1 >= 0)
		ret[idx++] = s1[l1--];

	while (ret[idx - 1] == '0' && idx > 1)
		ret[--idx] = 0;

	if (isNeg)
		ret[idx++] = '-';

	idx--;
	while (idx >= 0)
		write(1, &ret[idx--], 1);
	write(1, "\n", 1);
}

void doAdd(char* s1, char* s2, int neg) {

	if (*s1 == '-')
		s1++;
	if (*s2 == '-')
		s2++;

	int l1 = myStrLen(s1) - 1, l2 = myStrLen(s2) - 1;
	char ret[l1 + l2 + 2];
	for (int i = 0; i < l1 + l2 + 2; i++)
		ret[i] = 0;

	int idx = 0, carry = 0;
	while (l1 >= 0 && l2 >= 0) {
		int a = s1[l1] - '0', b = s2[l2] - '0';
		int sum = a + b + carry;
		carry = sum / 10;
		ret[idx++] = sum % 10 + '0';
		l1--;
		l2--;
	}

	if (l1 >= 0 || l2 >= 0) {
		char* s = l1 >= 0 ? s1 : s2;
		int l = l1 >= 0 ? l1 : l2;
		while (l >= 0) {
			int sum = s[l] - '0' + carry;
			carry = sum / 10;
			ret[idx++] = sum % 10 + '0';
			l--;
		}
	}

	if (carry)
		ret[idx++] = carry + '0';

	while (ret[idx - 1] == '0' && idx != 1)
		ret[--idx] = 0;

	if (neg)
		ret[idx++] = '-';

	idx--;
	while (idx >= 0)
		write(1, &ret[idx--], 1);
	write(1, "\n", 1);
}

int main(int ac, char* av[]) {

	if (ac != 3)
		return 0;

	int neg1 = 0, neg2 = 0, isNeg = 0, hasNeg = 0;
	if (*av[1] == '-') {
		neg1 = 1;
		hasNeg = 1;
	}
	if (*av[2] == '-') {
		neg2 = 1;
		hasNeg = 1;
	}
	if ((neg1 && !neg2) || (!neg1 && neg2))
		isNeg = 1;
	if (isNeg)
		doSub(av[1], av[2]);
	else
		doAdd(av[1], av[2], hasNeg);
	return 0;
}

/*
INFIN_ADD
Assignment name  : infin_add
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------
Write a program that takes as a parameter two strings that represent two
numbers potentially infinit, and displays on stdout the result of the addition
of these two numbers, followed by a '\n'.
A negative number will always be prefixed by one and only one -. The only
characters that can be part of the strings are digits and the sign -.
Both parameters will always be well formated, and you will always have
exactly two parameters, no tricks.
Example:
$> ./infin_add "879879087" "67548976597" | cat -e
68428855684$
$> ./infin_add "-876435" "987143265" | cat -e
986266830$
$> ./infin_add "-807965" "-34532"
-842497
$>
*/