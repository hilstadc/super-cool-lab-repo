#include <stdio.h>

int main() {
	// input array
	float inputArr[3];
	
	// Prompt for 3 numbers
	printf("Please enter 3 numbers: \n");
	int i;
	for (i = 0; i<3; i++) {
		printf("Please enter number %d: ",i+1);
		scanf("%f", &inputArr[i]);
	}
	
	//Ternary to print if mission passed or failed
	float sum = inputArr[0] + inputArr[1] + inputArr[2];
	(sum > 12.11) ? printf("Mission Failed\n")
		: printf("Mission Passed\n");
	
	//Assign value to soap (Can't initialize with ternary) (Can't loop through an uninitialed at compile char array) (have to set letters individually)
	char soap[15];
	if (sum > 12.11) {
		soap[0] = 'M';
		soap[1] = 'i';
		soap[2] = 's';
		soap[3] = 's';
		soap[4] = 'i';
		soap[5] = 'o';
		soap[6] = 'n';
		soap[7] = ' ';
		soap[8] = 'f';
		soap[9] = 'a';
		soap[10] = 'i';
		soap[11] = 'l';
		soap[12] = 'e';
		soap[13] = 'd';
		soap[14] = '\0';
	} else {
		soap[0] = 'M';
		soap[1] = 'i';
		soap[2] = 's';
		soap[3] = 's';
		soap[4] = 'i';
		soap[5] = 'o';
		soap[6] = 'n';
		soap[7] = ' ';
		soap[8] = 'p';
		soap[9] = 'a';
		soap[10] = 's';
		soap[11] = 's';
		soap[12] = 'e';
		soap[13] = 'd';
		soap[14] = '\0';
	}
	// soap must be initalized at compile or this won't work. That's why I can't just initialize it in the if statement
	printf("soap is equal to: %s\n", soap);
}
