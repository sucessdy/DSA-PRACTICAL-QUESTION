#include <iostream>
#include <vector>
#include <string>
using namespace std;

void RatinMaze(vector<vector<int>> &mat, int row, int col, string path, vector<string> &ans)
{
    int n = mat.size();
    if (row < 0 || col < 0 || row >= n || col >= n || mat[row][col] == 0 || mat[row][col] == -1)
    {
        return;
    }

    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(path) ; 
        return ;
    }

    mat[row][col] = -1; 
    // down
    // string newPath = path + "D";
    RatinMaze(mat, row + 1, col, path + "D", ans);

    // up

    RatinMaze(mat, row - 1, col, path + "U", ans);
    // left
    RatinMaze(mat, row, col - 1, path + "L", ans);

    // right
    RatinMaze(mat, row, col + 1, path + "R", ans);
        mat[row][col] =1; 

}

vector<string> FindPath(vector<vector<int>> &mat)
{

    vector<string> ans;
    string path = "";

    RatinMaze(mat, 0, 0, path, ans);
    return ans;
}
int main()
{

     vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string>  res = FindPath(mat) ; 
    for ( auto i : res  ) {
        cout << i <<  endl; 
    }


    return 0;
}