#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool comparator(pair<int , int> p1, pair<int, int> p2) {
    if(p1.second < p2.second ) return true; 
    if (p1.second > p2.second) return false;
    if (p1.first < p2.first) return true; 
   else  return false; 


    
}

int main()
{
    // int arr[6] = {1, 2, 3, 4, 5, 4};
    // vector<pair<int, int >> arr =  {{1, 2}, {3, 4} , {5, 6}, {0, 1} ,  {9, 2} , {5, 4}};
    // vector<int> arr =  {1, 2, 3, 4, 5, 4};
    // int n = sizeof(arr) / sizeof(arr[0]);

    // sort(arr.begin(), arr.end());
// sort(arr, arr+n, greater<int>()) ; // descending order


    // sort(arr.begin(), arr.end(), comparator );
// reverse(arr.begin() , arr.end()); 

    // for (auto i : arr)
    // {
    //     // cout << i.first   << i.second << " " << endl;
    //     cout << i << " " << endl; 
    // }
  

    //  premutation 

    // string s = "abc" ;
    // next_permutation(s.begin(), s.end()) ; 
    // cout << s << endl; 

    //  max element .. min element 

    vector<int> arr = {1, 3, 6, 7,7, 8,19} ; 
    cout << *(max_element(arr.begin(), arr.end())) << endl; 
    cout << *(min_element(arr.begin(), arr.end())) << endl; 


    return 0;
}