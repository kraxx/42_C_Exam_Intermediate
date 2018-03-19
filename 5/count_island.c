#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define LIM 100000

int errorCheck(char buf[LIM], int size, int width, int height) {

	if (size / height != width) {
		write(1, "\n", 1);
		return 0;
	}

	for (int i = 0; i < size; i++) {
		if (buf[i] != '.' && buf[i] != 'X' && buf[i] != '\n')
			return 0;
	}
	
	return 1;
}

void floodFill(char buf[LIM], int size, int width, int height, int i, char replacer) {

	buf[i] = replacer;

	if ((i > width) && (buf[i - width] == 'X'))
		floodFill(buf, size, width, height, i - width, replacer);

	if ((i < size - width - 1) && buf[i + width] == 'X')
		floodFill(buf, size, width, height, i + width, replacer);

	if (i && (i % width > 0) && buf[i - 1] == 'X')
		floodFill(buf, size, width, height, i - 1, replacer);

	if (i && (i % width < width - 1) && buf[i + 1] == 'X')
		floodFill(buf, size, width, height, i + 1, replacer);
}

void countIsland(char* file) {
	
	char buf[LIM] = {0};
	int fd = open(file, O_RDONLY);

	int size = read(fd, buf, LIM);
	if (size < 0) {
		write(1, "\n", 1);
		return;
	}

	int width = 1;
	for (int i = 0; buf[i] != '\n'; i++)
		width++;

	int height = size / width;

	if (!errorCheck(buf, size, width, height))
		return;

	char replacer = '0';
	for (int i = 0; i < size; i++) {
		if (buf[i] == 'X') {
			floodFill(buf, size, width, height, i, replacer);
			replacer++;
		}
	}
	write(1, buf, size);
}

int main(int ac, char* av[]) {
	if (ac == 2)
		countIsland(av[1]);
	return 0;
}

/*
COUNT_ISLAND
Assignment name  : count_island
Expected files   : *.c, *.h
Allowed functions: open, close, read, write, malloc, free
--------------------------------------------------------------------------------
Write a program that takes a file that contains lines of equal length. Those
lines contain characters that are either '.' or 'X'. All those lines put
together form rectangles of '.' containing "islands" of 'X'.
The maximum size of a line is 1024 characters, including the terminating
newline.
A column if formed of the set of characters in the file that are separated from
the start of their respective lines by the same number of characters.
Two characters are said to be touching if they are contiguous and on the same
line, or on contiguous lines and on the same column.
An "island" of 'X' means a set of 'X' touching each other.
The program must walk though the file and display it after replacing all the
'X' by a number corresponding to the position their island appears in the file,
starting at the beginning of the file.
There can be only one result.
If the file is empty, or there is an error (Incoherent input, for example), or
no parameters are passed, the program must display a newline.
The file contains at most 10 islands.
You will find examples in the subject directory.
Examples:
$>cat toto
.................XXXXXXXX..........................................
....................XXXXXXXXX.......XXXXXXXX.......................
.................XXXXXXXX..............XXX...XXXXX.................
.....................XXXXXX.....X...XXXXXXXXXXX....................
................................X..................................
......XXXXXXXXXXXXX.............X..................................
..................X.............XXXXXXXXX..........................
..................X.........XXXXXXXXXXXX...........................
..................X................................................
XX.............................................................XXXX
XX..................XXXXXXXXXXXXX.................................X
...................................................................
.................................................................X.
.....................XXXXX.......................................XX
$>
$>./count_island toto
.................00000000..........................................
....................000000000.......11111111.......................
.................00000000..............111...11111.................
.....................000000.....2...11111111111....................
................................2..................................
......3333333333333.............2..................................
..................3.............222222222..........................
..................3.........222222222222...........................
..................3................................................
44.............................................................5555
44..................6666666666666.................................5
...................................................................
.................................................................7.
.....................88888.......................................77
$>
$>cat qui_est_la
...................................................................
...X........X.....XXXXX......XXXXXXX...XXXXXXXXXX..XXXXXXXXXX......
...XX......XX....XX...XX....XX.....XX.....XXXX.....XXXXXXXXXX......
...XXXX..XXXX...XX.....XX...XX.....XX......XX......XX..............
...XX.XXXX.XX...XX.....XX...XX.....XX......XX......XX..............
...XX...X..XX...XX.....XX...XXXXXXXX.......XX......XXXXX...........
...XX......XX...XXXXXXXXX...XXXX...........XX......XXXXX...........
...XX......XX..XX.......XX..XX.XX..........XX......XX..............
...XX......XX..XX.......XX..XX...X.........XX......XX..............
...XX......XX..XX.......XX..XX....X......XXXXXX....XXXXXXXXXX......
...XX......XX.XX.........XX.XX.....XX..XXXXXXXXXX..XXXXXXXXXX..X...
...................................................................
$>
$>./count_island qui_est_la
...................................................................
...0........0.....11111......2222222...3333333333..4444444444......
...00......00....11...11....22.....22.....3333.....4444444444......
...0000..0000...11.....11...22.....22......33......44..............
...00.0000.00...11.....11...22.....22......33......44..............
...00...0..00...11.....11...22222222.......33......44444...........
...00......00...111111111...2222...........33......44444...........
...00......00..11.......11..22.22..........33......44..............
...00......00..11.......11..22...5.........33......44..............
...00......00..11.......11..22....6......333333....4444444444......
...00......00.11.........11.22.....77..3333333333..4444444444..8...
...................................................................
$>
$>cat -e rien
$>./count_island rien | cat -e
$
$>
*/