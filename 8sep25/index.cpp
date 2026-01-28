#include <iostream>
#include <vector>
#include <set>
using namespace std;
// all day waste
// Find maximum & minimum in an array

void moveZero(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp(n);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp[j++] = arr[i];
        }
    }

    while (j < n)
    {

        arr[j++] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

void moveZeroWithOptimal(vector<int> &arr)
{
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            arr[cnt++] = arr[i];
        }
    }
    while (cnt < arr.size())
    {
        arr[cnt++] = 0;
    }
}

// void largestElementBF(vector<int> &arr) {
//     // vector<int> temp ;
//     sort(arr.begin() , arr.end()) ;

//     // temp.insert(temp.end(), arr.begin(), arr.end());
// }

int largestElement(vector<int> &arr)
{
    // int cnt = 0;
    int maxElem = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (maxElem < arr[i])
        {
            maxElem = arr[i];
            // cnt++;
        }
        // maxElem = max(maxElem, cnt);
    }
    return maxElem;
}

int SecondlargestElementwithBruteForce(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int largest = n - 1; 
    int secLargest = arr[0];

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] != largest)
        {
            secLargest = arr[i];
            break;
        }
    }
    return secLargest;
}
int secondLargestElementwithBetter(vector<int> &arr)
{
    int largest = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (largest < arr[i])
        {
            largest = arr[i];
        }
    }

    int secondLargest = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }
    return secondLargest; // time complexity = O (2n) ;
}
// string largestNumber(vector<int>& nums) {

//     }

int secondLargest(vector<int> &arr, int n)
{
    int slargest = -1;
    int largest = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > slargest)
        {
            slargest = arr[i];
        }
    }
    return slargest;
}

int smallestLargest(vector<int> &arr, int n)
{

    int smallest = arr[0];
    int secSmallest = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < smallest)
        {
            secSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] != smallest && arr[i] < secSmallest)
        {
            secSmallest = arr[i];
        }
    }
    return secSmallest;
}

void Secondlargest(vector<int> &arr, int n)
{
    int slargest = secondLargest(arr, n);
    int smlargest = smallestLargest(arr, n);
    cout << "Second Largest: " << slargest << endl;
    cout << "Second Smallest: " << smlargest << endl;
}

bool checkIfArrayisSorted(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] >= arr[i - 1])
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

void RemoveTheDuplicate(vector<int> &arr)
{
    set<int> s;
    vector<int> result;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.find(arr[i]) == s.end())
        {
            s.insert(arr[i]);
            result.push_back(arr[i]);
        }
    }
    arr = result;
}
int removeDuplicates(vector<int> &nums)
{
    set<int> s;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        if (s.find(nums[i]) == s.end())
        {
            s.insert(nums[i]);
            result.push_back(nums[i]);
        }
    }
    nums = result;
    return nums.size();
}

vector<int> moveZerowithBR(vector<int> &nums)
{
    vector<int> temp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            temp.push_back(nums[i]);
        }
    }
    int zeroCount = nums.size() - temp.size(); // temp
    for (int j = 0; j < zeroCount; j++)
    {
        temp.push_back(0);
    }

    return temp;
}

vector<int> movewithZeroBetter(vector<int> &arr)
{
    int j = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return arr;

    for (int i = j + 1; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    return arr;
}

bool sortedRotate(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> arr = {1, 2, 0, 9, 0, 0, 4, 0};
    // vector<int> rs = movewithZeroBetter(arr);
    // for (auto i : rs)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    //    bool res =  sortedRotate(arr);

    //     if (res) {
    // cout << "true" << endl;
    //     }
    //     else {
    // cout << "false" << endl;
    //     }

    // if (!arr.empty())
    // {
    //     for (auto i : arr)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    // else
    // {
    //     cout << " not valid" << endl;
    // }

      removeDuplicates(arr);

        for (auto i : arr)
        {
            cout << i << " ";
        }
    // cout << checkIfArrayisSorted(arr) << endl;
    // int n = arr.size()  ;
    // moveZeroWithOptimal(arr) ;

    // cout << SecondlargestElementwithBruteForce(arr) << endl;
    // Secondlargest(arr, n);
    // cout << Secondlargest(arr,n ) << endl;
    // largestElementBF(arr);
    // if(!arr.empty()) {
    //     cout << arr.back() -2  << endl;
    // }
    // else {
    //     cout << "arr is empty" << endl;
    // }

    // for ( auto i : arr) {
    //     cout << i << " " ;
    // }
    // cout << endl;

    // cout << largestElement(arr) << endl;

    // vector<int> nums = {1, 2, 3, 0, 9, 0, 4, 5, 0, 0};
    // vector<int> moved = moveZerowithBR(nums);
    // for (auto i : moved)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    return 0;
}