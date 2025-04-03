/*
	* File: in_class_03-24-25.c
	* Author: Cameron Hilstad
	* Assignment: In Class 03/24/2025
	* Date: 03/24/2025
	* References: lectures
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Node structure
typedef struct item {
	char item_name[50];
	float item_value;
	struct item* next;
} Item;

// Function to add an item to the inventory
void add_item(char *item_name) {
    //fill in here
}

// Function to remove an item from the inventory
void remove_item(char *item_name) {
    //fill in here
}

// Function to view all items in the inventory
void view_inventory() {
	
}

// Function to remove front object
void pop() {
    //Fill in here
}

int main() {
    Item swordOfTheGoblinKing = {}

    return 0;
}
