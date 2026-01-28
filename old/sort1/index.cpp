#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int st, int mid, int end)
{
    int i = st;      // left
    int j = mid + 1; // right

    vector<int> temp;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[idx + st] = temp[idx];
    }
}

void mergeSort(vector<int> &arr, int st, int end)
{

    if (st < end)
    {

        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);      // left
        mergeSort(arr, mid + 1, end); // right
        merge(arr, st, mid, end);
    }
}

int countInversion(vector<int> &arr)
{

    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = i + 1; j < arr.size(); j++)
        {

            if (i < j && arr[i] > arr[j])
            {
                count += 1;
            }
         
        }
    }
    return count;
}

int countInversionMerge (vector<int> &arr , int st , int mid, int end) {
int i = st;
int j = mid +1; 
int countInversion = 0;
vector<int> temp ;  
while (i <= mid && j <= end ) { 
    if ( arr[i] < arr[j] ){
        temp.push_back(arr[i]) ; 
        i++; 


    }
    else {
  
        temp.push_back(arr[j]) ; 
        j++; 
              countInversion += (mid-i+ 1) ; 

    }
}

while (i <= mid) {
    temp.push_back(arr[i]) ; 
    i++ ; 
}
while  (j <= end) {
    temp.push_back(arr[j]);
    j++; 
}

for ( int idx = 0; idx <temp.size() ; idx ++ ) {
  arr[idx + st] =   temp[idx]; 
}
return countInversion ; 

}
int countInversionWithOptimal(vector<int> &arr , int st, int end) {
    if (st >= end) {
        return 0;
    }
    int mid = st  + (end - st ) / 2;

    int left = countInversionWithOptimal(arr, st, mid);
    int right = countInversionWithOptimal(arr , mid+ 1, end);
    int mergeCount = countInversionMerge(arr, st, mid, end);

    return left + right + mergeCount;
}
int main()
{

    // vector<int> arr = {12, 31, 25, 8, 32, 17};
    // int st = 0;
    // int end = arr.size() - 1;

    // mergeSort(arr, st, end);
    // for ( int i = 0 ; i< arr.size() ; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    vector<int> arr = {1, 3, 5, 10, 2, 6, 8, 9};
    int st = 0;
    int end = arr.size() -1; 
    // cout << countInversion(arr) << endl;
    cout << countInversionWithOptimal(arr , st, end) << endl; 
    return 0;
}