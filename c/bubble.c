#include <stdio.h>
void bubble(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int swap = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = 1;
            }
        }
        if (swap == 0) break;
    }
}
int main()
{
    int arr[] = {1, 3 , 5 , 3, 32} ; 
    int n = 5; 

    bubble(arr, n) ; 
    for (int i = 0 ; i < n ; i++){ 
        printf("%d ", arr[i]) ; 
    }
    return 0; 

}