#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NAME_LENGTH 50

// TODO: Define the constant that represents the maximum # of elements in inventory.

// Define the structure for the inventory node
struct Node {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
    struct Node* next;  // Pointer to the next node in the list
};

// Function to create a new node and add it to the linked list
struct Node* create_node(const char* name, int quantity) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strncpy(new_node->name, name, MAX_ITEM_NAME_LENGTH);
    new_node->name[MAX_ITEM_NAME_LENGTH - 1] = '\0';  // Ensure null-termination
    new_node->quantity = quantity;
    new_node->next = NULL;  // New node is the last one in the list
    return new_node;
}

// Function to add a node to the inventory (linked list)
void add_node_to_beginning(struct Node** inventory, const char* name, int quantity) {
    //TODO: Implement add Node and only allow a maximum of 28 items to be added at maximum.
}

// Function to add a node to the end of the inventory (linked list)
void add_node_to_end(struct Node** inventory, const char* name, int quantity) {
    struct Node* new_node = create_node(name, quantity);

    if (*inventory == NULL) {
        // If the inventory is empty, make the new node the first node
        *inventory = new_node;
    } else {
        // Otherwise, find the last node and append the new node
        struct Node* current = *inventory;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;  // Append new node to the end of the list
    }
}

// Function to display all nodes in the inventory
void display_inventory(struct Node* inventory) {
    if (inventory == NULL) {
        //TODO
    }
    struct Node* current = inventory;
    while (current != NULL) {
        printf("Item: %s, Quantity: %d\n", current->name, current->quantity);
        current = current->next;
    }
}

// Function to free the memory allocated for the inventory
void free_inventory(struct Node* inventory) {
    //TODO
}

int main() {
    struct Node* inventory = NULL;  // Initialize the inventory as empty

    // TODO: call add_node functions at least 10 times with your own data.
    

    // Displaying the inventory
    printf("Inventory:\n");
    display_inventory(inventory);

    // Freeing the allocated memory
    free_inventory(inventory);

    return 0;
}
