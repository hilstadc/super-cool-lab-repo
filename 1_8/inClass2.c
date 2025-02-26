#include <stdio.h>

int main()
{
	int total = 0;

	int foodChoice = 0;
	int drinkChoice = 0;

	int priceTaco = 10;
	int priceBurger = 5;
	int priceDrink = 1;

	int tax = 2;

	printf("Hello, what are you hungry for? (Enter 1 for taco or 2 for burger): ");
	scanf("%d",foodChoice);

	printf("What would you like to drink? (Enter 1 for soda or 2 for tea):");
	scanf("%d",drinkChoice);

	if (foodChoice == 1)
	{
		total = priceTaco;
	}
	else
	{
		total = priceBurger;
	}
	total += priceDrink;
	
	printf("Your total today is: $%d",total);
}
