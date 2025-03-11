/*
	* File: hilstadcInClass3_10.c
	* Author: Cameron Hilstad
	* Assignment: In Class 03/10/2025
	* Date: 03/10/2025
	* References: GeeksForGeeks C Program to count number of lines in a file, 
		StackOverflow How to split a string to 2 strings in C
    GeeksForGeeks Selection Sort
    I also had chatGPT generate 10 more flight numbers / airlines
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
		for (c = getc(fptr); c != EOF; c = getc(fptr))
			if (c == '\n') // Increment count if this character is newline
				count++;
		fclose(fptr);
    printf("%d flights found\n",count);
		return count;
	}
}

int importFlights(struct Flight arr[], int size) {
	FILE *fptr;
	char buffer[100];
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
		for (i = 0; i < size; i++) {
			// Read line
			fgets(buffer, sizeof(buffer), fptr);
			
			// Remove Newline
			buffer[strcspn(buffer, "\n")] = 0;
			
			// Split into separate variables and store
			token = strtok(buffer, ",");
			arr[i].flightNum = atoi(token);
			token = strtok(NULL, ",");
			strcpy(arr[i].airline,token);
		}
    return 1;
	}
}

void arrangeFlights(struct Flight arr[], int size) {
	int i, j, minIndex, tempNum;
  char tempAirline[50];
 
	for (i = 0; i < size; i++) {
    minIndex = i;
    for (j = i + 1; j < size; j++) {
      if (arr[j].flightNum < arr[minIndex].flightNum) {
        minIndex = j;
      }
    }
    
    //Move mimimum element
    tempNum = arr[i].flightNum;
    strcpy(tempAirline,arr[i].airline);
    arr[i].flightNum = arr[minIndex].flightNum;
    strcpy(arr[i].airline,arr[minIndex].airline);
    arr[minIndex].flightNum = tempNum;
    strcpy(arr[minIndex].airline,tempAirline);
	}
}

void searchFlights(struct Flight arr[], int size) {
  // Prompt user for flight number
  int search, c;
  printf("Please enter a flight number to search for: ");
  while (1) {
    if (scanf("%d", &search) == 1 && search > 0) {
      break;
    } else {
      printf("Invalid Input! Try again: ");
      // clear buffer
      while ((c = getchar()) != '\n' && c != EOF) { }
    }
  }
  
  // Search through flights
  int foundFlight = 0;
	int i;
	for (i = 0; i < size; i++) {
    // If matching flight is found, print it
		if (arr[i].flightNum == search) {
      printf("Found %d, %s at index %d\n",arr[i].flightNum,arr[i].airline,i);
      foundFlight = 1;
    // If we have passed all matching numbers, break
  	} else if (arr[i].flightNum > search) {
      break;
    }
  }
  
  // If no flight was found, warn user
  if (!foundFlight) {
    printf("Flight not available.\n");
  }
}

int main() {
	int numFlights = getNumFlights();
	
	if (numFlights == 0) {
		return 1;
	}
	
	// declare struct array
	struct Flight flights[numFlights];
	
	// import flights from file
	if (!importFlights(flights, numFlights)) {
		return 0;
	}
	
	int i;
	for (i = 0; i < numFlights; i++) {
		printf("%s %d\n",flights[i].airline,flights[i].flightNum);
	}
	printf("\n");
 
	arrangeFlights(flights, numFlights);

  for (i = 0; i < numFlights; i++) {
		printf("%s %d\n",flights[i].airline,flights[i].flightNum);
	}
 
	searchFlights(flights, numFlights);
	
	return 0;
}