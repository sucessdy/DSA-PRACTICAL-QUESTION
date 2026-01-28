#include <iostream>
#include <vector>
#include <set>
using namespace std;

int RemoveDuplicate(vector<int> &arr)
{

    set<int> s;
    vector<int> result;
    for (int i = 0; i < arr.size(); i++)
    {
        if ( s.find(arr[i]) == s.end())
        {
            s.insert(arr[i]);
            result.push_back(arr[i]);
        }
    }
    arr = result;
    return s.size();
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 4, 5};
    cout << RemoveDuplicate(arr) << endl;
    return 0;
}