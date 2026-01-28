#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void subarray(vector<int> arr)
{
   
    int n = arr.size();


    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << arr[k];
            }
            cout << " ";
        }
        cout << endl;
    }
}
void subarrayWithOptimal(vector<int> arr)
{

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = i; j < n; j++)
        {
            temp.push_back(arr[j]);

            for (int val : temp)
            {
                cout << val;
            }
            cout << " ";
        }
        cout << endl;
    }
}
long long subarraywithCount(vector<int> arr)
{
    int n = arr.size();
    long long total = 0;

    for (int i = 0; i < n; i++)
    {

        total += (long long)arr[i] * (i + 1) * (n - i);
    }

    return total;
}

/// find the duplicates

int RemoveDuplicate(vector<int> &arr)
{
    int n = arr.size();
    set<int> s;
    vector<int> result;
    for (int i = 0; i < n; i++)
    {

        if (s.find(arr[i]) == s.end())
        {
            s.insert(arr[i]);
            result.push_back(arr[i]);
        }
    }
    arr = result;
    return arr.size();
}
// 287. Find the Duplicate Number

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and using only constant extra space.

// / brute force

int findTheDuplicate(vector<int> &arr)
{
    unordered_set<int> S;
    for (auto val : arr)
    {
        if (S.find(val) != S.end())
        {
            return val;
        }
        S.insert(val);
    }

    return -1;
}

//  /  slow and fast pointer

int findtheDuplicatewithOptimal(vector<int> &arr)
{
    int slow = arr[0];
    int fast = arr[0];

    do
    {                          /// why do while do, cuz slow and fast pointer is at same 0th place ...so we don't want first checl the condition just run a loop for slow and fast to meet again
        slow = arr[slow];      // + 1
        fast = arr[arr[fast]]; // + 2

    } while (slow != fast);
    slow = arr[0];
    while (slow != fast)
    {                     // so here we expecting to be at different place
        slow = arr[slow]; // + 1
        fast = arr[fast]; // + 1
    }
    return slow;
}
// brute force
// bool TwoSum(vector<int> &arr, int tar)
// {
//     for (int i = 0; i < arr.size(); i++)
//     {
//         int j = i + 1;
//         int sum = arr[i] + arr[j];
//         if (sum == tar)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// vector<int> TwoSumwithVector(vector<int> &arr, int tar)
// {
//     for (int i = 0; i < arr.size(); i++)
//     {
//         int j = i + 1;
//         int sum = arr[i] + arr[j];
//         if (sum == tar)
//         {
//             return {i, j};
//         }
//     }
//     return {};
// }

// vector<int> TwoSumwithBetter(vector<int> &arr, int tar)
// {
//     sort(arr.begin(), arr.end());
//     int st = 0, end = arr.size() - 1;

//     while (st < end)
//     {
//         int sum = arr[st] + arr[end];
//         if (sum == tar)
//         {
//         }
//         else if (sum < tar)
//         {
//             st++;
//         }
//         else
//         {
//             end--;
//         }
//     }

//     return {};
// }
// better
vector<int> TwoSumWithoutHash(vector<int> nums, int target)
{
    int st = 0;
    int end = nums.size() - 1;

    vector<pair<int, int>> arr;

    for (int i = 0; i < nums.size(); i++)
    {                                // so we don't direclty change in the original array
        arr.push_back({nums[i], i}); /// store value + index
    }

    sort(arr.begin(), arr.end());

    while (st < end)
    {
        int sum = arr[st].first + arr[end].first;
        if (sum == target)
        {
            return {arr[st].second, arr[end].second};
        }
        else if (sum < target)
        {
            st++;
        }

        else
        {
            end--;
        }
    }

    return {};
}

vector<int> twoSumwithOptimal(vector<int> arr, int target)
{

    unordered_map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        int first = arr[i];
        int second = target - first;
        if (m.find(second) != m.end())
        {
            // return {i, m[second]}; // also work
            ans.push_back(i);
            ans.push_back(m[second]);
            break;
        }
        m[first] = i;
    }
    return ans;
}

int removeDuplicates(vector<int> &nums)
{
    set<int> s;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (s.find(nums[i]) == s.end())
        {
            s.insert(nums[i]);
            ans.push_back(nums[i]);
        }
    }
    nums = ans;
    return nums.size();
}

int RemoveDuplicatewithOptimal(vector<int> &arr)
{

    int n = arr.size();
    if (n <= 1)
    {
        return n;
    }

    int idx = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            arr[idx] = arr[i];
            idx++;
        }
    }

    return idx;
}

int missingNumber(vector<int> &arr)
{
    int sum = 0;
    int n = arr.size();
    int total = (n * (n + 1) / 2);
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return total - sum;
}
void repeating(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {

        bool alreadyPrinted = false;

        for (int k = 0; k < i; k++)
        {
            if (arr[i] == arr[k])
            {
                alreadyPrinted = true;
                break;
            }
        }

        if (alreadyPrinted)
            continue;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                cout << arr[i] << " ";
                break;
            }
        }
    }
}

void repeatingwithSet(vector<int> &arr)
{
    unordered_set<int> s;
    unordered_set<int> print;

    for (int i = 0; i < arr.size(); i++)
    {
        if (print.find(arr[i]) != print.end())
        {
            continue;
        }
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                cout << arr[i];
                print.insert(arr[i]);
                break;
            }
        }
    }
}

void repeatingwithbetter(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
        {
            if (i == 1 || arr[i] != arr[i - 2])
            {
                cout << arr[i];
            }
        }
    }
}

vector<int> GridRepeatingandMissing(vector<vector<int>> &grid)
{
    vector<int> ans;
    unordered_set<int> s;
    int sum = 0;
    int expectSum = 0;
    int actualSum = 0;

    int n = grid.size();
    int a, b = 0;
    for (int i = 0; i < n; i++)
    { // repeating '

        for (int j = 0; j < n; j++)
        {
            actualSum += grid[i][j];
            if (s.find(grid[i][j]) != s.end())
            {
                a = grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }
    //
    // missing

    expectSum = (n * n) * (n * n + 1) / 2;
    b = expectSum + a - actualSum;
    ans.push_back(b);
    return ans;
}
int main()
{
    vector<vector<int>> grid = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};

    vector<int>  rs = GridRepeatingandMissing(grid);
    for (auto i : rs)
    {
      
            cout << i<< " ";
        
       
    }
     cout << endl;
    // vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 5, 5};

    // repeating(arr);

    // repeatingwithSet(arr);
    // repeatingwithbetter(arr);

    // vector<int> nums = {1, 1, 2};
    // int target = 5;
    // vector<int> res = twoSumwithOptimal(nums, target);
    // // cout << TwoSum(nums, target) << endl;
    // for (auto i : res)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // cout << RemoveDuplicatewithOptimal(nums) << endl;

    // vector<int> arr = {3,0,1} ;
    // cout << missingNumber(arr) << endl;

    // vector<int> arr = {1, 1, 1, 1,1};
    // vector<int> arr ={3, 1, 2, 3,4} ;
    // cout << findtheDuplicatewithOptimal(arr);

    // cout << subarraywithCount(arr)  << endl;

    //
    // vector<int>arr= { 5, 4, 1, 6, 7};
    // int tar = 9;
    // if (TwoSum(arr, tar) ) {
    //     cout << "true is existes" << endl ;
    // } else{
    //     cout << "Not valid" << endl;
    // };

    // vector<int> arr = {5, 4, 1, 6, 7};

    // // vector<int> res = TwoSumwithVector(arr, 9);
    // vector<int> res = TwoSumwithBetter(arr, 9);
    // for (auto i : res)
    // {
    //     cout
    //         << i << " ";
    // }
    // cout << endl;

    // vector<int> arr = {1, 2, 3, 4, 4,  5,  6};
    // cout << repeatingNumber(arr) << endl;
    return 0;
}
