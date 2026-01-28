#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int> &nums, int st, vector<vector<int>> &ans)
{
    if (st == nums.size())
    {
        ans.push_back({nums});
        return;
    }

    for (int i = st; i < nums.size(); i++)
    {
        if (i != st && nums[i] == nums[st])
            continue;

        swap(nums[st], nums[i]);
        backtrack(nums, st + 1, ans);
        swap(nums[i], nums[st]);

        int idx = st+1; 
        while ( idx != st && nums[idx] == nums[idx -1]) continue;
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    backtrack(nums, 0, ans);

    return ans;
}

int main()
{

    vector<int> nums = {2, 2, 1, 1};

    vector<vector<int>> res = permute(nums);
    for (auto i : res)
    {
        for (auto it : i)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}