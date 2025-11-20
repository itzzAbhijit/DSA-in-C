#include <stdio.h>

void modifiedBubbleSort(int a[], int n)
{
    int i, j, flag, temp;

    for (i = 0; i < n - 1; i++)
    {
        flag = 0; // reset flag for each pass

        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                // swap a[j] and a[j+1]
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                flag = 1; // a swap happened
            }
        }

        // If no swap happened, array is already sorted → stop early
        if (flag == 0)
            break;
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

    modifiedBubbleSort(a, n);

    printf("Sorted elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}