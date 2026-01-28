#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> calculateSpan(vector<int> &arr)
{
    // code here
    vector<int> ans(arr.size(), 1);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i - 1; (j >= 0 && arr[j] <= arr[i]); j--)
        {

            ans[i]++;
        }
    }
    return ans;
}

vector<int> calculateSpanwithStack(vector<int> &arr)
{

    vector<int> ans(arr.size());

    stack<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!s.empty()  && arr[s.top()] <= arr[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = i + 1;
        }
        else
        {
            ans[i] = i - s.top(); // i - prevHigh
        }
            s.push(i);
    }


    return ans;
}

int main()
{

    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans1 = calculateSpanwithStack(arr);
    for (auto i : ans1)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

