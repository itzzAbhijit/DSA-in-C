#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int position(int a[], int l, int h)
{
    int u = h, d = l;
    int p = l + rand() % (h - l + 1); // random pivot index
    int pivot = a[p];

    // move pivot to start
    swap(&a[p], &a[l]);
    p = l;

    while (d < u)
    {
        while (a[u] > pivot && u > l)
            --u;
        while (a[d] <= pivot && d < h)
            ++d;

        if (d < u)
            swap(&a[d], &a[u]);
    }

    // place pivot in its correct position
    swap(&a[p], &a[u]);

    return u;
}

void quicksort(int a[], int l, int h)
{
    if (l < h)
    {
        int p = position(a, l, h);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, h);
    }
}

int main()
{
    int a[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
