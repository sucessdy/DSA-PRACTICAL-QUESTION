#include <iostream>
#include <vector>
using namespace std;

void Subset(vector<int> &arr, vector<int> &ans, int i)
{
    if (i == arr.size()) 
    {
        for (int i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    ans.push_back(arr[i]);
    Subset(arr, ans, i + 1); //
    ans.pop_back();

    Subset(arr, ans, i + 1);
}

void subSetP(vector<int> &nums, vector<int> &ans, int i)
{

    if (i == nums.size())
    {

        for (int i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
return; 
        
    }
    ans.push_back(nums[i]);
        subSetP(nums, ans, i + 1);
        ans.pop_back();
        subSetP(nums, ans, i + 1);
}
// int subSetPrint(vector<int > &nums , vector<int> ans ,  int i ) {
// if (  i ==  nums.size() ){
// ans.push_back(nums[i])
// ;
// return ;
// }

// ans.push_back(nums[i]) ;
// subSetPrint(nums, ans, i +1) ;
// ans.pop_back() ;

// subSetPrint(nums, ans, i + 1) ;

// }

// bool SubsetPrint(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allset)
// {
//     if (i == nums.size())
//     {
//         allset.push_back({ans}); // this is we push_back the value ..if we don't use the cur;y braces so ...we can pass the ans directly
//         return true;
//     }

//     ans.push_back(nums[i]);
//     SubsetPrint(nums, ans, i + 1, allset);
//     ans.pop_back();

//     SubsetPrint(nums, ans, i + 1, allset);
//     return false;
// }

// vector<vector<int>> subsets(vector<int> &nums)
// {
//     vector<vector<int>> allset;
//     vector<int> ans;
//     SubsetPrint(nums, ans, 0, allset);
//     return allset;
// }

// vector<vector<int>> subsetsWithDup(vector<int>& nums) {

//     }

bool SubSetwithTwo(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allsubset)
{

    if (i == nums.size())
    {
        allsubset.push_back(ans);
        return true;
    }

    // include

    ans.push_back(nums[i]);

    SubSetwithTwo(nums, ans, i + 1, allsubset); // include 
    ans.pop_back(); // backtrack 

    int idx = i + 1;

    while (idx < nums.size() && nums[idx] == nums[idx - 1])
    {
        idx++;
    }
    SubSetwithTwo(nums, ans, idx, allsubset);  // exclude 


    return false;
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> allsubset;
    vector<int> ans;

    SubSetwithTwo(nums, ans, 0, allsubset);
    return allsubset;
}

vector<vector<int>> subset()
{
}

int main()
{
    // vector<int> arr = {1, 2, 3};
    // vector<int> ans;
    vector<int> nums = {1, 2, 3};
    vector<int> ans;
    subSetP(nums,ans , 0 );


    // vector<vector<int>> subsetsResult = subSetP(nums);
    // for (const vector<int> &subset : subsetsResult)
    // {
    //     cout << "[ ";
    //     for (const int &num : subset)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << "]" << endl;
    // }

    // vector<int> nums = {4, 4, 4, 1, 4};
    // vector<vector<int>> subsetsResult = subsetsWithDup(nums);
    // for (const vector<int> &subset : subsetsResult)
    // {
    //     cout << "[ ";
    //     for (const int &num : subset)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << "]" << endl;
    // }
}