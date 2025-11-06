#include <stdio.h>

void shell_sort(int a[], int n)
{
    int gap = n / 2;
    int i, j, t;

    while (gap > 0)
    {
        for (i = gap; i < n; ++i) {
            t = a[i];
            for (j = i - gap; j >= 0 && t < a[j]; j = j - gap)
            {
                a[j + gap] = a[j];
            }
            a[j + gap] = t;
        }
        gap = gap / 2;
    }
}

int main()
{
    int n, i;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    shell_sort(arr, n);
    
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
