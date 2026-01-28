#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;
int findDuplicate(vector<int> &arr)
{

    unordered_set<int> s;
    for (auto i : arr)
    {
        if (s.find(i) != s.end())
        {
            return i; 

      
        }
        s.insert(i); 

    }
    return -1; 

}

int findtheDuplicatewithSlowFast(vector<int> &arr) { 
int slow = arr[0] , fast = arr[0] ; 

do{
    slow = arr[slow] ; 

    fast = arr[arr[fast]] ;


}while(slow != fast) ; 

slow = arr[0] ; 

while (slow != fast) {

 slow = arr[slow] ; 
 fast = arr[fast] ; 
 

}
return slow ;
 
}

int main()
{

    vector<int> arr ={ 2,2,3,4} ; 
    // cout << findDuplicate(arr) << endl; 

    cout << findtheDuplicatewithSlowFast(arr) ; 


    return 0;
}