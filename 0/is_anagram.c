int is_anagram(char* a, char*b) {

	int tab[126] = {0};

	while (*a)
		tab[(int)*a++]++;
	while (*b)
		tab[(int)*b++]--;
	for (int i = 0; i < 126; i++)
		if (tab[i] != 0)
			return 0;
	return 1;
}

/************
  Test Main
************/

#include <stdio.h>
int main() {
	char* a = "abcdef";
	char* b = "fabcde";

	printf("%d\n", is_anagram(a, b));

	char* c = ".123?.";
	char* d = "?321..";

	printf("%d\n", is_anagram(c, d));

	char* e = "abca";
	char* f = "bcab";

	printf("%d\n", is_anagram(e, f));

	char* g = "aaaaaaaaaa";
	char* h = "aaaaaaaaaa";

	printf("%d\n", is_anagram(g, h));

	return 0;
}

/*
IS_ANAGRAM
Assignment name  : is_anagram
Expected files   : is_anagram.c
Allowed functions: 
--------------------------------------------------------------------------------
ALERT: OPTIMIZED SOLUTION REQUIRED.
An anagram is a sequence of characters formed by rearranging the letters of
another sequence, such as 'cinema', formed from 'iceman'.
Given two strings as parameters, create a function able to tell whether or
not the first string is an anagram of the second.
The function must be declared as follows:
int is_anagram(char *a, char *b);
Considerations:
- Be careful: the naive solution won't work on our big input, you have to
find an optimized solution which will run in O(sa + sb) time (where sa is
the length of a and sb length of b).
- Our tested string will always be a sequence of ascii characters between 32
and 126 inclusive.
- The bigger test we will do is on 2 sequences of 1.000.000 characteres each.
It should run in less than 2 seconds.
Example 1:
a='abcdef'
b='fabcde'
In this case, these two strings are anagrams, your function should return 1.
Example 2: 
a='.123?.'
b='?321..'
In this case, these two strings are anagrams, your function should return 1.
Example 3:
a='abca'
b='bcab'
In this case, these two strings are not anagrams, your function should return 0.
*/