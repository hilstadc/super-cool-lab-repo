/*
	* File: calc.c
	* Author: Cameron Hilstad
	* Assignment: In Class 02/24/2025
	* Date: 02/24/2025
	* References: lectures, GeeksforGeeks Convert String to int in C
*/

#include <stdio.h>
#include <stdlib.h>

// Operation functions, most just print the computed value
void add(float a, float b) {
  printf("Result: %f \n", (a+b));
}

void subtract(float a, float b) {
  printf("Result: %f \n", (a-b));
}

void multiply(float a, float b) {
  printf("Result: %f \n", (a*b));
}

void divide(float a, float b) {  
  // Check to make sure b isn't 0
  if (b == 0) {
    printf("ERROR! Divide by zero\n");
  } else {
    printf("Result: %f\n", a/b);
  }
}

int main(int argc, char *argv[]) {
  // make sure 3 parameters are added (calling program counts as well, so 4 total)
  if (argc != 4) {
    printf("ERROR! 3 parameters required, %d entered\n", argc-1);
    return 1;
  }
  
  // cast numbers from string to float
  float a = atof(argv[1]);
  float b = atof(argv[3]);
  
  // cast operator string to char
  char op = argv[2][0];
  
  // print the detected input
  printf("Detected Input:\n");
  printf("%f %c %f\n",a,op,b);
  
  // perform operation entered
  if (op == '+') {
    add(a,b);
  } else if (op == '-') {
    subtract(a,b);
  } else if (op == 'x' || op == 'X') {
    multiply(a,b);
  } else if (op == '/') {
    divide(a,b);
  } else {
    // print error if operator is not valid
    printf("ERROR! Invalid Operator\n");
  }
  
  return 0;
}