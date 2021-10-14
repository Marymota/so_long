#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MATRIX_ROWS = 5;
const int MATRIX_COLS = 4;

void print_matrix(int mat[MATRIX_ROWS][MATRIX_COLS])
{
	for(int row = 0; row < MATRIX_ROWS; row++)
	{
		printf("%d:\t", row);
		for (int col = 0; col < MATRIX_ROWS; col++)
		{
			printf("%x ", mat[row][col]);
		}
		printf("\n");
	}
}

int main (int argc, char *argv[])
{
	int matrix[MATRIX_ROWS][MATRIX_COLS];
	for(int row = 0; row < MATRIX_ROWS; row++)
	{
		for (int col = 0; col < MATRIX_ROWS; col++)
		{
			matrix[row][col] = (row << 16) | col;
		}
	}
	printf("sizeof(matrix) = %lu\n", sizeof(matrix));
	print_matrix(matrix);
	return (0);
}