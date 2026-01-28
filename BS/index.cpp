#include <iostream>
#include <vector>
using namespace std;

int BS(vector<int> &arr, int target)
{
    int st = 0;
    int end = arr.size() - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

// int RotatedSortedArray(vector<int> &arr, int target)
// {
//     int st = 0;
//     int end = arr.size() - 1;
//     while (st <= end)
//     {

//         int mid = st + (end - st) / 2;
//         if (arr[mid] == target)
//             return mid;

//         if (arr[st] <= arr[mid])
//         {
//             if (arr[st] <= target && target <= arr[mid])
//             { // left part sorted
//                 end =  mid - 1;
//             }
//             else
//             {
//                 st = mid + 1;
//             }
//         }
//         else
//         {
//             if (arr[mid] <= target && target <= arr[end])
//             {
//                 st = mid + 1;
//             }
//             else
//             {
//                 end = mid - 1;
//             }
//         }

//         // but  if my right part is sorted
//     }
//     return -1;
// }

// int RotatedSortedArray(vector<int> &arr, int target)
// {

//     int st = 0;
//     int end = arr.size() - 1;
//     while (
//         st <= end)
//     {
//         int mid = st + (end - st) / 2;

//         if (arr[mid] == target)
//             return mid;
//         // Left part sorted
//         if (arr[st] <= arr[mid])
//         {
//             if (arr[st] <= target && target <= arr[mid])
//             {
//                 end = mid - 1;
//             }
//             else
//             {
//                 st = mid + 1;
//             }
//         }
//         else
//         { // // right part sorted

//             if (arr[mid] < target && target <= arr[end])
//             {

//                 st = mid + 1;
//             }
//             else
//                 end = mid - 1;
//         }
//     }

//     return -1;
// }

// int RotatedSortedArray(vector<int> &arr, int target)
// {
//     int st = 0, end = arr.size() - 1;

//     while (st <= end)
//     {
//         int mid = st + (end - st) / 2;

//         if (arr[mid] == target)
//             return mid;

//         // Left half is sorted
//         if (arr[st] <= arr[mid])
//         {
//             if (arr[st] <= target && target < arr[mid])
//                 end = mid - 1;
//             else
//                 st = mid + 1;
//         }
//         // Right half is sorted
//         else
//         {
//             if (arr[mid] < target && target <= arr[end])
//                 st = mid + 1;
//             else
//                 end = mid - 1;
//         }
//     }
//     return -1;
// }

vector<int> ProductExpectSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);

    for (int i = 0; i < n; i++)
    {
        // int prod = 1; // we don't realy need this extra prod varible we can simply store the value in the ans ;;;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                // prod *= nums[j];
                ans[i] *= nums[j];
            }
        }
        // ans[i] = prod;
    }
    return ans;
}

vector<int> pairSum(vector<int> &arr, int target)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
                return {i, j};
        }
    }
    return {-1, -1};
}

vector<int> PairSumWithOptimal(vector<int> &arr, int target)
{
    int st = 0;
    int end = arr.size() - 1;
    while (st < end)
    {
        int mid = st + (end - st) / 2;
        int sum = arr[st] + arr[end];
        if (sum == target)
            return {st, end};
        else if (sum < target)
        {
            st++;
        }
        else
        {
            end--;
        }
    }
    return {-1, -1};
}

int findmax(vector<int> &nums)
{
    int maxOne = 0;
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;
            maxOne = max(maxOne, count);
        }
        else
        {
            count = 0;
        }
    }
    return maxOne;
}

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxNum = 0;
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;

            maxNum = max(maxNum, count);
        }
        else
        {
            count = 0;
        }
    }

    return maxNum;
}

int majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int freq = 1;
    int n = nums.size();
    int ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            freq++;
        }
        else
        {
            freq = 1;
            ans = nums[i];
        }
        if (freq > n / 2)
        {
            return ans;
        }
    }
    return ans;
}

int majorityElement(vector<int> &nums)
{
        int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
  count = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
        }
        if (count > n / 2)
        {
          return  nums[i];
        }
    }
    return -1;
}

int MajorityElementWithOptimal(vector<int> &nums){ 
    int ans = 0;
    int freq = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (freq == 0)
        {
            ans = nums[i];
        }
        if (ans == nums[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    return ans;
}



int main()
{
    // vector<int> arr = {4,5,6,7,0,1,2};
    // int target = 0;
    // cout << RotatedSortedArray(arr, target) << endl;

    // vector<int> nums = {1, 2, 3, 4};

    // vector<int> result = ProductExpectSelf(nums);
    // for (auto i : result)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // vector<int> arr = {2, 7, 9, 10} ;
    // int target= 9;
    // vector<int> ans = PairSumWithOptimal(arr, target) ;
    // for ( auto i  : ans) {
    //     cout << i << " " ;
    // }
    // cout << endl;

    // vector<int> nums = {1,1,0,1,1,1};
    // cout << findMaxConsecutiveOnes(nums) << endl;
    // cout << findmax(nums) << endl;

    vector<int> nums = {6, 5, 5};
    // cout << majorityElement(nums) << endl;
    cout << MajorityElementWithOptimal(nums) << endl;
    return 0;
}