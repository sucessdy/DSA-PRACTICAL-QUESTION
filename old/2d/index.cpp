#include <iostream>
#include <vector>

using namespace std;

// bool matrixGrid(int matrix[][3], int row , int col, int k){
// for ( int i = 0 ; i < row ; i++){
//     for ( int j = 0; j < col ; j ++) {
// if ( matrix[i][j] == k){
//     return true;
// }
//     }
// }
// return false;
// }

pair<int, int> Matrix(const vector<vector<int>>& matrix, int key)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == key)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// // Overload for vector<vector<int>>
// pair<int, int> Matrix(const vector<vector<int>>& matrix, int key)
// {
//     for (int i = 0; i < matrix.size(); i++)
//     {
//         for (int j = 0; j < matrix[i].size(); j++)
//         {
//             if (matrix[i][j] == key)
//             {
//                 return {i, j};
//             }
//         }
//     }
//     return {-1, -1};
// }

int getMaxSum(int matrix[][3], int row, int col)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < col; j++)
        {

            rowSum += matrix[i][j];
        }

        maxSum = max(maxSum, rowSum);
    }
    return maxSum;
}

int getMaxCol(int matrix[][3], int col, int row)
{
    int maxColSum = INT_MIN;

    for (int i = 0; i < col; i++)
    {
        int colSum = 0;
        for (int j = 0; j < row; j++)
        {
            colSum += matrix[j][i];
        }
        maxColSum = max(maxColSum, colSum);
    }
    return maxColSum;
}

pair<int, int> LinearSearch(int matrix[][3], int row, int col, int key)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == key)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int DiagonalSum(int matrix[][3], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                sum += matrix[i][j];
            }
            else if (j == n - 1 - i)
            {
                sum += matrix[i][j];
            }
        }
    }
    return sum; 
}

int diagonalSumOptimal(int matrix[][3], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += matrix[i][i];
        if (i != n - i - 1)
        {
            sum += matrix[i][n - i - 1];
        }
    }
    return sum;
}
// this is function f0r the seacrching in the row after the matrix search 
bool searchInRow (vector<vector<int>> &matrix, int target ,int row ) { 
int n = matrix[0].size(); 
int st = 0 ;
int end = n -1; 

while ( st < end){
    int mid = st+ (end -st)/ 2;
    if ( matrix[row][mid] == target) return true;
else if ( matrix[row][mid] < target){ 
    st = mid + 1; 
}
else {

    end = mid -1
    ; 
}
}

return false;


}

bool SearchMatrix(vector<vector<int>> &matrix, int target)
{
    int st = matrix.size();     // row => m
    int end = matrix[0].size(); // col =>  n
    int stRow = 0;
    int endRow = st - 1;

    while (stRow <= endRow)
    {
        int midRow = stRow + (endRow - stRow) / 2;

        if (matrix[midRow][0] <= target && target <= matrix[midRow][end - 1])
        {
            return searchInRow(matrix, target , midRow) ; 
        }
        else if (target >= matrix[midRow][end- 1]) {
            stRow = midRow +1; 
        }
        else {
            endRow = midRow -1; 
        }
    }
    return false ; 
}

bool SearchMatrixII(vector<vector<int>>&matrix , int target) { 
    int m = matrix.size() ; 
int n = matrix[0].size();
    int  st = 0;  // row 
    int end = n -1;  // col 

    while ( end >= 0 && st  < m){
        int mid = st + (end - st) /2 ; 
        if (matrix[st][end] == target) {
            return true;

        }
        else if (matrix[st][end] < target) {
            // st = mid +1; 

            st++; 
        }
        else {
            end --; 
        }
    }

    return false; 
}
        // pair<int, int> ans = Matrix(matrix, key) ;
int main () {
    // int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix = {{1,3,5,7} ,{ 10,11,16,20} ,{23,30,34,60}};
    int n = 3;
    int row = 3;
    int col = 3;
    int key = 21;
    // cout << diagonalSumOptimal(matrix, n) << endl;
    // cout << DiagonalSum(matrix, n) << endl;

    // cout << getMaxCol(matrix, col, row) << endl;
    // pair<int, int> ans = LinearSearch(matrix, row, col, key);

    // cout << getMaxSum(matrix, row, col) << endl;
// cout << Matrix(matrix, row, col, key) << endl;  
        // pair<int, int> ans = Matrix(matrix, row, col, key) ;

         pair<int, int> ans = Matrix(matrix, key) ;
        if(ans.first == -1){
    cout << "not found\n";
        }
        else {
             cout <<  "index: " << ans.first << " " << ans.second << endl ;
             cout << "value : " << matrix[ans.first][ans.second] << endl;
        }

    // cout << matrixGrid(matrix, row, col, k) << endl;

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cin >> matrix[i][j];
    //     }
    // }

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // 2d vector  =======

    // row => matrix.size();
    // col => matrix[i].size();

    // vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // dyanmic ->
    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     for (int j = 0; j < matrix[i].size(); j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    

    // cout << SearchMatrix( matrix, 34)  << endl;
    return 0;
}