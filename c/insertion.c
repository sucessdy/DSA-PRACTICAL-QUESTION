#include <stdio.h>
void Insertion(int arr[], int n){
    for (int  i = 1; i < n ; i ++){ 
        int curr = arr[i] ; 
        int prev = i -1;
       while (prev >= 0 && arr[prev] >= curr ){
      arr[prev + 1 ] = arr[prev] ; 
      prev--; 

       } 

       arr[prev + 1] = curr; 

    } 

}
int main() { 

    int arr[] = {1, 24, 5, 6 } ;
    int n = 4; 
    Insertion(arr, n) ; 
    for ( int i = 0; i < n ; i++) {
        printf("%d ", arr[i]) ; 
    }
    return 0; 
}