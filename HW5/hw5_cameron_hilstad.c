/*
	* File: hw5_cameron_hilstad.c
	* Author: Cameron Hilstad
	* Assignment: Homework 5
	* Date: 02/09/2025
	* References: lectures
*/
#include <stdio.h>

void getInput(int *a, int *b) {
	// takes two pointers from main and stores the inputted values into the locations given
	
	// buffer variable
	int c;
	
	// Prompt user for two integers
	printf("Please enter two integers seperated by a space: ");
	// Loop to read inputted values until they are valid
	while (1) {
		// check for valid input
		// input is sent to the pointers given, which passes the values into the variables from main
		if (scanf("%d %d",a,b) == 2) {
			// if valid, break from loop
			break;
		} else {
			printf("Invalid Input! Try again: ");
			// stops infinite loop by clearing the input buffer 
			while ((c = getchar()) != '\n' && c != EOF) {}
		}
	}
}

void printResult(int result, int a, int b) {
	// takes an inputted result value and displays it to the user
	// also prints the initial values to remind the user
	printf("For the numbers %d and %d:\n", a, b);
	printf("Your result is %d\n\n", result);
}

// I would probably overload this function if it was C++
// One would just have 'a' while the other has both 'a' and 'b'
void printTwosResult(int result, int a) {
	// takes an inputted result value and displays it to the user
	// this time its a single value because the twos complement is calculated per input
	printf("For the number %d:\n", a);
	printf("Your result is %d\n\n", result);
}

int xorFunc(int a, int b) {
	// takes two integers and XORs their binary values
	return (a^b);
}

int orFunc(int a, int b) {
	// takes two integers and ORs their binary values
	return (a|b);
}

int andFunc(int a, int b) {
	// takes two integers and ANDs their binary values
	return (a&b);
}

int twoCompFunc(int a) {
	// takes an integer and returns its 2's complement
	// This is the 1's complement plus 1
	return (~a + 1);
}

int main()
{
	// input variables
	int intOne, intTwo;
	
	// Greet user
	printf("Hello and Welcome!\n");
	
	// Ask for two integers
	getInput(&intOne, &intTwo);
	
	//Main Loop Variables
	int menuOption, repeatOption, c, d;
	int runLoop = 1;
	//Main loop 
	while (runLoop) {
		// I could probably also make the menus into their own functions but its late
		// and I have a heat transfer project and quiz tomorrow
		
		// Prompt user with menu
		printf("\nPlease enter the option you would like to choose:\n");
		printf("1: XOR\n");
		printf("2: OR\n");
		printf("3: AND\n");
		printf("4: 2's Complement\n");
		printf("> ");
		
		// Get menu option chosen
		while (1) {
			// check for valid input
			if (scanf("%d", &menuOption) == 1 && menuOption >= 1 && menuOption <= 4) {
				// if valid, break from loop
				break;
			} else {
				printf("Invalid Input! Try again: ");
				// stops infinite loop by clearing the input buffer 
				while ((c = getchar()) != '\n' && c != EOF) {}
			}
		}
		
		// Perform operation picked
		switch (menuOption) {
			case 1:
				// XOR
				printResult(xorFunc(intOne, intTwo), intOne, intTwo);
				break;
			case 2:
				// OR
				printResult(orFunc(intOne, intTwo), intOne, intTwo);
				break;
			case 3:
				// AND
				printResult(andFunc(intOne, intTwo), intOne, intTwo);
				break;
			case 4:
				// 2's compliment
				printTwosResult(twoCompFunc(intOne), intOne);
				printTwosResult(twoCompFunc(intTwo), intTwo);
				break;
			default:
				printf("You have somehow picked an invalid option AND it cleared my filter\n");
				break;
		}
		
		// Prompt user with repeat menu
		printf("Please enter the option you would like to choose:\n");
		printf("1: Perform another operation with the same numbers\n");
		printf("2: Choose different numbers\n");
		printf("3: Quit\n");
		printf("> ");
		
		// Get repeat option chosen
		while (1) {
			// check for valid input
			if (scanf("%d", &repeatOption) == 1 && repeatOption >= 1 && repeatOption <= 3) {
				// if valid, break from loop
				break;
			} else {
				printf("Invalid Input! Try again: ");
				// stops infinite loop by clearing the input buffer 
				while ((d = getchar()) != '\n' && d != EOF) {}
			}
		}
		
		// Perform operation picked
		switch (repeatOption) {
			case 1:
				// just loop again, nothing to do here
				break;
			case 2:
				// get new numbers and loop again
				getInput(&intOne, &intTwo);
				break;
			case 3:
				// stop main loop
				runLoop = 0;
				break;
			default:
				printf("You have somehow picked an invalid option AND it cleared my filter\n");
				break;
		}
	}
	
	return 0;
}