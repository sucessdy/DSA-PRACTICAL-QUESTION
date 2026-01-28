
#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int maxSum = INT_MIN;

    int n = nums.size();
    int currSum = 0;

    for (int i = 0; i < n; i++)
    {

        currSum += nums[i];
        maxSum = max(currSum, maxSum);

        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}
int main()
{

    vector<int> arr = {-5, -4,  -7, -8};
    cout << maxSubArray(arr) << endl;
}