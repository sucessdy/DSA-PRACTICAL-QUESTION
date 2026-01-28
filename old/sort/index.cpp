#include <iostream>
#include <vector>
using namespace std;

void sortColor(vector<int> &arr){ 

    sort(arr.begin() , arr.end()) ; 

    for( auto i : arr) { 
        cout<< i << " " ;
    }
    cout << endl; 
}


void sort( vector<int> &arr)  {
int count = 0;
int count2 = 0 
;

int count3 = 0; 
for ( int i = 0 ; i< arr.size() ;  i++) { 
    if( arr[i]  == 0) { 
count ++; 
    }
    else if ( arr[i] == 1) {
        count2++; 
    }
    else  count3 ++; 
}
int idx = 0 ;

for (int i = 0 ; i < count ; i++) {
arr[idx++] = 0 ; 
}

for (int i = 0 ; i < count2 ; i++) {
arr[idx++] = 1 ; 
}
for (int i = 0 ; i < count3 ; i++) {
arr[idx++] = 2 ; 
}

 
}


int sortTheColor (vector<int> &arr) { 

}
int main () { 
vector<int> arr = { 2, 0, 1, 2, 1, 0} ; 
 sort(arr)  ; 

 for (auto i : arr) { 
    cout << i << endl; 
 }


    return 0; 
}