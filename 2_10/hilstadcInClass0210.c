/*
	* File: hilstadcInClass0210.c
	* Author: Cameron Hilstad
	* Assignment: In Class 02/10/2025
	* Date: 02/10/2025
	* References: lectures
*/
#include <stdio.h>
#define ROWS 4
#define COLS 4

// I tried for so long to get this to return but couldn't get the pointers to work
void addMatricies(int a[ROWS][COLS], int b[ROWS][COLS]) {
	// return array
	int result[ROWS][COLS];
	
	// loop variables
	int i, j;
	// iterate through each row
	for (i = 0; i < ROWS; i++) {
		// iterate through each column
		for(j = 0; j < COLS; j++) {
			// add values from the same place and store them in result
			result[i][j] = a[i][j] + b[i][j];
			printf("%d ",result[i][j]);
		}
		printf("\n");
	}
}

int main() {
	// delcare matrix values
	int matrixA[4][4] = {{5,8,4,9},{1,0,0,2},{8,0,9,8},{7,1,0,4}};
	int matrixB[4][4] = {{5,8,0,6},{5,0,7,8},{9,4,8,7},{5,1,9,9}};
	
	// add matricies
	addMatricies(matrixA, matrixB);
}