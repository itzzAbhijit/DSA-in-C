#include <stdio.h>
#include <stdlib.h>

typedef struct bst
{
    int data;
    struct bst *left, *right;
} node;

void insert(node **ptroot, int val)
{
    if (*ptroot == NULL)
    {
        *ptroot = (node *)malloc(sizeof(node)); // create node using malloc
        (*ptroot)->data = val;
        (*ptroot)->left = (*ptroot)->right = NULL;
    }
    else if (val < (*ptroot)->data)
    {
        insert(&((*ptroot)->left), val);
    }
    else
    {
        insert(&((*ptroot)->right), val);
    }
}

node *binarySearch(node *ptr, int val)
{
    if (ptr == NULL)
        return NULL;
    else if (ptr->data == val)
        return ptr;
    else if (val < ptr->data)
        return binarySearch(ptr->left, val);
    else
        return binarySearch(ptr->right, val);
}

void preorder(node *ptr)
{
    if (ptr == NULL)
        return;
    else
    {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(node *ptr)
{
    if (ptr == NULL)
        return;
    else
    {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

void postorder(node *ptr)
{
    if (ptr == NULL)
        return;
    else
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void delnode(node **ptroot, int val)
{
    if (*ptroot == NULL)
        return;

    if (val < (*ptroot)->data)
    {
        delnode(&((*ptroot)->left), val);
    }
    else if (val > (*ptroot)->data)
    {
        delnode(&((*ptroot)->right), val);
    }
    else
    {
        node *tmp = *ptroot;

        // Case 1: No child
        if ((*ptroot)->left == NULL && (*ptroot)->right == NULL)
        {
            free(tmp);
            *ptroot = NULL;
        }
        // Case 2: Only left child
        else if ((*ptroot)->left != NULL && (*ptroot)->right == NULL)
        {
            *ptroot = (*ptroot)->left;
            free(tmp);
        }
        // Case 3: Only right child
        else if ((*ptroot)->right != NULL && (*ptroot)->left == NULL)
        {
            *ptroot = (*ptroot)->right;
            free(tmp);
        }
        // Case 4: Two children
        else
        {
            tmp = (*ptroot)->right;
            while (tmp->left != NULL)
                tmp = tmp->left;

            (*ptroot)->data = tmp->data;
            delnode(&((*ptroot)->right), tmp->data);
        }
    }
}

int main()
{
    node *root = NULL;
    int ch, val;
    node *res;

    while (1)
    {
        printf("\n\n---- Binary Search Tree Menu ----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display Inorder\n");
        printf("5. Display Preorder\n");
        printf("6. Display Postorder\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(&root, val);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            delnode(&root, val);
            break;

        case 3:
            printf("Enter value to search: ");
            scanf("%d", &val);
            res = binarySearch(root, val);
            if (res != NULL)
                printf("Value %d found in BST.\n", val);
            else
                printf("Value %d not found.\n", val);
            break;

        case 4:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 6:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 7:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}