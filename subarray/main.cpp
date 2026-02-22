#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

void subArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        vector<int> temp;
        for (int j = i; j < arr.size(); j++)
        {
            temp.push_back(arr[j]);
            for (auto i : temp)
            {
                cout << i << " ";
            }

            cout << endl;
        }
    }
}
// brute force
int subArraywithLongest(vector<int> arr, int k)
{

    int len = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sub = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sub += arr[j];
            if (sub == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }

    return len;
}

int subarrayWithLongestSum(vector<int> &a, long long k)
{
    map<long long, int> PrefixMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = sum - k;
        // i
        if (PrefixMap.find(rem) != PrefixMap.end())
        {
            int len = i - PrefixMap[rem];
            maxLen = max(maxLen, len);
        }

        /// for zero we handle this
        if (PrefixMap.find(sum) == PrefixMap.end())
        {
            PrefixMap[sum] = i;
        }
    }

    return maxLen;
}

int subarrayWithOptimal(vector<int> &a, long long k)
{
    int left = 0;
    int right = 0;
    int n = a.size();
    long long sum = a[0];
    int maxLen = 0;

    while (right < n)
    {
        while (left <= right && sum > k)
        { // if it's more keep on subtracting
            sum -= a[left];
            left++;
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1) ; 
        }
        right++;
        if (right < n)
            sum += a[right];
    }
    return maxLen; 
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 3 , 3};
    // subArray(arr);
    //
    // cout << subArraywithLongest(arr, 3)  << endl;
    // cout << subarrayWithLongestSum(arr, 3) << endl;
    cout << subarrayWithOptimal(arr, 6) << endl;

    unordered_map<int, string> m;
    m[1] = "apple";
    m[2] = "banana";
    auto it = m.find(1);
    if (it != m.end())
    {
        cout << "found " << it->second << endl;
    } 
    it = m.find(3);
    if (it == m.end())
    {
        cout << "not found" << endl;
    }

    return 0;
}