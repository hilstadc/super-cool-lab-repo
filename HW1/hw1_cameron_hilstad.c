/*
 * File: hw1_cameron_hilstad.c
 * Author: Cameron Hilstad
 * Assignment: Homework 1
 * Date: 01/12/2025
 * References: none
*/
#include <stdio.h>

int main()
{
    // input variables
    float numerator = 0;
    float denominator = 0;

    // take inputs
    printf("Please enter the numerator: ");
    scanf("%f", &numerator);

    printf("Please enter the denominator: ");
    scanf("%f", &denominator);

    // ensure denominator is not 0
    if (denominator == 0)
    {
        printf("ERROR: Divide by 0!\n");
    }
    else
    {
        // divide for answer and print values back to user
        float answer = numerator / denominator;
        printf("Numerator: %.2f; Denominator: %.2f; Answer: %.2f\n", numerator, denominator, answer);
    }
}