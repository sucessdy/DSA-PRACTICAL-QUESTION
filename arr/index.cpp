#include <iostream>
#include <vector>
#include <string> 
#include <unordered_map>
using namespace std;

int freqMin(vector<int> &arr)
{
    int n = arr.size();
    //  vector<bool> visited(n, false);
    int maxFreq = 0;

    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int cnt = 1;

        //   if ( visited[i] == true) {
        //     continue ;
        //   }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                // visited[j] == true ;
                cnt++;
            }

            if (cnt > maxFreq)
            {
                maxFreq = cnt;
                ans = arr[i];
            }
            else if (cnt == maxFreq && arr[i] < ans)
            {
                ans = arr[i];
            }
        }
    }
    return ans;
}

int freqHhashing(vector<int> &arr)
{

    unordered_map<int, int> m;

    int ans = INT_MAX;

    int maxiFreq = 0;

    for (auto it : arr)
    {
        m[it]++;

        if (m[it] > maxiFreq)
        {
            maxiFreq = m[it];
            ans = it;
        }
        else if (
            m[it] == maxiFreq && it < ans)
        {
            ans = it;
        }
    }

    return ans;
}

int firstUnique(vector<int> &nums) { 
    // sort(nums.begin() , nums.end()) ; 
int ans = 0 ; 
int cnt =0; 
for (int i =0 ; i < nums.size() ; i ++) {
   int j ; 
    for (j = 0; j <nums.size() ; j++) {
 if ( i != j && nums[j] == nums[i] ) {

break ; 
    }


       

        
    }

    if ( j == nums.size() ) return nums[i]; 
   

}
return -1; 
} 

int Unique(vector<int> &  nums) { 

    sort(nums.begin() , nums.end()) ; 

    for (int i = 0 ; i< nums.size() ; i++) { 
        if (( i == 0  ||  nums[i] != nums[i-1]) && (i = nums.size() -1 ||  nums[i] !=  nums[i + 1])){
return nums[i] ; 
        }
       
      

    }
    return -1  ; 

}


int hashmapUnique(vector<int> & arr) { 
unordered_map<int, int> m;
for (auto i : arr){
    m[i]++ ; 

}
for (auto i : arr) if (m[i] == 1) return i; 

return -1; 
}

int firstUniqChar(string s) {
        
        unordered_map<char, int> m; 
        for (auto i : s) {
            m[i]++;
        }
        for (auto i: s) {
            if (m[i] == 1) return i; 
        }
        return -1; 
    }
int main()
{
    vector<int> arr = {1, 3, 2, 1, 4, 1, 3, 3};
    cout << freqHhashing(arr) << endl;

    vector<int> nums = {7, 8, 7, 9, 10, 8} ; 
    cout << hashmapUnique(nums) << endl; 

    string s = "leetcode" ; 
    cout << firstUniqChar(s) << endl; 
    return 0;
}