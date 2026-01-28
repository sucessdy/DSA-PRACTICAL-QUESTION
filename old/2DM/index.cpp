#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    int sRow = 0;
    int eRow = m - 1;
    int sCol = 0;
    int eCol = n - 1;
    vector<int> ans;

    while (sRow <= eRow && sCol <= eCol)
    {
        // top
        for (int j = sCol; j <= eCol; j++)
        {
            ans.push_back(mat[sRow][j]);
        }

        // right
        for (int i = sRow + 1; i <= eRow; i++)
        {
            ans.push_back(mat[i][eCol]);
        }

        // down
        if (sRow <=eRow)
        {
            for (int j = eCol - 1; j >= sCol; j--)
            {
                ans.push_back(mat[eRow][j]);
            }
        }

        // left
        if (sCol <= eCol) {

              for (int i = eRow - 1; i >= sRow + 1; i--)
        {
        
            ans.push_back(mat[i][sCol]);
        }
        }
      
        sRow++;
        eRow--;
        sCol++;
        eCol--;
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> res = spiralOrder(mat);

    for (auto val : res)
    {

        cout << val << " ";
    }

    //  for (int i = 0; i < mat.size(); i++)
    //     {
    //         for (int j = 0; j < mat[i].size(); j++)
    //         {
    //             cout << mat[i][j] << " ";
    //         }
    //         cout << endl;
    //     }

    cout << endl;

    return 0;
}