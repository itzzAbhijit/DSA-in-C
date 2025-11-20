#include <stdio.h>

void countingSort(int a[], int n, int k)
{
    int c[50], b[50];
    int i;

    // Step 1: Initialize count array with 0
    for (i = 0; i < k; i++)
        c[i] = 0;

    // Step 2: Store the count of each element
    for (i = 0; i < n; i++)
        c[a[i]]++;

    // Step 3: Modify count array (cumulative sum)
    for (i = 1; i < k; i++)
        c[i] = c[i] + c[i - 1];

    // Step 4: Build the output array (from right to left)
    for (i = n - 1; i >= 0; i--)
    {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    // Step 5: Copy sorted elements back to a[]
    for (i = 0; i < n; i++)
        a[i] = b[i];
}

int main()
{
    int a[50], n, k, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter range (k): ");
    scanf("%d", &k);

    printf("Enter %d elements (each < %d):\n", n, k);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    countingSort(a, n, k);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}
