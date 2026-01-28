#include <iostream> 
#include <vector> 

using namespace std ;
// data started = 20 / aug / 2025 

// insert and easre  are most expensive opertaion  O(n)
int main () { 

    vector<int> v ; 

vector<int> vec(10, -1); // most important sytnax for DP or advance proagramming 
for ( int i  : vec) {
cout << i <<" ";
} 
cout << endl; 

v.push_back(1);
v.push_back(2);
v.push_back(3);
v.push_back(4);
v.push_back(5);
v.insert(v.begin() + 2 , 8); 
// v.pop_back() ; 
// v.erase(v.begin()) ; 
// cout << v.size() << endl;
// cout << v.capacity() << endl ;
for ( int i : v){
    cout << i << " ";
}
cout << endl;
//  direct memory location.. with iterator 

// this is forward loop in iterator 
// vector<int>::iterator it ;
// for ( auto it = v.begin() ; it != v.end() ; it++ ) { 
//     cout << *(it) << " "; 
// } 
// cout << endl; 


// this is backed loop with iterator 

// vector<int>::reverse_iterator it;
// for (auto it = v.rbegin() ; it != v.rend() ; it++){
//     cout << *(it) << " ";
// }
// cout << endl;  

// cout << "vec at 3 : " << v.at(3) << "\n" << v[3] << endl;  
//  




    return 0; 
}