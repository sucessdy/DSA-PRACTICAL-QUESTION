#include <stdio.h>
void Selection(int arr[], int n)
{
    for (int i = 0 ; i < n -1; i ++){ 
        int min = i; 
        for (int j  = i + 1; j < n ; j++){ 
           if (arr[j] < arr[min]){ 
            min = j; 
           }
        }
        int temp = arr[i] ; 
        arr[i] = arr[min] ; 
        arr[min] = temp; 
    }
}
int main()
{
    int arr[] = {13, 5, 6, 2, 1};
    int n = 5;
    Selection(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}