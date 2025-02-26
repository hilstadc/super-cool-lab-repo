#include <stdio.h>

int main()
{
    // input variables
    int end_number = 0;

    // ask for number
    printf("Please enter a number from 1-1000 to count to: ");
    scanf("%d", &end_number);

    // ensure number is within range
    if (end_number < 1 || end_number > 1000) {
        printf("ERROR: Number not within range");
		return 0;
    }
	
	// print numbers from 0 until the inputted number
	int i = 0;
	while (i <= end_number) {
		printf("%d\n", i);
		i++;
	}
	
	return 0;
}