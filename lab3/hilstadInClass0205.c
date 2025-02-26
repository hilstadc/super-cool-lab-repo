/*
	* File: hilstadInClass0205.c
	* Author: Cameron Hilstad
	* Assignment: In Class 02/05/2025
	* Date: 02/05/2025
	* References: none
*/
#include <stdio.h>
#include <string.h>

int main() {
    char firstStr[50];
    char secondStr[50];
    int c;

    while (1) {
    	printf("Please enter two strings seperated by a space\n> ");
    	if(scanf("%s%s", firstStr, secondStr) == 2) {
    	    break;
    	} else {
    	    printf("Invalid Input!\n");
    	    while ((c = getchar()) != '\n' && c != EOF) {}
    	}
	}
	if (strlen(firstStr) >= 8,strlen(secondStr) >= 8) {
        printf("String is longer than 8 characters! (including null)");
        return 1;
    }
    char result[16];
    strcpy(result, firstStr);
    strcat(result,"+");
    strcat(result, secondStr);
    printf("%s\n",result);
    
    return 0;
}