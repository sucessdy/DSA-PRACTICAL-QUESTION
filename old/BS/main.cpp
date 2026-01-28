#include <iostream>
#include <vector>
using namespace std;
void singalArraywithBruteForce(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i - 1] != arr[i] && arr[i] != arr[i + 1])
        {
            cout << i;
        }
    }
}

int SingleElementwithOptimal(vector<int> &arr)
{
    int st = 0, end = arr.size() - 1;
    if (arr.size() == 1)
    {
        return arr[0];
    }
    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (mid == 0 && arr[0] != arr[1])
            return arr[mid];

        if (mid == arr.size() - 1 && arr[arr.size() - 1] != arr[arr.size() - 2])
        {
            return arr[mid];
        }

        if (arr[mid - 1] != arr[mid] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }
        if (mid % 2 == 0)
        {
            if (arr[mid - 1] == arr[mid])
            { // even no
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else
        {
            if (arr[mid - 1] == arr[mid])
            { // odd no
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}

/// search in a rotate sorted array

void RotatedSortedArray(vector<int> &arr, int tar)
{

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == tar)
        {
            cout << i;
        }
    }
}
int RotatedSortedArraywithOptimal(vector<int> &arr, int tar)
{
    int st = 0;
    int end = arr.size() - 1;
    while (st < end

    )
    {
        int mid = st + (end - st) / 2;
        if (arr[st] <= arr[mid])
        { // left part is sorted

            if (arr[st] <= tar && tar <= arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else
        { // right part is sorted

            if (arr[mid + 1] <= tar && tar <= arr[end])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int FirstOccurance(vector<int>
                       &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        int j;

        for (j = 0; j < arr.size(); j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                return i;
            }
           
        }
    }
}
int main()
{
    vector<int> arr = {
        6,
        7,
    };
    // singalArraywithBruteForce(arr);
    // cout << SingleElementwithOptimal(arr) << endl;
    RotatedSortedArray(arr, 0);
    return 0;
}