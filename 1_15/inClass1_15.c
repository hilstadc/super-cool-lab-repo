#include <stdio.h>

int main()
{
    // input variable
	int input = 0;

    // take inputs
    printf("Please choose an aircraft:\n1: B747\n2: A320\n3: A321\n4: B757-3\n5: SR71\n> ");
    scanf("%d", &input);

    // print the aircraft chosen
	printf("You chose ");
    switch (input)
	{
		case 1:
			printf("B747");
			break;
		case 2:
			printf("A320");
			break;
		case 3:
			printf("A321");
			break;
		case 4:
			printf("B757-3");
			break;
		case 5:
			printf("SR71");
			break;
		default:
			printf("an invalid aircraft");
			break;
	}
	printf("\n");
}