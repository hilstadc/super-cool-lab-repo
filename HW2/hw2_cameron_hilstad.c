/*
 * File: hw1_cameron_hilstad.c
 * Author: Cameron Hilstad
 * Assignment: Homework 2
 * Date: 01/19/2025
 * References: geeksforgeeks sleep, bool
*/
#include <stdio.h>
#include <stdbool.h>
//use this on Windows
//#include<windows.h>
//use this on Linux
#include<unistd.h>

int main()
{
	// set to true if running on Linux
	bool isLinux = true;
	
	//input variables
	float T_ambient = 0;
	int fuel = 0;
	float T_required = 0;
	
	//take inputs
	printf("Please enter an ambient temperature: ");
	scanf("%f",&T_ambient);
	
	printf("Please enter a whole number amount of fuel in (gal): ");
	scanf("%d",&fuel);
	
	printf("Please enter a required engine takeoff temperature (F): ");
	scanf("%f",&T_required);
	
	//set delay amount in ms. If running linux, this must be converted to seconds
	int delay = 1000;
	if (isLinux) {
		delay = delay/1000;
	}
	
	//set up startup loop
	int burn_rate = 2; //(gal/s)
	float T_start = T_ambient + 3;
	float T_increase = 1.25; //(F/s)
	int fuel_used = 0;
	int i = 0;
	
	// While loop to calculate warmup time
	while (T_start < T_required) {
		// Increase/decrease values by given rates
		T_start += T_increase;
		fuel_used += burn_rate;
		fuel -= burn_rate;
		i += 1;
		//Change to Sleep (upercase) if on Windows
		sleep(delay);
		//Sleep(delay);
	}
	
	//print start parameters
	printf("Warmup completed after %d seconds. Warmup used %d gallons of fuel. Remaining fuel left onboard is %d gallons.\n",i,fuel_used,fuel);
}