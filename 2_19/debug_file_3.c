/*
	* File: debug_file_3.c
	* Author: Cameron Hilstad
	* Assignment: In Class 02/19/2025
	* Date: 02/19/2025
	* References: lectures
*/

#include <stdio.h>

void process_array(int arr[], int size) {
    int i;
    // This srand is never used, commented out
    // srand(time(0));
    // Loop goes an index past the size of the array since they are indexed at 0. Changed from <= to <
    for (i = 0; i < size; i++) {
        arr[i] = i * 2;
    }
}

int main() {
    int array[10];
    int size = 10;
    // No semicolon here, added
    int sum = 0;

    process_array(array, size);

    // i initilaized in loop, must be outside before C99
    int i;
    // Started at index 1 instead of 0 and ran to index size instead of size-1 (<= instead of <)
    for (i = 0; i < size; i++) {
        sum += array[i];
	printf("%d ",array[i]);
    }

    printf("Sum of array elements: %d\n", sum);

    return 0;
}
