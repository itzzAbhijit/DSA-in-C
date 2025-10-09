#include <stdio.h>
#include <stdlib.h>

typedef struct dll
{
    int data;
    struct dll *next, *prev;
} node;

void addbeg(node **ptstart, node **ptend, int val)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->prev = NULL;
    temp->next = *ptstart;

    if (*ptstart == NULL)
    {
        *ptstart = *ptend = temp;
    }
    else
    {
        (*ptstart)->prev = temp;
        *ptstart = temp;
    }
}

node *linearsearch(node *ptstart, int key)
{
    node *ptr = ptstart;
    while (ptr != NULL)
    {
        if (ptr->data == key)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

void append(node **ptstart, node **ptend, int val)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = *ptend;

    if (*ptend == NULL)
    {
        *ptstart = *ptend = temp;
    }
    else
    {
        (*ptend)->next = temp;
        *ptend = temp;
    }
}

void insertbefore(node **ptstart, node **ptend, int val, int key)
{
    node *ptr;
    ptr = linearsearch(*ptstart, key);
    if (ptr == NULL)
        return;

    else
    {
        if (*ptstart == ptr)
            addbeg(ptstart, ptend, val);
        else
        {
            node *temp;
            temp = (node *)malloc(sizeof(node));
            temp->data = val;
            temp->next = ptr;
            temp->prev = ptr->prev;
            ptr->prev->next = temp;
            ptr->prev = temp;
        }
    }
}
void insertafter(node **ptstart, node **ptend, int val, int key)
{
    node *ptr;
    ptr = linearsearch(*ptstart, key);
    if (ptr == NULL)
        return;

    else
    {
        if (*ptend == ptr)
            append(ptstart, ptend, val);
        else
        {
            node *temp = (node *)malloc(sizeof(node));
            temp->data = val;
            temp->prev = ptr;
            temp->next = ptr->next;
            ptr->next->prev = temp;
            ptr->next = temp;
        }
    }
}

void delend(node **ptstart, node **ptend)
{
    if (*ptstart == NULL)
    {
        return;
    }
    else
    {
        node *temp;
        temp = *ptend;
        if (*ptstart == *ptend)
        {
            *ptstart = *ptend = NULL;
        }
        else
        {
            (*ptend)->prev->next = NULL;
            *ptend = (*ptend)->prev;
        }
        free(temp);
    }
}

void delbeg(node **ptstart, node **ptend)
{
    if (*ptstart == NULL)
    {
        return;
    }
    else
    {

        node *temp;
        temp = *ptstart;
        if (*ptstart == *ptend)
        {
            *ptstart = *ptend = NULL;
        }
        else
        {
            *ptstart = (*ptstart)->next;
            (*ptstart)->prev = NULL;
        }
        free(temp);
    }
}
void delbyval(node **ptstart, node **ptend, int val)
{
    if (*ptstart == NULL)
        return;
    else
    {
        node *ptr;

        ptr = linearsearch(*ptstart, val);
        if (ptr == NULL)
            return;

        if (ptr == *ptstart)
        {
            delbeg(ptstart, ptend);
        }
        else if (ptr == *ptend)
        {
            delend(ptstart, ptend);
        }
        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
        }
    }
}

void display(node *start)
{
    node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    node *start = NULL, *end = NULL;
    int choice, val, key;

    while (1)
    {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Add at beginning\n");
        printf("2. Add at end\n");
        printf("3. Insert before a value\n");
        printf("4. Insert after a value\n");
        printf("5. Delete at beginning\n");
        printf("6. Delete at end\n");
        printf("7. Delete by value\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            addbeg(&start, &end, val);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            append(&start, &end, val);
            break;
        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            printf("Enter key (before which to insert): ");
            scanf("%d", &key);
            insertbefore(&start, &end, val, key);
            break;
        case 4:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            printf("Enter key (after which to insert): ");
            scanf("%d", &key);
            insertafter(&start, &end, val, key);
            break;
        case 5:
            delbeg(&start, &end);
            break;
        case 6:
            delend(&start, &end);
            break;
        case 7:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            delbyval(&start, &end, val);
            break;
        case 8:
            display(start);
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}