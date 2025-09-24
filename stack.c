#include <stdio.h>
#include <string.h>
#define SIZE 100
typedef struct
{
    int a[SIZE];
    int tos;
} Stack;
void init(Stack *pts)
{
    pts->tos = -1; // Initialize the top of stack index to -1

}
int isfull(Stack *pts)
{
    if (pts->tos == SIZE - 1) // Check if the stack is full
    {
        return 1; // Stack is full
    }
    else
    {
        return 0; // Stack is not full
    }
}

int isempty(Stack *pts)
{
    if (pts->tos == -1) // Check if the stack is empty
    {
        return 1; // Stack is empty
    }
    else
    {
        return 0; // Stack is not empty
    }
}

int push(Stack *pts, int item)
{
    if (isfull(pts))
    {
        printf("Stack is full, cannot push %d\n", item); // Error message if stack is full
        return 0; // Return failure
    }
    else
    {
        pts->tos++;            // Increase the top of stack index
        pts->a[pts->tos] = item; // Push the item onto the stack
        printf("Pushed %d onto stack\n", item); // Confirmation message
        return 1; // Return success
    }
}

int pop(Stack *pts)
{
    if (isempty(pts))
    {
        printf("Stack is empty, cannot pop\n");
        return -999; // Return an error code if stack is empty
    }
    else
    {
        int item = pts->a[pts->tos]; // Get the item from the top of stack
        pts->tos--; // Decrease the top of stack index
        printf("Popped %d from stack\n", item); // Confirmation message
        return item; // Return the popped item
    }
}
int peek(Stack *pts)
{
    if (isempty(pts))
    {
        printf("Stack is empty, cannot peek\n");
        return -999; // Return an error code if stack is empty
    }
    else
    {
        return pts->a[pts->tos]; // Return the item at the top of stack without removing it
    }
}
int main()
{
    printf("Enter 1 for push operation\n");
    printf("Enter 2 for pop operation\n");
    printf("Enter 3 for peek operation\n");
    int choice, item;
    scanf("%d", &choice);
    Stack s;
    init(&s); // Initialize the stack
    switch (choice)
    {
        case 1:
            printf("Enter item to push: ");
            scanf("%d", &item);
            push(&s, item); // Call push function
            break;
        case 2:
            pop(&s); // Call pop function
            break;
        case 3:
            peek(&s); // Call peek function
            break;
        default:
            printf("Invalid choice\n"); // Handle invalid input
            break;
    }
}

