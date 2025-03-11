/*
	* File: hilstadcHW8.c
	* Author: Cameron Hilstad
	* Assignment: Homework 8
	* Date: 03/09/2025
	* References: Past homework / in class assignments, int to string stackoverflow
*/

#include <stdio.h>
#include <string.h>

// create student struct 
struct Airframe {
		char model[50];
		char manufacturer[50];
		int year;
		int quantity;
	};

void addAirframe(struct Airframe arr[]) {
	int i, c;
	for (i = 0; i < 5; i++) {
	    // Iterates loop until model with NA is found to replace with data
		if (strcmp(arr[i].model,"NA") == 0) {
		    break;
		}
	}
	
	// check that i can exist
	if (i < 5) {
		// ask for all data and store
	    printf("Enter airframe %d's model: ",i+1);
		scanf("%49s", arr[i].model);
		while ((c = getchar()) != '\n' && c != EOF) { }
		
		printf("Enter airframe %d's manufacturer: ",i+1);
		scanf("%49s", arr[i].manufacturer);
		while ((c = getchar()) != '\n' && c != EOF) { }
		
		printf("Enter airframe %d's year: ",i+1);
		scanf("%d", &arr[i].year);
		while ((c = getchar()) != '\n' && c != EOF) { }
		
		printf("Enter airframe %d's quantity: ",i+1);
		scanf("%d", &arr[i].quantity);
		while ((c = getchar()) != '\n' && c != EOF) { }
		printf("\n");
	} else {
	    printf("Error: Airframe Inventory Full!\n\n");
	}
}

void printAirframes(struct Airframe arr[]) {
	int i;
	for (i = 0; i < 5; i++) {
	    // print all airframes that are not equal to NA
	    if (strcmp(arr[i].model,"NA")) {
    		printf("Airframe %d: \n",i+1);
    		printf("Model: %s \n",arr[i].model);
    		printf("Manufacturer: %s \n",arr[i].manufacturer);
    		printf("Year: %d \n",arr[i].year);
    		printf("Quantity: %d \n\n",arr[i].quantity);
	    }
	}
}

void shiftAirframes(struct Airframe arr[], int id) {
	// shift eveything to the right of the given id to the left by one
    int i;
    for (i = id; i < 4; i++) {
        strcpy(arr[i].model,arr[i+1].model);
        strcpy(arr[i].manufacturer,arr[i+1].manufacturer);
        arr[i].year = arr[i+1].year;
        arr[i].quantity = arr[i+1].quantity;
    }
	// set the last model to NA to stop it from being printed
    strcpy(arr[4].model,"NA");
}

void deleteAirframe(struct Airframe arr[]) {
    char identifier[50];
    int c;
    char yearStr[10];
    
    // Determine what will be deleted
    printf("Enter an identifier to delete: ");
	scanf("%49s", identifier);
	while ((c = getchar()) != '\n' && c != EOF) { }
    
	int i;
	int deleteCounter = 0;
	for (i = 0; i < 5; i++) {
	    // check all airframes that are not equal to NA
	    if (strcmp(arr[i].model,"NA")) {
	        // if match is found in any parameter, shift all airframes past this index left by one
	        if (strcmp(arr[i].model,identifier) == 0) {
	            printf ("Airframe %d deleted\n\n",i+1+deleteCounter);
	            shiftAirframes(arr,i);
	            // next i is now current i;
				// add deletecounter to displayed number to prevent confusion
	            i--;
	            deleteCounter++;
	        } else if (strcmp(arr[i].manufacturer,identifier) == 0) {
	            printf ("Airframe %d deleted\n\n",i+1+deleteCounter);
	            shiftAirframes(arr,i);
	            i--;
	            deleteCounter++;
	            //if a to i exists, i to a should right? ( NO :(... ))
	        } else {
	            sprintf(yearStr, "%d", arr[i].year);
	            if (strcmp(yearStr,identifier) == 0) {
	                printf ("Airframe %d deleted\n\n",i+1+deleteCounter);
	                shiftAirframes(arr,i);
	                i--;
	                deleteCounter++;
	            }
	        }
	    }
	}
}

int main() {
	// decleare struct array
	struct Airframe airframes[5];
	
	// initialize with NA
	int i;
	for (i = 0; i < 5; i++) {
		// set inistial values to "NA" or 0
	    strcpy(airframes[i].model,"NA");
	    strcpy(airframes[i].manufacturer,"NA");
	    airframes[i].year = 0;
	    airframes[i].quantity = 0;
	}
	
	// Main loop
	int c, option;
	int runLoop = 1;
	while (runLoop) {
	    // Show menu
    	printf("What would you like to do?\n");
    	printf("1: Add Airframe\n");
    	printf("2: Remove Airframe\n");
    	printf("3: Display inventory\n");
    	printf("4: Quit\n> ");
    	
		// take input
    	while (1) {
        	if (scanf("%d", &option) == 1 && option >= 1 && option <= 4) {
                break;
            } else {
                printf("Invalid Input! Try again: ");
                // clear buffer
                while ((c = getchar()) != '\n' && c != EOF) { }
            }
    	}
        
        // Perform menu option
        switch (option) {
            case 1:
                addAirframe(airframes);
                break;
            case 2:
                deleteAirframe(airframes);
                break;
            case 3:
                printAirframes(airframes);
                break;
            case 4:
                runLoop = 0;
                break;
            default:
                printf("Option not valid!\n\n");
                break;
        }
	}
	
	return 0;
}