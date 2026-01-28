#include <iostream>
#include <vector> 
#include <string> 

using namespace std;


class Solution {
private:
    void trySolution(vector<string> board, int x, int y, int n, int queensLeft, vector<vector<string>>& solutions, vector<int> unusedX) {
        unusedX.erase(remove(unusedX.begin(), unusedX.end(), x), unusedX.end());

        int i = y + 1;
        int j = x + 1;
        while (i < n and j < n) {
            if (board[i][j] == 'Q') return;
            i++;
            j++;
        }

        i = y - 1;
        j = x - 1;
        while (i >= 0 and j >= 0) {
            if (board[i][j] == 'Q') return;
            i--;
            j--;
        }

        i = y + 1;
        j = x - 1;
        while (i < n and j >= 0) {
            if (board[i][j] == 'Q') return;
            i++;
            j--;
        }

        i = y - 1;
        j = x + 1;
        while (i >= 0 and j < n) {
            if (board[i][j] == 'Q') return;
            i--;
            j++;
        }

        y++;
        if (y == n) {
            solutions.push_back(board);
            return;
        }
        for (int x : unusedX) {
            board[y][x] = 'Q';
            trySolution(board, x, y, n, queensLeft - 1, solutions, unusedX);
            board[y][x] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        int queensLeft = n;
        vector<string> board(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i] += '.';
            }
        }
        vector<int> unusedX;
        for (int i = 0; i < n; i++) {
            unusedX.push_back(i);
        }
        for (int x = 0; x < n; x++) {
            board[0][x] = 'Q';
            trySolution(board, x, 0, n, queensLeft - 1, solutions, unusedX);
            board[0][x] = '.';
        }
        return solutions;
    }
};


// another way 



class Solution {
    // Hashing with size of n , 2*n - 1 and 2*n -1 respectively.
    int SameRow[9],UpperDiagnol[17],LowerDiagnol[17];

    bool CanPlace(int row, int col, int n) // Tells that can we place a Queen in (row,col) on the board.
    {
        return (SameRow[row] == 0 && LowerDiagnol[row + col] == 0 && UpperDiagnol[n-1 + col-row] == 0);
    }

    void Solve(int col, vector<string> &answer, vector<vector<string>> &answers, int n)
    {
        // Base condition.
        if(col == n)
        {
            answers.push_back(answer);
            return;
        }

        for(int row =0; row < n; row++)
        {
            if(CanPlace(row,col,n))
            {
                answer[row][col] = 'Q';
                // Now we should mark the presence of this Queen in SameRow, upper and lower Diagnol.
                SameRow[row] = 1;
                UpperDiagnol[n-1 + col-row] = 1;
                LowerDiagnol[row + col] = 1;
                Solve(col+1,answer,answers,n);

                // On Backtracking we should remove this Queen and unmark its presence in Hashing.
                answer[row][col] = '.';
                SameRow[row] = 0;
                UpperDiagnol[n-1 + col-row] = 0;
                LowerDiagnol[row + col] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answers; // Store all valid solutions.
        vector<string> answer(n); // One of the valid solutions.
        string s(n,'.');
        for(int i=0; i<n; i++) answer[i] = s;

        Solve(0,answer,answers,n);

        return answers;
    }
};


// 0ms 



class Solution {
public:
void solve(int n,int col,vector<int>&leftrow,vector<int>&upperdia,vector<int>&lowerdia,vector<string>&board,vector<vector<string>>&ans)
{

    if(col==n) {
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++)
    {    if(leftrow[row]==0&&upperdia[n-1-row+col]==0&&lowerdia[row+col]==0)
    {
        board[row][col]='Q';
        leftrow[row]=1;
        upperdia[n-1-row+col]=1;
        lowerdia[row+col]=1;
        solve(n,col+1,leftrow,upperdia,lowerdia,board,ans);
        board[row][col]='.';
        leftrow[row]=0;
        upperdia[n-1-row+col]=0;
        lowerdia[row+col]=0;

    }}
}


    vector<vector<string>> solveNQueens(int n) {
int col=0;
vector<int> leftrow(n,0);
vector<int> upperdia(2*n-1);
vector<int> lowerdia(2*n-1,0);
vector<string> board(n);
string s(n,'.');
vector<vector<string>> ans;
for(int i=0;i<n;i++)
{
    board[i]=s;
}
                solve(n,col,leftrow,upperdia,lowerdia,board,ans);
                return ans;

    }
};