#include <stdio.h>

int main() {
	// input variables
	int lowerBound;
	int iterations;
	
	// take user input
	printf("Please enter a lower bound: ");
	scanf("%d",&lowerBound);
	printf("Please enter a number of iterations: ");
	scanf("%d",&iterations);
	
	// calculate upper bound
	// this should be the modulo 6 of the iterations + the lower bound
	int upperBound = (iterations % 6) + lowerBound;
	
	// loop for the amount of iterations given
	int i;
	for (i = 0; i < iterations; i++) {
		// generate a random number within the range
		int randNum = rand() % (upperBound - lowerBound + 1) + lowerBound;
		printf("%d\n",randNum);
	}
}