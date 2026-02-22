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



int sumDigit(int num ){ 
    int sum=0;

while (num != 0){ 
    int dig = num %10 ; 
    sum += dig ;
num/=10; 

}
return sum; 

}

// void strStr(string a, string b) {
        // int cnt = 0; 
        // while (a.length()  > 0 && a.find(b) < a.length ()){ 
        //     if (a.compare(b) == 0){
        //         cnt ++;
//         //     }
            
//         // }
//         // return cnt; 
//     int i= a.length ; 

// int j = b.length(); 

//     if ((a.compare(b)) == 0){
//          cout << "String Matched" << endl;
//     }
//     else{ 
//          cout << "String Not Matched" << endl;
//     }
        
//     // return -1; 
//     }

    int strStr(string a, string b) {
        int cnt = 0; 
    int n = a.length() ;
    int m = b.length();     

    for (int i = 0 ; i < n - m+1 ; i++){
        int j ; 
       if (   n != m && n[i + j] ==m[j]  ){
               
                 cnt++                            ; 
       }                                     
          
else { 
    
}
    }
    return -1; 
                      
    }
// bool part = true; 

//         for (int i = 0; i < a.size() ; i++){
//             if (tolower(a[i]) != tolower(b[i])){
//                 part = false; 
//                 break;
//             } 
//             else {
//                 cnt++; 
//             }
//         }
    

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


    // 28. Find the Index of the First Occurrence in a String Input: haystack = "sadbutsad", needle = "sad"
string  a = "sadbutsad"; 
string b = "sad" ; 
cout << strStr(a, b) << endl; 
 
// cout << strStr(a, b) << endl; 


    // vector<int> arr = {3,0,1} ; 
    // int N = arr.size() ; 
    // // cout << missing(arr) << endl; 
    // cout << missingNumberwithBrute(arr, N) << endl; 


    // int n = 123; 
    // cout << sumDigit(n ) << endl; 

    return 0 ;
}