
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int secondLargestElement(vector<int> &nums)
{
    // your code goes here
    // sort(nums.begin() , nums.end()) ;
    sort(nums.begin(), nums.end(), greater<int>()); // n log n
    int secondLargest = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != secondLargest)
        {
            secondLargest = nums[i];
            break;
        }
    }
    return secondLargest;
}

int secondLargest(vector<int> &nums)
{
    int largest = INT_MIN;
    int cnt = 0;

    for (int i = 0; i < nums.size(); i++)

    {

        if (nums[i] > largest)
        {
            largest = nums[i];
        }
    }

    int secondLargest =-1;

    for (int i = 0; i < nums.size(); i++)

    {

        if (nums[i] > secondLargest && nums[i] != largest)
        {
            secondLargest = nums[i];
        }
        
    }

    return secondLargest;
}

// int secondLargestwithOptmise(vector<int> &arr)
// {
//     int largest = 0;
//     int secondlargest = -1;

//     for (int it = 0; it < arr.size(); it++)
//     {

//     }
// }

unordered_map<int, int> buildFrequency(vector<int> &arr, int target)
{

    unordered_map<int, int> m;
    for (auto val : arr)
    {
        if (arr[val] == target)
        {
            m[val]++;
        }
    }
    return m;
}
int main()
{
    vector<int> nums = {5, 5,  5};
    // cout << secondLargestElement(nums) << endl;
    cout << secondLargest(nums) << endl;

    vector<int> arr = {1, 2, 3, 2, 2, 4, 5};
    int k = 2;
    unordered_map<int, int> res;
    buildFrequency(arr, k);
    cout << "Count of " << k << " = " << arr[k] << endl;
    k = 3;
    cout << "Count of " << k << " = " << arr[k] << endl;
    return 0;
}