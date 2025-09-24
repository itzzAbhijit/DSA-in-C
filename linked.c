#include <stdio.h>
#include <stdlib.h>

// Structure Definition
typedef struct block {
    int data;
    struct block *next;
} node;

// Function to display linked list
void display(node *ptr) {
    if (ptr == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Function to count nodes
int countNodes(node *ptr) {
    int count = 0;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

// Function to add node at beginning
void addBeg(node **phead, int val) {
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = *phead;
    *phead = temp;
}

// Function to add node at end
void addEnd(node **phead, int val) {
    node *temp, *ptr;
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;

    if (*phead == NULL) {   // If list is empty
        *phead = temp;
        return;
    }

    ptr = *phead;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

// Function to delete a node by value
void deleteNode(node **phead, int val) {
    node *temp = *phead, *prev = NULL;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    // If head node itself holds the value
    if (temp != NULL && temp->data == val) {
        *phead = temp->next;
        free(temp);
        printf("Node with value %d deleted.\n", val);
        return;
    }

    // Search for the node
    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    // If value not found
    if (temp == NULL) {
        printf("Value %d not found in list!\n", val);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", val);
}

// Main function (menu-driven)
int main() {
    node *head = NULL;
    int choice, val;

    do {
        printf("\n===== Linked List Menu =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Display List\n");
        printf("5. Count Nodes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &val);
                addBeg(&head, val);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                addEnd(&head, val);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(&head, val);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Total nodes = %d\n", countNodes(head));
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}