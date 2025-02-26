/*
	* File: hw3_cameron_hilstad.c
	* Author: Cameron Hilstad
	* Assignment: Homework 3
	* Date: 01/26/2025
	* References: none
*/
#include <stdio.h>

int main()
{
	// input variables
	float hoursWorked;
	int employeeID;
	float hourlyRate;
	int employeeType;
	int talkToManager;
	
	// initial prompt
	printf("Please enter the amount of hours you have worked > ");
	scanf("%f",&hoursWorked);
	printf("Please enter your employee ID (1000-1000000) > ");
	scanf("%d",&employeeID);
	printf("Please enter your hourly pay rate > ");
	scanf("%f",&hourlyRate);
	printf("Please enter your employment type (1: Hourly | 2: Salary) > ");
	scanf("%d",&employeeType);
	
	// scrub results
	while (employeeID < 1000 || employeeID > 1000000 || hourlyRate > 100 || employeeType > 2 || employeeType < 1) {
		// employee ID must be 1000-1000000
		if (employeeID < 1000 || employeeID > 1000000) {
			printf("Your employee ID is incorrect. Please try again > ");
			scanf("%d",&employeeID);
		}
		// hourly rate must be <= $100
		if (hourlyRate > 100) {
			printf("Your hourly rate is too high. Please try again > ");
			scanf("%f",&hourlyRate);
		}
		// employee type is either 1 or 2
		if (employeeType < 1 || employeeType > 2) {
			printf("Your employee type is invalid. Please try again (1: Hourly | 2: Salary) > ");
			scanf("%d",&employeeType);
		}
	}
	
	// Check if manager needs to be contacted
	if (hoursWorked > 60) {
		talkToManager = 1;
		hoursWorked = 60;
	} else {
		talkToManager = 0;
	}
	
	// print summary
	printf("\nHello employee %d, your hourly rate is %f, your employment type is ", employeeID, hourlyRate);
	(employeeType == 1) ? printf("hourly, ") : printf("salary, ");
	printf("your hours worked are %f, and you ", hoursWorked);
	if (talkToManager) {
		printf("need to speak with your manager. ");
		printf("This is required before working more than 60 hours. "); 
		printf("Your hours worked have automatically been set to 60.\n");
	} else {
		printf("do not need to speak with your manager.\n");
	}
	
	
	// main loop variables
	int runLoop = 1;
	int option;
	float currentPay;
	int currentPayWhole;
	int wholeOrExact;
	
	// main loop
	while (runLoop) {
		// give space between prompts
		printf("\n");
		// display talk to manager before prompt
		if (talkToManager) {
			printf("You have tried to enter more than 60 hours and must speak with your manager to clear this message.\n");
		}
		
		// print menu
		printf("Please choose an option:\n");
		printf("1: Calculate current pay\n");
		printf("2: Change hours worked\n");
		printf("3: Change hourly rate\n");
		printf("4: Change employee type\n");
		printf("5: View talk to manager status\n");
		printf("6: Show summary\n");
		printf("7: Exit\n");
		scanf("%d", &option);
		
		// switch based on input
		switch (option) {
			case 1:
				// calculate pay
				// depends on type, same under 40 hours, but salary capped at 40
				if (employeeType == 1) {
					currentPay = hourlyRate * hoursWorked;
				} else if (employeeType == 2 && hoursWorked >= 40) {
					currentPay = hourlyRate * 40;
				} else {
					currentPay = hourlyRate * hoursWorked;
				}
				
				// ask how user wants result rounded
				printf("Would you like to view whole dollars or the exact amount? (1: Whole | 2: Exact) > ");
				scanf("%d",&wholeOrExact);
				while (wholeOrExact < 1 || wholeOrExact > 2) {
					printf("Your input is invalid. Please try again (1: Whole | 2: Exact) > ");
					scanf("%d",&wholeOrExact);
				}
				
				// print result
				if (wholeOrExact == 1) {
					currentPayWhole = currentPay;
					printf("Your current pay is $%d\n",currentPayWhole);
				} else {
					printf("Your current pay is $%f\n",currentPay);
				}
				
				break;
			case 2:
				// cahnge hours worked
				printf("Please enter the amount of hours you have worked > ");
				scanf("%f",&hoursWorked);
				
				// check if manager needs to be notified
				if (hoursWorked > 60) {
					talkToManager = 1;
					hoursWorked = 60;
					printf("You must speak with your manager before working more than 60 hours. ");
					printf("Your hours worked have automatically been set to 60.\n");
				}
				
				break;
			case 3:
				// change pay rate
				printf("Please enter your hourly pay rate > ");
				scanf("%f",&hourlyRate);
				while (hourlyRate > 100) {
					printf("Your hourly rate is too high. Please try again > ");
					scanf("%f",&hourlyRate);
				}
				
				break;
			case 4:
				// change employment type
				printf("Please enter your employment type (1: Hourly | 2: Salary) > ");
				scanf("%d",&employeeType);
				while (employeeType < 1 || employeeType > 2) {
					printf("Your employee type is invalid. Please try again (1: Hourly | 2: Salary) > ");
					scanf("%d",&employeeType);
				}
				
				break;
			case 5:
				// check manager status
				(talkToManager) ? printf("You must speak with your manager\n") 
				: printf("You do not need to speak with your manager\n");
				
				break;
			case 6:
				// print summary (same as original summary)
				printf("Hello employee %d, your hourly rate is %f, your employment type is ", employeeID, hourlyRate);
				(employeeType == 1) ? printf("hourly ") : printf("salary ");
				printf("your hours worked are %f, and you ", hoursWorked);
				if (talkToManager) {
					printf("need to speak with your manager before working more than 60 hours. ");
					printf("Your hours worked have automatically been set to 60.\n");
				} else {
					printf("do not need to speak with your manager.\n");
				}
				
				break;
			case 7:
				runLoop = 0;
				break;
			default:
				printf("Invalid option.\n");
				break;
		}
	}
}	