#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

typedef struct {
    int id;
    char name[20];
} EMPLOYEE;

EMPLOYEE e[SIZE];

// Function to initialize the hash table
void initialize_table() {
    for (int i = 0; i < SIZE; i++) {
        e[i].id = 0;
        strcpy(e[i].name, ""); // Initialize the name to an empty string
    }
}

// Function to insert an employee into the hash table
void insert_table() {
    int i, id, index, hvalue;
    char name[26];

    printf("Enter the employee id and name: ");
    scanf("%d %s", &id, name);

    hvalue = id % SIZE; // Hash value
    for (i = 0; i < SIZE; i++) {
        index = (hvalue + i) % SIZE; // Linear probing
        if (e[index].id == 0) { // Check for an empty slot
            e[index].id = id;
            strcpy(e[index].name, name);
            printf("Employee inserted at index %d\n", index);
            return;
        }
    }
    printf("Hash table full\n"); // If no empty slot is found
}

// Function to display the hash table
void display_table() {
    printf("Index\tId\tName\n");
    for (int i = 0; i < SIZE; i++) {
        if (e[i].id != 0) {
            printf("%d\t%d\t%s\n", i, e[i].id, e[i].name);
        } else {
            printf("%d\t-\t-\n", i);
        }
    }
}

int main() {
    int ch = 0;

    initialize_table(); // Initialize the hash table

    while (1) {
        printf("\n1: Insert\t2: Display\t3: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert_table();
                break;
            case 2:
                display_table();
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Enter a valid choice\n");
        }
    }

    return 0;
}
