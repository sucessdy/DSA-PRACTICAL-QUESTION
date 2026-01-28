#include <iostream>
#include <vector>
using namespace std; 

int missing(vector<int> &arr) { 
int sum = 0; 
int n = arr.size() ; 
int total = (n * (n +1) / 2 ); 
for (int i =0; i < n ; i ++) {
    sum+=arr[i] ; 

}
return total -sum ; 
}


int missingNumberwithBrute (vector<int> &arr, int N) { 
for (int i  = 0 ; i < N; i++ ) { 
    int flag = 0; 
    for (int j = 0; j < N ; j++) {
        if (arr[j] == i){
flag =1; 
break; 
        }
    }
    if (flag == 0) return i;  
}
return N; 

}

int main() {
    vector<int> arr = {3,0,1} ; 
    int N = arr.size() ; 
    // cout << missing(arr) << endl; 
    cout << missingNumberwithBrute(arr, N) << endl; 

    return 0 ;
}