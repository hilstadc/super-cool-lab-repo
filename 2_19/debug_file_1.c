/*
	* File: debug_file_1.c
	* Author: Cameron Hilstad
	* Assignment: In Class 02/19/2025
	* Date: 02/19/2025
	* References: lectures
*/

#include <stdio.h>

int main() {
    int a = 10;
    // b is never initialized
    int b; 
    // Initialize b
    b = 5;

    printf("The value of a is: %d\n", a);
    printf("The value of b is: %d\n", b);

    return 0;
}
