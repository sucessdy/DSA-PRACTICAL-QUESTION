// ❓ Problem:

// Given an array of integers, return the index of the first element that is unique (appears only once).
// If no unique element exists, return -1.

// Example:
// Input: [4, 5, 1, 2, 0, 4]
// Output: 1   // because 5 is the first element that appears only once

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int Unique(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        int j;

        for (j = 0; j < arr.size(); j++)
        {

            if (i != j && arr[i] == arr[j])
            {

                break;
            }
        }
        if (j == arr.size())
        {
            return i;
        }
    }

    return -1;
}

int UniqueFirstElement(vector<int> &arr)
{
    unordered_map<int, int> m;
    for (auto it : arr)
    {
        m[it]++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (m[arr[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}

int firstUniqChar(string s)
{
    vector<int> vec(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        vec[s[i] - 'a']++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (vec[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}

vector<int> unionTwoSortedArray(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> unionArr;
    while (i < n && j < n2)
    {
        // if our j is bigger
        if (a[i] <= b[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while (i < n)
    {
        if (unionArr.size() == 0 || unionArr.back() != a[i])
        {
            unionArr.push_back(a[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (unionArr.size() == 0 || unionArr.back() != b[j])
        {
            unionArr.push_back(b[j]);
        }
        j++;
    }
    return unionArr;
}

vector<int> IntersectionWithBruteForce(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();
    vector<int> ans;
    vector<int> vis(m, 0);

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j] && vis[j] == 0)
            {
                ans.push_back(a[i]);
                vis[j] = 1;
                break;
            }

            if (b[j] > a[i])
                break;
        }
    }
    return ans;
}

vector<int> IntersectionWithOptimal(vector<int> &a, vector<int> &b){ 
int i = 0; 
int j = 0; 
vector<int> ans; 
while (i < a.size()  && j <b.size() ){ 
  if (i > 0 && a[i - 1] == a[i]) {
    i++;
    continue;
}


    if (a[i] < b[j]) {
        i++;
    }

    else if (a[i] > b[j]){
        j++;
    }
    else { 
   
ans.push_back(a[i]) ; 
        

i++;
j++ ; 

    }
}
return ans ; 
}
int main()
{
    vector<int> arr = {4, 1, 1, 2, 2, 0, 4};
    cout << UniqueFirstElement(arr) << endl;
    string s = "abc123";
    cout << firstUniqChar(s) << endl;
    vector<int> a = { 2,2, 3, 4, 5, 5};
    vector<int> b = {2, 2, 3, 4, 5, 6};

    // vector<int> res = unionTwoSortedArray(a, b);
    // vector<int> res = IntersectionWithBruteForce(a, b);
    vector<int> res = IntersectionWithOptimal(a, b);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}