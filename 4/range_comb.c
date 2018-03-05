#include <stdlib.h>
#include <string.h>

int findPerms(int n) {
	int ret = 1;
	for (int i = 1; i <= n; i++)
		ret *= i;
	return ret;
}

void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void sortRightSide(int* t, int size) {

	for (int i = 0; i < size - 1; i++) {
		if (t[i] > t[i + 1]) {
			int tmp = t[i];
			t[i] = t[i + 1];
			t[i + 1] = tmp;
			i = -1;
		}
	}
}

int findCeil(int* t, int first, int l, int n) {
	int ceilIndex = l;

	for (int i = l + 1; i < n; i++)
		if (t[i] > first && t[i] < t[ceilIndex])
			ceilIndex = i;
	return ceilIndex;
}

void permute(int** ret, int* t, int* idx, int n) {

	while (1) {

		memcpy(ret[*idx], t, sizeof(int) * n);
		*idx += 1;

		int i;
		for (i = n - 2; i >= 0; i--)
			if (t[i] < t[i + 1])
				break;
		if (i == -1) 
			break;
		else {
			int ceilIndex = findCeil(t, t[i], i + 1, n);
			swap(t + i, t + ceilIndex);
			sortRightSide(t + i + 1, n - i - 1);
		}
	}
}

int    **range_comb(int n) {

	int perms = findPerms(n);

	int** ret = malloc(sizeof(int*) * perms);
	for (int i = 0; i < perms; i++)
		ret[i] = malloc(sizeof(int) * n);

	int* template = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		template[i] = i;

	int idx = 0;
	permute(ret, template, &idx, n);
	return ret;
}

/************
  Test Main
************/

#include <stdio.h>
int main(int ac, char* av[]) {
	if (ac != 2)
		return 0;
	int n = atoi(av[1]);
	int** ret = range_comb(n);
	printf("perms: %d\n", findPerms(n));
	for (int i = 0; i < findPerms(n); i++) {
		printf("{ ");
		for (int j = 0; j < n; j++)
			printf("%d ", ret[i][j]);
		puts("}");
	}
	return 0;
}

/*
RANGE_COMB
Assignment name  : range_comb
Expected files   : range_comb.c
Allowed functions: malloc free memcpy
--------------------------------------------------------------------------------
Implement a function which computes, for a given integer n, all
the possible permutations of the numbers in the range from 0 to
(n - 1) inclusive.
The function returns a null-terminated array.
Your function must be declared as follows:
int    **range_comb(int n);
If n <= 0, the function returns -1;
Examples:
input  = 2
output = {{0, 1}, {1, 0}}
input  = 3
output = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}}
*/