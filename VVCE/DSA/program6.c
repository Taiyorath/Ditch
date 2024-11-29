#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    int data;
    struct student *next, *prev;
} NODE;

// Function to create a new node
NODE* getnode() {
    NODE *x = (NODE*)malloc(sizeof(NODE));
    if (x == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("\nEnter Data of Node to be Inserted: ");
    scanf("%d", &x->data);
    x->next = x->prev = NULL;
    return x;
}

// Function to insert a node at the front of the list
NODE* insert_front(NODE* first) {
    NODE *temp = getnode();
    if (first == NULL) {
        return temp; // List was empty
    } else {
        temp->next = first;
        first->prev = temp;
        return temp; // New node is now the first node
    }
}

// Function to insert a node to the left of a specified node
NODE* insert_left(NODE* first) {
    NODE *temp, *cur, *pre;
    int data;

    if (first == NULL) {
        temp = getnode();
        return temp; // List was empty
    } else {
        printf("Enter the node data to which left part new node to be inserted: ");
        scanf("%d", &data);
        
        cur = first;
        while (cur != NULL && cur->data != data) {
            pre = cur;
            cur = cur->next;
        }

        if (cur == NULL) {
            printf("No such node with data %d found.\n", data);
            return first; // Node with specified data not found
        }

        temp = getnode();
        temp->next = cur;
        temp->prev = pre;

        if (pre != NULL) {
            pre->next = temp;
        }
        
        cur->prev = temp;

        // If inserting before the first node
        if (cur == first) {
            return temp; // New node is now the first node
        }

        return first; // Return original head
    }
}

// Function to delete a specified node from the list
NODE* delete_node(NODE* first) {
    NODE *cur = first;
    int data;

    printf("Enter the data of the NODE to be deleted: ");
    scanf("%d", &data);

    if (first == NULL) {
        printf("\nList is empty\n");
        return NULL;
    }

    while (cur != NULL && cur->data != data) {
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("No such node is present in the list\n");
        return first; // Node not found
    }

    // Node found and needs to be deleted
    if (cur->prev != NULL) {
        cur->prev->next = cur->next;
    } else {
        first = cur->next; // Deleting the first node
    }

    if (cur->next != NULL) {
        cur->next->prev = cur->prev;
    }

    free(cur);
    return first;
}

// Function to display the list
void display(NODE* first) {
    NODE *cur = first;

    if (first == NULL) {
        printf("No nodes present\n");
        return;
    }

    while (cur != NULL) {
        printf("-->%d", cur->data);
        cur = cur->next;
    }
}

int main() {
    NODE *first = NULL;
    int ch;

    while (1) {
        printf("\n1. Insert Front\t 2. Insert Left\t 3. Delete\t 4. Display\t 5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                first = insert_front(first);
                break;
            case 2:
                first = insert_left(first);
                break;
            case 3:
                first = delete_node(first);
                break;
            case 4:
                display(first);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }
    
    return 0;
}
