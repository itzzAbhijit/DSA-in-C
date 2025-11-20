#include <stdio.h>

void insertionSort(int a[], int n)
{
    int i, j, key;

    // Loop for unsorted region
    for (i = 1; i < n; i++)
    {
        key = a[i];   // Pick the element to be inserted
        j = i - 1;

        // Shift elements greater than 'key' to the right
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        // Insert the key at its correct position
        a[j + 1] = key;
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

    // Call insertion sort function
    insertionSort(a, n);

    printf("Sorted elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}