#include<stdio.h>
int partition(int arr[],int low,int high)
{
    int i = low, j = high, temp, pivot = arr[low];
    while(i<j)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void QuickSort(int arr[],int low,int high)
{
    int j;
    if(low<high)
    {
        j = partition(arr,low,high);
        QuickSort(arr,low,j-1);
        QuickSort(arr,j+1,high);
    }
}
int main()
{
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    QuickSort(arr,0,n-1);
    printf("Sorted array: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}