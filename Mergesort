#include <stdio.h>

// ---------------- MERGESORT FUNCTION ----------------
void mergesort(int a[], int l, int h)
{
    int m;
    if (h <= l)
        return;
    else {
        m = (l + h) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, h);
        merging(a, l, m, h);
    }
}

// ---------------- MERGING FUNCTION ----------------
void merging(int a[], int l, int m, int h)
{
    int b[50];
    int i = l, j = m + 1, k = l;

    while (i <= m && j <= h)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= m)
        b[k++] = a[i++];

    while (j <= h)
        b[k++] = a[j++];

    // copy back to original array
    for (k = l; k <= h; k++)
        a[k] = b[k];
}

// ---------------- MAIN FUNCTION ----------------
int main()
{
    int a[50], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergesort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}
