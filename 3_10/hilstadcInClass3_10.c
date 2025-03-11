/*
	* File: hilstadcInClass3_10.c
	* Author: Cameron Hilstad
	* Assignment: In Class 03/10/2025
	* Date: 03/10/2025
	* References: GeeksForGeeks C Program to count number of lines in a file, 
		StackOverflow How to split a string to 2 strings in C
*/

#include <stdio.h>
#include <string.h>

// create struct 
struct Flight {
		int flightNum;
		char airline[50];
	};

int getNumFlights() {
	FILE *fptr;
	int count = 0;
	char c;
	
	// Open file
	fptr = fopen("flight_data_recorder_data.txt", "r");
	
	// Check if file exists
	if (fptr == NULL)
    {
        printf("Could not open file");
        return 0;
    } else {
		// Extract characters from file and store in character c
		for (c = getc(fp); c != EOF; c = getc(fp))
			if (c == '\n') // Increment count if this character is newline
				count++;
		fclose(fptr);
		return count;
	}
}

int importFlights(struct Flight arr[], int size) {
	FILE *fptr;
	char[100] buffer;
	char *token;
	
	// Open file
	fptr = fopen("flight_data_recorder_data.txt", "r");
	
	// Check if file exists
	if (fptr == NULL)
    {
        printf("Could not open file");
        return 0;
	} else {
		// Read each flight and add to struct
		int i;
		for (i = 0; i < size, i++) {
			// Read line
			fgets(buffer, sizeof(buffer), fptr);
			
			// Remove Newline
			buffer[strcspn(buffer, "\n")] = 0;
			
			// Split into separate variables and store
			token = strok(buffer, ",")
			arr[i].flightNum = atoi(*token);
			token = strok(NULL, ",")
			strcpy(arr[i].airline,*token);
		}
	}
}

void arrangeFlights(struct Flight arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("Hi");
	}
}

void searchFlights(struct Flight arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("Hi");
	}
}

int main() {
	int numFlights = getNumFlights();
	
	if (numFlights == 0) {
		return 1;
	}
	
	// decleare struct array
	struct Flight flights[numFlights];
	
	// import flights from file
	if (!importFlights(flights, numFlights)) {
		return 0;
	}
	
	int i;
	for (i = 0; i < numFlights; i++) {
		fprintf("%s %s\n",flights[i].airline,flights[i].flightNum);
	}
	
	arrangeFlights(flights, numFlights);
	searchFlights(flights, numFlights);
	
	return 0;
}