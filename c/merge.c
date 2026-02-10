#include <stdio.h>
void merge(int arr[], int st, int mid, int end)
{
    int i = st;
    int j = mid + 1;
    int size = end - st + 1;

    int temp[size];
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    // for temp oringinal change

    for (int idx = 0; idx < size; idx++)
    {
        arr[idx + st] = temp[idx];
    }
}
void MergeSort(int arr[],  int st, int end)
{
    if (st < end)
    {
       int mid = st + (end - st) / 2;
        MergeSort(arr, st, mid);
        MergeSort(arr,  mid + 1, end);
        merge(arr, st, mid, end);
    }
}
int main()
{
    int arr[] = {1, 9, 4, 5, 6, 7};
    int n = sizeof(arr) /sizeof(arr[0]) ; 
    int st = 0;
    int end = n - 1;

    MergeSort(arr, st, end);
    printf("Sorted: ");
 for (int i = 0; i <n; i++)
        printf("%d ", arr[i]);


    return 0;
}