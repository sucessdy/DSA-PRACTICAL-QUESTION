#include <iostream> 
 #include <vector> 
#include <unordered_map> 
 using namespace std; 
int hashToFindtheDuplicateFirst(vector<int> &arr) { 
unordered_map<int, int> m ; 
for (auto it : arr) { 
     m[it]++; 
}    
 for  (auto it : arr){ 
    if(m[it] > 1) {
        return it; 

    }
 }
 return -1; 


}
 int main() {
    
     vector<int> arr = {1, 2, 3, 4, 2, 1};

    cout << hashToFindtheDuplicateFirst(arr) << endl; 
    return 0; 
 }