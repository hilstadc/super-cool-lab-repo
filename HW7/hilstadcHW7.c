/*
	* File: hilstadcHW7.c
	* Author: Cameron Hilstad
	* Assignment: Homework 7
	* Date: 03/02/2025
	* References: lectures, In class assignment
*/

// I pretty much just changed the in class back from float to int, changed to pointers, and added scanf inputs

#include <stdio.h>
#include <stdlib.h>

// Operation functions, each take 2 pointers and sets the value at the first to the result of the operation
void add(int *a, int *b) {
  *a = *a + *b;
}

void subtract(int *a, int *b) {
  *a = *a - *b;
}

void multiply(int *a, int *b) {
  *a = *a * *b;
}

void divide(int *a, int *b) {  
  // Check to make sure b isn't 0
  if (*b == 0) {
    printf("ERROR! Divide by zero\n");
    // I want to set a to 0 so it doesn't just print the result as whatever a was
    // I don't think I can stop main from inside this function, there probably is a way I havent learned yet
    *a = 0;
  } else {
    *a = *a / *b;
  }
}

int main(int argc, char *argv[]) {
  // make sure 0 or 3 parameters are added (calling program counts as one, so 1 or 4 total)
  if (argc != 4 && argc != 1) {
    printf("ERROR! 3 parameters required, %d entered\n", argc-1);
    return 1;
  }
  
  /*
  used to debug arguements
  int i;
  for (i = 0; i < argc; i++) {
    printf("Arg %d is %s\n", i+1, argv[i]);
  }
  */
  
  // Storage variables
  int a, b;
  char op;
  
  // If no arguements given, prompt user, otherwise convert and store
  if (argc == 1) {
    // Prompt user for input
    
    // Get two numbers
    printf("Please enter 2 integers: ");
    while (scanf("%d %d", &a, &b) != 2) {
      printf("Invalid Input! Try again: ");
			// clear buffer
			while (getchar() != '\n');
    }
    
    //clear buffer
    while (getchar() != '\n');
    
    // Get operator
    printf("Please choose an operation (+, -, x, /): ");
    while (1) {
      if (scanf("%c", &op) == 1 && (op == '+' || op == '-' || op == 'x' || op == 'X' || op == '/')) {
        break;
      } else {
        printf("Invalid Input! Try again: ");
  			// clear buffer
  			while (getchar() != '\n');
      }
    }
  } else {
    // Terminal Input
  
    // cast numbers from string to int
    a = atoi(argv[1]);
    b = atoi(argv[3]);
    
    // cast operator string to char
    op = argv[2][0];
  }
  
  // print the detected input
  printf("Detected Input:\n");
  printf("%d %c %d\n",a,op,b);
  
  // perform operation entered
  if (op == '+') {
    add(&a,&b);
  } else if (op == '-') {
    subtract(&a,&b);
  } else if (op == 'x' || op == 'X') {
    multiply(&a,&b);
  } else if (op == '/') {
    divide(&a,&b);
  } else {
    // print error if operator is not valid, this should be caught earlier but here just in case
    printf("ERROR! Invalid Operator\n");
    return 1;
  }
  
  // Print result
  printf("Result: %d\n", a);
  
  return 0;
}