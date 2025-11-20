#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shiftdown(int a[], int n, int p)
{
    int c;
    do
    {
        c = 2 * p + 1; 
        if (c >= n)
            break;

        if (c < n - 1 && a[c] < a[c + 1])
            c = c + 1; 

        if (a[p] < a[c])
        {
            swap(&a[p], &a[c]);
            p = c;
        }
        else
            break;
    } while (c < n);
}

void heapify(int a[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        shiftdown(a, n, i);
}

void heapsort(int a[], int n)
{
    int i;
    heapify(a, n);
    for (i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        shiftdown(a, i, 0);
    }
}

int main()
{
    int a[50], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    heapsort(a, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
