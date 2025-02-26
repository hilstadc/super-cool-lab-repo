#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

/* Function to safely get an integer from user input */
int getIntegerInput(const char *prompt) {
    char buffer[50];  // Input buffer
    char *endPtr;
    long value;

    while (1) {
        printf("%s", prompt);

        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Error reading input. Please try again.\n");
            continue;
        }

        // Convert input string to integer
        value = strtol(buffer, &endPtr, 10);

        // Validate conversion and ensure value is within integer range
        if (endPtr == buffer || (*endPtr != '\n' && *endPtr != '\0') || value < INT_MIN || value > INT_MAX) {
            printf("Invalid input. Please enter a valid integer.\n");
            continue;
        }

        return (int)value;
    }
}

/* Function to generate a secure random seed */
unsigned int getRandomSeed() {
    unsigned int seed = (unsigned int)time(NULL);

    // Additional entropy mixing (bitwise shifts & XOR)
    seed ^= (seed << 13);
    seed ^= (seed >> 17);
    seed ^= (seed << 5);

    return seed;
}

/* Function to generate a random number in a given range */
int getRandomInRange(int lower, int upper) {
    return lower + (rand() % (upper - lower + 1));
}

int main() {
    int lowerBound, iterations;

    /* Get user input with validation */
    lowerBound = getIntegerInput("Please enter a lower bound: ");

    do {
        iterations = getIntegerInput("Please enter a number of iterations (must be > 0): ");
    } while (iterations <= 0);

    /* Calculate upper bound */
    int upperBound = lowerBound + (iterations % 6);
    if (upperBound <= lowerBound) {
        upperBound = lowerBound + 1;  // Ensure a valid range
    }

    /* Improved random number seeding */
    srand(getRandomSeed());

    /* Generate and print random numbers */
    printf("\nRandom numbers between %d and %d:\n", lowerBound, upperBound);
    for (int i = 0; i < iterations; i++) {
        printf("%d\n", getRandomInRange(lowerBound, upperBound));
    }

    return 0;
}