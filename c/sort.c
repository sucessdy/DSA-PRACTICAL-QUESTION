#include <stdio.h>
void merge(int arr[], int st, int mid, int end){ 
    int i = st; 
    int j = mid + 1; 

    int size = end - st + 1; 
    int temp[size] ; 
    int k = 0; 
    while (i <= mid && j <= end){ 
        if (arr[i ] <= arr[j]){ 
            temp[k++] = arr[i++]; 
        }
        else { 
             temp[k++] = arr[j++]; 
        }
    }
//left 
    while (i <= mid) { 
        temp[k++] = arr[i++] ; 
    }

    while (j <= end){ 
        temp[k++] = arr[j++] ; 
    }


// copy temp back to original array

for (int idx  = 0 ; idx < size;idx++ ) { 
    arr[idx + st] = temp[idx] ; 

}
}
void mergeSort( int arr[], int n, int st, int end) { 

    if (st< end){ 
int mid = st + (end - st) / 2;
   mergeSort(arr, n,  st,  mid) ; 
   mergeSort(arr, n, mid+ 1, end) ; 
   merge(arr, st, mid, end) ; 
    }
    
}

void swap( int *a , int * b) {  
    int temp = *a ; 
    *a = *b; 
    *b = temp; 

}
int Partition(int arr[] , int st, int end) { 
int idx = st -1; 

int pivot  = arr[end]; 
for ( int i = st; i < end ; i++ ){ 
    if (arr[i] < pivot) { 
idx++; 
swap(&arr[i] , &arr[idx]); 

    }



}
    idx++; 
    swap(&arr[end] , &arr[idx]) ; 
    return idx; 
}
void quickSort(int arr[], int st,int end){ 
    if (st  < end){ 
        int pivIdx = Partition (arr, st,  end) ; 
        quickSort(arr, st , pivIdx -1) ; 
        quickSort(arr, pivIdx+ 1, end) ; 
         
    }
}
int main() { 
//   int arr[] = {5, 2, 8, 1, 3};
// int n = sizeof(arr) /sizeof(arr[0]) ; 
// int st  = 0; 
// int end = n  -1 ; 

//  mergeSort(arr, 0, st, end ); 

//  printf("Sorted: ");
//  for (int i = 0; i <n; i++)
//         printf("%d ", arr[i]);


        int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printf("Sorted: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);



        return 0;
}