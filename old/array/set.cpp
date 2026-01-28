#include <iostream>
#include <vector>
#include <set>
using namespace std;

 vector<int> findUnion(vector<int> &a, vector<int> &b) {
        set<int> S ; 
        for (int i = 0 ; i< a.size() ; i ++){ // T.C = O(n .logn)
            S.insert(a[i]);
        }
          for (int i = 0 ; i< b.size() ; i ++){ // T.C = O(n .logn)
            S.insert(b[i]);
        }
        
     vector<int> Union(S.size()); // T.C = O(n + n ) // both can unique in worst case 
      int i = 0;  // union i take here, just to return answer not to solve the problem
      for (auto it : S) { 
        Union[i++] = it; 
       
      }
      return Union;
    }


    
    vector<int> SortedArray( vector<int> &a, vector<int> &b) {
         int n1 = a.size() ; 
         int n2 = b.size() ; 
int i = 0; 
int j = 0; 
vector<int> Union; 

while (i < n1 && j < n2){ 

}

    }
int main() { 
vector <int>  a = {1, 2, 3, 4, 5}  ; 
vector<int>  b = {1, 2, 3, 6, 7}  ; 

vector<int> res = findUnion(a, b) ; 

for (auto i :res) { 
    cout << i  << " " ; 
}
cout << endl; 



    return 0 ; 
}