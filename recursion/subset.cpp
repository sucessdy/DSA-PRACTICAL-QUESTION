#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void printSubsequence(string s, string output)
{
    if (s.size() == 0)
    { 
        cout << output << endl;
        return;
    }

    printSubsequence(s.substr(1), output + s[0]);

    printSubsequence(s.substr(1), output);
}

void premutation(string s, int idx)
{

    if (idx == s.size())
    {
        cout << s << endl;
        return;
    }

    for (int i = idx; i < s.size(); i++)
    {

        swap(s[idx], s[i]);
        premutation(s, idx + 1);
        swap(s[idx], s[i]);
    }
}

// subset sum
int sumSub (vector<int> &arr)  { 

    int sum = accumulate(arr.begin(), arr.end(), 0); 
    return sum;

}


void subsetSum(vector<int> &arr, int idx, vector<int> &sum, vector<vector<int>> &ans)
{

    if (idx == arr.size())
    {
        ans.push_back(sum);
        return;
    }

    sum.push_back(arr[idx]);
    subsetSum(arr, idx + 1, sum, ans);
    sum.pop_back();
    subsetSum(arr, idx + 1, sum, ans);
}

vector<vector<int>> sumSubset(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> sum ;

    subsetSum(arr, 0, sum, ans);
    sort(ans.begin(), ans.end());
   
    // for (const auto& subset : ans) {
    //     cout << "Sum: " << sumSub(const_cast<vector<int>&>(subset)) << endl;
    // }
    return ans;
}

int countSubsets(vector<int>& arr, int idx, int target) {
     if (arr.size() == idx) { 
        return 0; 
     }
     if (target == 0) {
        return 1; 
     }

     
}


int main()
{

    vector<int> arr = {1, 2};

vector<vector<int>> res = sumSubset(arr);
for (const auto& subset : res) {
    for (int num : subset)
        cout << num << " ";
    cout << " -> Sum: " << accumulate(subset.begin(), subset.end(), 0) << endl;
}


    //   string s1  = "abc" ;
    //   string output1 = "" ;

    //   printSubsequence(s1, output1) ;

    //   string s = "abc" ;
    // int idx1 = 0 ;
    //   premutation(s, idx1) ;

    return 0;
}