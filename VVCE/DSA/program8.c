#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
    int ht; // Height of the node
} NODE;

// Function to calculate the height of a node
int height(NODE *T) {
    if (T == NULL) {
        return -1; // Height of an empty tree is -1
    }
    return T->ht; // Return the stored height
}

// Function to calculate the balance factor of a node
int BF(NODE *T) {
    if (T == NULL) {
        return 0;
    }
    return height(T->left) - height(T->right); // Balance factor = left height - right height
}

// Right rotation
NODE *rotateright(NODE *x) {
    NODE *y = x->left;
    x->left = y->right;
    y->right = x;
    
    // Update heights
    x->ht = height(x);
    y->ht = height(y);
    
    return y; // New root after rotation
}

// Left rotation
NODE *rotateleft(NODE *x) {
    NODE *y = x->right;
    x->right = y->left;
    y->left = x;

    // Update heights
    x->ht = height(x);
    y->ht = height(y);
    
    return y; // New root after rotation
}

// Right-Right case
NODE* RR(NODE *T) {
    return rotateleft(T);
}

// Left-Left case
NODE* LL(NODE *T) {
    return rotateright(T);
}

// Left-Right case
NODE* LR(NODE *T) {
    T->left = rotateleft(T->left);
    return rotateright(T);
}

// Right-Left case
NODE* RL(NODE *T) {
    T->right = rotateright(T->right);
    return rotateleft(T);
}

// Function to insert a node into the AVL tree
NODE* insert(NODE *T, int x) {
    if (T == NULL) {
        T = (NODE*)malloc(sizeof(NODE));
        T->data = x;
        T->left = T->right = NULL;
        T->ht = 0; // Height of new node is 0
        return T;
    } else if (x > T->data) {
        T->right = insert(T->right, x);
        if (BF(T) == -2) {
            if (x > T->right->data)
                T = RR(T); // Right-Right case
            else
                T = RL(T); // Right-Left case
        }
    } else if (x < T->data) {
        T->left = insert(T->left, x);
        if (BF(T) == 2) {
            if (x < T->left->data)
                T = LL(T); // Left-Left case
            else
                T = LR(T); // Left-Right case
        }
    }

    // Update the height of the current node
    T->ht = 1 + ((height(T->left) > height(T->right)) ? height(T->left) : height(T->right));
    
    return T; // Return the updated tree root
}

// Function to perform inorder traversal of the AVL tree
void inorder(NODE *T) {
    if (T != NULL) {
        inorder(T->left);
        printf("%d (BF=%d)\n", T->data, BF(T));
        inorder(T->right);
    }
}

int main() {
    NODE *root = NULL;
    int x, n, i, ch;

    while (1) {
        printf("\n1. Create\t2. Insert\t3. Display\t4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter tree data:\n");
                root = NULL; // Reset root for new tree creation
                for(i = 0; i < n; i++) {
                    scanf("%d", &x);
                    root = insert(root, x);
                }
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 3:
                printf("Inorder sequence:\n");
                inorder(root);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
