/*
	* File: inClass0203.c
	* Author: Cameron Hilstad
	* Assignment: In Class 02/03/2025
	* Date: 02/03/2025
	* References: none
*/
#include <stdio.h>
#include <string.h>

void printCat (char str1[201], char str2[100]) {
	strcat(str1,"+");
	strcat(str1,str2);
	printf("Your combined string is: %s",str1);
}

int main()
{
	char stringOne[201];
	char stringTwo[100];
	int c;
	while (1) {
    	printf("Please enter two strings seperated by a space\n> ");
    	if(scanf("%s %s", stringOne, stringTwo) == 2) {
    	    break;
    	} else {
    	    printf("Invalid Input!\n");
    	    while ((c = getchar()) != '\n' && c != EOF) {}
    	}
	}
	printCat(stringOne, stringTwo);
}