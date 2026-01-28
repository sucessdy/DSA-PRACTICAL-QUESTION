#include <iostream>
#include <vector>
#include <unordered_set>
#include <set> 
#include <cctype>
using namespace std;

// int secondLargest(vector<int> &arr)
// {
//     sort(arr.begin(), arr.end());
//     int n = arr.size();

//     for (int i = n - 2; i >= 0; i--)
//     {

//         if (arr[i] != arr[n - 1])
//         {
//             return arr[i];
//         }
//     }
//     return -1;
// }

// int secondLargestwithBetter(
//     vector<int> &arr)
// {
//     int largest = 0;

//     int n = arr.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > largest)
//         {
//             largest = arr[i];

//         }
//     }
//     int secondLargest = INT_MIN;

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > secondLargest && arr[i] != largest)
//         {
//             secondLargest = arr[i];

//         }
//     }
//     return secondLargest ;
// }

int secondLargestHelper(vector<int> &arr)
{
    int largest = arr[0];
    int secondlargest = INT_MIN;

    int n = arr.size();
    if (n < 2)
        return -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondlargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondlargest && arr[i] != largest)
        {

            secondlargest = arr[i];
        }
    }
    return (secondlargest == INT_MIN ? -1 : secondlargest);
}
int secondSmallestHelper(vector<int> &arr)
{
    int smallest = arr[0];
    int secondSmallest = INT_MAX;
    int n = arr.size();
    if (n < 2)
        return -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < secondSmallest && arr[i] != smallest)
        {
            secondSmallest = arr[i];
        }
    }

    return (secondSmallest == INT_MAX ? -1 : secondSmallest);
}

vector<int> secondLargestwithOptimal(vector<int> &arr)
{
    int slargest = secondLargestHelper(arr);
    int ssmallest = secondSmallestHelper(arr);
    return {slargest, ssmallest};
}
bool isSorted(vector<int> &nums)
{

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= nums[i - 1])
        {
        }
        else
            return false;
    }
    return true;
}

int Duplicate(vector<int> &arr)
{
    set<int> s;
    vector<int> res;
    for (auto i : arr)
    {
        if (s.find(i) == s.end())
        {
            s.insert(i);
            res.push_back(i);
        }
    }
    arr = res;

    return arr.size();
}

int DuplicateWithBrute(vector<int> &arr)
{
    int idx = 0;
   set<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        s.insert(arr[i]);
    }
    for (auto i : s)
    {

        arr[idx] = i;
        idx++;
    }
    return idx;
}

int DuplicatewithB(vector<int> &arr) {
    int i = 0; 
    int n  = arr.size() ; 
    if (n <= 1) return n; 
    for (int j = 1; j < arr.size() ;  j ++) {
         if (arr[i] != arr[j]) { 
            arr[j]  = arr[i +1 ] ;
            i++; 
         }
    }
    return i +1;

}
int main()
{

    vector<int> arr = {1, 1, 2};
    // cout << Duplicate(arr) << endl;
    // cout << DuplicatewithBetter(arr)
        //  << endl;
    // cout << secondLargestwithBetter(arr) << endl;

    //  vector<int> res = secondLargestwithOptimal(arr);

    // for (auto i :res ){
    //     cout << i << " ";
    // }
    // cout << endl;

    // vector<int> nums= {1, 2, 3,4, 8} ;
    // cout << isSorted(nums) << endl;

    return 0;
}