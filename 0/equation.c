#include <stdio.h>

void equation(int n) {
	for (int a = 0; a < 10; a++)
		for (int b = 0; b < 10; b++)
			for (int c = 0; c < 10; c++)
				if ((a * 10 + b) + (c * 10 + a) == n)
					printf("A = %d, B = %d, C = %d\n", a, b, c);
}

/************
  Test Main
************/

#include <stdlib.h>
int main(int ac, char* av[]) {
	if (ac == 2)
		equation(atoi(av[1]));
	return 0;
}


/*
EQUATION
Assignment name  : equation
Expected files   : equation.c
Allowed functions: printf
-------------------------------------------------------------------------------
The goal of this exercise is to find all possible answers to the following
equation :

	AB + CA = n

where A, B, and C are individual digits [0-9] and n is an integer.
Note that here AB is not the product of A and B. It is merely a two digit number
with A being the first digit (tens place) and B the second digit (ones place).

Implement a function that, given an integer n, prints on the standard
output all the possible values of A, B, C for which the equation is true.

Your function must be declared as follows:

void    equation(int n);

If a solution could not be found, nothing is printed.
Examples:
For the value n = 42, the output would be :
$> ./equation 42
A = 0, B = 2, C = 4
A = 1, B = 1, C = 3
A = 2, B = 0, C = 2
A = 3, B = 9, C = 0
$>
For the value n = 111, the output would be :
$> ./equation 111
A = 2, B = 9, C = 8
A = 3, B = 8, C = 7
A = 4, B = 7, C = 6
A = 5, B = 6, C = 5
A = 6, B = 5, C = 4
A = 7, B = 4, C = 3
A = 8, B = 3, C = 2
A = 9, B = 2, C = 1
$>
For the value n = 0, the output would be :
$> ./equation 0 | cat -e
A = 0, B = 0, C = 0$
$>
Note:
- The displayed output will always be sorted in ascending order beginning with A, then B and then C.
(as shown in the examples above)
*/