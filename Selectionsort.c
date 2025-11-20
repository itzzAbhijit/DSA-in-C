#include <stdio.h>

void selectionSort(int a[], int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;  // Assume current index has minimum element

        // Find the index of the smallest element in the unsorted part
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }

        // Swap the found minimum with the first element of unsorted part
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

int main()
{
    int n;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    int a[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    selectionSort(a, n);

    printf("Sorted elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}