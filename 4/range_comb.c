// Generates in the wrong order

#include <stdlib.h>
#include <string.h>

void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int findPerms(int n) {
	int ret = 1;
	for (int i = 1; i <= n; i++) {
		ret *= i;
	}
	return ret;
}

void permute(int** ret, int* t, int* idx, int n) {
	while (1) {

		memcpy(ret[*idx], t, sizeof(int) * n);
		*idx += 1;

		int i;
		for (i = n - 2; i >= 0; --i)
			if (t[i] < t[i + 1])
				break;
		if (i == -1) 
			break;
		else {
			int ceilIndex = findCeil(t, t[i], i + 1, n - 1);
			swap(t + i, t + ceilIndex);
		}

	}
}

int    **range_comb(int n) {
	int perms = findPerms(n);
	int** ret = malloc(sizeof(int*) * perms);
	for (int i = 0; i < perms; i++) {
		ret[i] = malloc(sizeof(int) * n);
	}
	int* template = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		template[i] = i;
	}
	int idx = 0;
	permute(ret, template, &idx, n);
	return ret;
}

// void permute(int* a, int l, int r, int n, int** ret, int* idx) {
// 	if (l == r) {
// 		memcpy(ret[*idx], a, sizeof(int) * n);
// 		*idx+= 1;
// 	} else {
// 		for (int i = l; i <= r; i++) {
// 			swap((a + l), (a + i));
// 			permute(a, l + 1, r, n, ret, idx);
// 			swap((a + l), (a + i));
// 		}
// 	}
// }

// int    **range_comb(int n) {
// 	int perms = findPerms(n);
// 	int** ret = malloc(sizeof(int*) * perms);
// 	for (int i = 0; i < perms; i++) {
// 		ret[i] = malloc(sizeof(int) * n);
// 	}
// 	int* template = malloc(sizeof(int) * n);
// 	for (int i = 0; i < n; i++) {
// 		template[i] = i;
// 	}
// 	int idx = 0;
// 	permute(template, 0, n - 1, n, ret, &idx);
// 	return ret;
// }

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