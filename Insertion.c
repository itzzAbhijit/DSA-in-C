#include<stdio.h>
void insertionSort(int a[],int n)
{
    int i,j,key;
    for(i=1;i<n;++i)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
           a[j+1]=a[j];
           j--;
        }
        a[j+1]=key;
    }
}
int main()
{
    int n;
    printf("Enter the number of element :\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the element to be sorted :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertionSort(a,n);
    printf("Element after being sorted is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}