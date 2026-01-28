#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{
    // horizontal
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == 'Q')
            return false;
    }

    // vertically

    for (int j = 0; j < n; j++)
    {
        if (board[j][col] == 'Q')
            return false;
    }

    // left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    // right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

// void nQueen(vector<string> &board, int row, int n, int &count)
// {
//     if (row == n)
//     {
//         count++;
//         return;
//     }

//     for (int i = 0; i < n; i++)
//     {

//         if (isSafe(board, row, i, n))
//         {
//             board[row][i] = 'Q';
//             nQueen(board, row + 1, n, count);
//             board[row][i] = '.';
//         }
//     }
// }

// int totalNQueens(int n)
// {
//     vector<string> board(n, string(n, '.'));

//     int count = 0;

//     nQueen(board, 0, n, count);
//     return count;
// }

int nQueen(vector<string> &board, int row, int n)
{
    if (row == n)
    {
        return 1; // found one valid solution
    }

    int total = 0;
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'Q';

            // add solutions from deeper recursion
            total += nQueen(board, row + 1, n);

            board[row][col] = '.';
        }
    }
    return total; // return number of solutions found from this state
}

int totalNQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    return nQueen(board, 0, n);
}

bool isPalind(string s)
{
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return s == s2;
}

void getAllPart(string s, vector<string> &partition, vector<vector<string>> &ans)
{
    if (s.size() == 0)
    {
        ans.push_back(partition);
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {

        string parts = s.substr(0, i + 1);
        if (isPalind(parts))
        {
            partition.push_back(parts);

            getAllPart(s.substr(i + 1), partition, ans);
            partition.pop_back();
        }
    }
}

vector<vector<string>> PalindromePartition(string s)
{ 
    vector<vector<string>> ans;
    vector<string> partition;

    getAllPart(s, partition, ans);
    return ans;
}

void GetCombination(vector<int> &nums, int start, int k, vector<int> &combin, vector<vector<int>> &ans)
{
    if (combin.size() == k)
    {
        ans.push_back(combin);
        return;
    }

    for (int i = start; i < nums.size(); i++)
    {
        combin.push_back(nums[i]);
        GetCombination(nums, i + 1, k, combin, ans);
        combin.pop_back();
    }
}

vector<vector<int>> combination(vector<int> &nums, int k)
{
    vector<vector<int>> ans;
    vector<int> combin;

    GetCombination(nums, 0, k, combin, ans);
    return ans;
}

void LetterCombination(string digits, int start, string &combin, vector<string> &ans, vector<string> &map)
{

    if (start == digits.size())
    {
        ans.push_back(combin);
        return;
    }

    for (char ch : map[digits[start] - '0'])
    {
        combin.push_back(ch);
        LetterCombination(digits, start + 1, combin, ans, map);
        combin.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits.empty())
        return ans;
    string combin = "";
    int start = 0;
    vector<string> map = {"", "",
                          "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    LetterCombination(digits, start, combin, ans, map);
    return ans;
}

void MergeSorted(
    vector<int> &A, int m, vector<int> &B, int n)
{
    int idx = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    // case 1 : is when i is greater space 1, 2, 3, 0, 0, 0  and j is larger in number j = 4, , 5,6 so we can copy the element in i ...
    while (i >= 0 && j >= 0)

    {
        if (A[i] >= B[j])
        {
            A[idx--] = A[i--];
        }
        else
        {
            A[idx--] = B[j--];
        }
    }
    // case when j is smaller then i when i = 4, 5, 6 , 0, 0, 0 and j = 1, 2, 3
    while (j >= 0)
    {
        A[idx--] = B[j--];
    }
}

// void printArray(vector<int> &A, int m, vector<int> &B, int n) {
//     for (auto i : A) {
//         cout << i << " ";
//     }
//     cout << endl;
// }

void Permutation(vector<int> &nums, int idx, vector<vector<int>> &ans)
{
    if (nums.size() == idx)
    {
        ans.push_back({nums});
        return;
    }
    
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        Permutation(nums, idx + 1, ans);
        swap(nums[idx], nums[i]);
    }
}
vector<vector<int>> permute(
    vector<int> &nums, int idx)
{
   
    vector<vector<int>> ans;
    Permutation(nums, 0, ans);
    return ans;
}

void printArray(const vector<vector<int>> &nums)
{
    for (const auto &i : nums)
    {
        for (auto val : i)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}



int main()
{

    //      vector<int> A = {1,  2, 3, 0, 0, 0} ;
    //      int m = 3 ;
    //      vector<int> B = {2, 5 ,6} ;
    //      int n = 3;

    // MergeSorted(A, m, B, n);
    // printArray(A, m, B, n) ;

    // int n = 4;

    // cout << totalNQueens(n) << endl;

    string s = "babad";
    vector<vector<string>> partitions = PalindromePartition(s);
    for (const auto &partition : partitions)
    {
        for (const auto &str : partition)
        {
            cout << str << ", ";
        }
        cout << endl;
    }

    // vector<int> nums = {1, 2, 3};
    // int k = 2;
    // vector<vector<int>> res = combination(nums, k);

    // for (auto i : res)
    // {
    //     for (auto val : i)
    //     {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    // string digit = "";
    // vector<string> result = letterCombinations(digit);

    // for (auto &i : result)
    // {
    //     cout << i << endl;
    // }


    // vector<int> nums = {1, 2, 3};
    // vector<vector<int>> permutations = permute(nums, 0);
    // printArray(permutations);

    return 0;
}