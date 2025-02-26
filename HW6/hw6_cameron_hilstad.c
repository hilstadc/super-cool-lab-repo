/*
	* File: hw6_cameron_hilstad.c
	* Author: Cameron Hilstad
	* Assignment: Homework 6
	* Date: 02/16/2025
	* References: lectures; GeeksforGeeks: Pass Array to Functions in C, How to Initialize Array to 0 in C?
*/
#include <stdio.h>
#define MAX 100

// recursive function to fill columns in a given row
void genRow(int pyramid[MAX][MAX], int row, int col) {
	// each row should have the same number of columns
	// stop if column is larger than current row
	if (col > row) return;
	// fill current row and column with the index of the column + 1 (should sart with 1, not 0)
	pyramid[row][col] = col + 1;
	// move to the next column in the row
	genRow(pyramid, row, col + 1);
}

// recursive function to fill each row up to n
// arrays get passed as pointers so no return needed, OG array is modified
void genPyramid(int pyramid[MAX][MAX], int n, int row) {
	// if row is greater than or equal to the number we need, stop
	if (row >= n) return;
	// otherwise fill in the columns in the row, starting with 0
	genRow(pyramid, row, 0);
	// now do it again but increment the row
	genPyramid(pyramid, n, row + 1);
}

// prints the pyramid in a readable format
void printPyramid(int pyramid[MAX][MAX], int n) {
	// loop variables
	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			// if value is 0, don't print
			if (pyramid[i][j] != 0) {
				// print value with a space after
				printf("%d ",pyramid[i][j]);
			}
		}
		// create a newline for the next column
		printf("\n");
	}
}

int main()
{
	// input variable for size of array
	int n;
	
	// initialize 2D matrix of max size with all 0s. Extra 0s will not be printed
	int pyramid[MAX][MAX] = {0};
	
	// take user input for size of pyramid
	printf("Enter a number between 1 and 100: ");
	// ensure that 1 value is grabbed and the value is between 1 and 100
	while (scanf("%d",&n) != 1 || n < 1 || n > 100) {
		printf("Invalid Input! Try again: ");
		// clear input buffer
		while (getchar() != '\n') {}
	}
	
	// generate the pyramid with the n value received
	genPyramid(pyramid, n, 0);
	
	// print the generated input
	printf("Matrix pattern:\n");
	printPyramid(pyramid, n);
	
	return 0;
}