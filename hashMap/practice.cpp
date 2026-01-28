#include <iostream>
#include <vector>
using namespace std; 


int longestConsetive (vector<int> &arr) {
if (arr.size() == 0) {
    return 0 ; 

}

     sort(arr.begin() , arr.end()) ; 
     int cnt = 1, res = 1 ; 
     for ( int i  = 1;  i < arr.size() ; i ++
     ) { 
        if (arr[i] == arr[i-1]) continue;
        if (arr[i] == arr[i-1] +1) {
            cnt++;
        }
        else { 
            cnt=1 ;

        }
        res = max(res, cnt) ; 
     }
     return res; 

}
int main () { 
    vector<int> arr= {100, 1001, 1, 2,3 , 4 , 101}; 
    cout << longestConsetive(arr) << endl; 
    return 0;

}