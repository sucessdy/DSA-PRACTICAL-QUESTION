#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>
using namespace std;

// brute
bool LinearSearch(vector<int> &a, int num)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == num)
        {
            return true;
        }
    }
    return false;
}
int longestConsecutiveElements(vector<int> &a)
{
    int longest = 1;
    if (a.size() == 0)
        return 0;

    for (int i = 0; i < a.size(); i++)
    {
        int cnt = 1;
        int x = a[i];
        while (LinearSearch(a, x + 1) == true)
        {
            x += 1;
            cnt += 1;
        }
        longest = max(longest, cnt);
    }
    return longest;
}
/// better apprach
int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    sort(nums.begin(), nums.end());
    int res = 1;
    int cnt = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
        {
            continue;
        }
        if (nums[i] == nums[i - 1] + 1)
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }
        res = max(res, cnt);
    }
    return res;
}

int longestConsecutiveOptimal(vector<int> &arr)
{
    if (arr.size() == 0)
        return 0;
    int longest = 1;
    unordered_set<int> s;

    for (int i = 0; i < arr.size(); i++)
    {
        s.insert(arr[i]);
    }

    for (auto it : s)
    {
        if (s.find(it - 1) == s.end())
        { // first value for we're checking cuz first element in the sequence we don't have ...previous element
            int cnt = 1;
            int x = it;
            while (s.find(x + 1) != s.end())
            { // next value
                x += 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int longestconsecutive(vector<int> &n)
{
    if (n.empty())
        return 0; 

    set<int> s(n.begin(), n.end());
    vector<int> ans(s.begin(), s.end());
    int cnt = 0;
    int res  = 0; 


    for (int i = 0; i < ans.size() - 1; i++)
    {
        if (ans[i +1] == ans[i] +1 ) {
            cnt++; 
            continue;

        }
        else {
            res = max(res, cnt + 1);
            cnt = 0; 

        }

        
    }
     res = max(res , cnt + 1) ;
    return res; 
}

int main()
{
    vector<int> nums = {-5, -4, -3, -2, -1};
    cout << longestConsecutive(nums) << endl;

    vector<int> a = {-5, -4, -3, -2, -1};
    cout << longestConsecutiveElements(a) << endl;

    vector<int> arr = {-5, -4, -3, -2, -1};
    cout << longestConsecutiveOptimal(arr)
         << endl;

         vector<int> n = {0,3,7,2,5,8,4,6,0,1} ; 
         cout << longestconsecutive(n) << endl; 
    return 0;
}