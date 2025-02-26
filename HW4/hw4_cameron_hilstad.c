/*
	* File: hw4_cameron_hilstad.c
	* Author: Cameron Hilstad
	* Assignment: Homework 4
	* Date: 02/02/2025
	* References: lectures, stackoverflow clear input buffer
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	// set up game variables
	int pathDistance, margin, autopilotStatus, elevation, eta, input, offset, c;
	// Main Loop (run until user quits)
	while (1) {
		// set random seed to current time
		srand(time(NULL));
		
		// initial variables
		pathDistance = rand() % (70 - 50 + 1) + 50;
		margin = 5;
		autopilotStatus = 0;
		elevation = 380000;
		eta = 10;
		
		// Game Loop (run until time is up)
		while (eta > 0) {
			offset = rand() % 25 + 1;
			// prompt user
			printf("Your current distance is %dnm. ETA %ds. (1: correct | 2: stay): ", pathDistance, eta);
			while (1) {
				// check for valid input
				if (scanf("%d",&input) == 1 && (input == 1 || input == 2)) {
					break;
				} else {
					printf("Invalid Input! Try again: ");
					// stops infinite loop by clearing the input buffer 
					// (I got an infinite loop in testing and searched why)
					while ((c = getchar()) != '\n' && c != EOF) {}
				}	
			}

			// add or subtract distance
			if (input == 1) {
				// if negative, add to correct, else subtract
				if (pathDistance < 0) {
					pathDistance += offset;
				} else {
					pathDistance -= offset;
				}
			} else {
				// if negative, subtract to deviate more, else add
				if (pathDistance < 0) {
					pathDistance -= offset;
				} else {
					pathDistance += offset;
				}
			}
			
			// wait 1 second and update eta
			sleep(1);
			eta--;
		}
		// print the final distance
		printf("Your final distance is: %dnm\n", pathDistance);
		
		// detect if the user won
		if (pathDistance > -5 && pathDistance < 5) {
			printf("Mission Success! (1: Play Again | 2: Quit): ");
		} else {
			printf("Mission Failed! (1: Play Again | 2: Quit): ");
		}
		// I could force a ternary here by making a win variable,
		// set it with this if, then print with a ternary
		// It would look like: 
		// (hasWon) ? printf("...") : printf("...");
		// but idk why I would add an extra line for that
		
		// take input
		while (1) {
			// check if valid
			if (scanf("%d",&input) == 1 && (input == 1 || input == 2)) {
				break;
			} else {
				printf("Invalid Input! Try again: ");
				// stops infinite loop
				while ((c = getchar()) != '\n' && c != EOF) {}
			}	
		}
		
		// subtract 1 so I can put a ternary here and break if the user chooses to quit
		// nevermind this can't even be a ternary
		input--;
		if (input) break;
	}
}