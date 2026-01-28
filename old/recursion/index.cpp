#include <iostream>
#include <vector>
using namespace std;
// 30 aug 2025 
void printNumber (int n ) { 
    if ( n ==1) 
    {
        cout << 1 << " ";
        return; 
    }

    cout << n << " "; 
    printNumber(n-1) ; 
}
int factorial(int n ) { 

    if ( n == 0) return 1; 
    if (n == 1 ) return 1;

   return  n * factorial(n -1); 
}
int sumofN(int n ){ 

    if ( n == 1) return 1; 
    return n + sumofN(n -1) ; 
}

// int Recursion (int n) { 
//     if (n  == 1) return  n; 
    
// return Recursion(n) - Recursion(n-1) ; 
// }


int fib ( int n ) { 
    if (n == 0) return 0; 
    if ( n ==1) return 1; 
    return fib(n-1) + fib(n -2) ;
}

// check if a array is sorted in recursion

bool Sorted(vector<int> arr, int n) { 
    if ( n == 0 || n ==1)return true; 
    return arr[n-1]  >= arr[n-2] && Sorted(arr, n-1); 

}


int BinarySearch(vector<int> arr, int target, int st, int end){
    if ( st <= end){
        int mid = st + (end -st) / 2; 

        if (arr[mid] == target) return mid; 
        if (arr[mid] <= target) return 
        BinarySearch(arr, target, mid+1, end) ;
        else { 
            BinarySearch(arr, target, st, mid-1); 
        }

    }
    return -1; 
}


int main(){

    // int n = 4; 
    // for (int i = 1; i <= n; ++i){
    //     cout << i << " " ; 
    // }
    // cout << endl; 


//     int n = 500; 

// printNumber(n) ; 

// int n = 4; 
// cout << factorial(n) << endl; 
// for (int i = 1; i <= n; ++i){
//         cout << i << " " ; 
//     }
//     cout << endl; 

//  int n = 6 ; 
//  cout << fib(n) << endl; 

vector<int> arr = {1, 2, 3,4,5} ; 
cout << BinarySearch(arr, 5, 0, arr.size()-1 ) << endl ; 
// cout << Sorted(arr, arr.size())  << endl; 
    return 0; 
}