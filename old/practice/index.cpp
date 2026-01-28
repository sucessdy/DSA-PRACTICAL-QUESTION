// 🔹 Warm-up DSA Interview Set (Easy)

// Reverse a String
// Input: "hello"
// Output: "olleh"

// Find Maximum Element in an Array
// Input: [2, 5, 1, 7, 3]
// Output: 7

// Check if a Number is Prime
// Input: 29
// Output: true
// Input: 12
// Output: false

// Check if a String is Palindrome
// Input: "racecar" → true
// Input: "hello" → false

// Move All Zeroes to End (Maintain Order)
// Input: [0, 1, 0, 3, 12]
// Output: [1, 3, 12, 0, 0]

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include <iomanip>
#include <sstream>
using namespace std;

string ReverseString(string s)
{ // iterative mood backwards loops
    string reverse = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        reverse += s[i];
    }
    return reverse;
}

string ReverseStringwithTwo(string s1)
{ // inplace
    int st = 0;
    int end = s1.size() - 1;
    while (st < end)
    {
        swap(s1[st], s1[end]);
        st++;
        end--;
    }
    return s1;
}

int maximumNumber(vector<int> &arr)
{
    int maxSum = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {

        if (maxSum < arr[i])
        {
            maxSum = arr[i];
        }
    }

    return maxSum;
}
bool primeNumber(int n)
{
    int prime = 1;
    if (n <= 1)
        return 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool palindrome(string str)
{
    int st = 0;
    int end = str.size() - 1;
    while (st < end)
    {
        if (str[st] != str[end])
            return false;
        st++;
        end--;
    }
    return true;
}

vector<int> MoveZero(vector<int> nums)
{
    int n = nums.size();
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return nums;

    for (int i = j + 1; i < n; i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }

    return nums;
}

int maxOperations(string s)
{
    long long ans = 0, ones = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            ++ones;
        }
        else
        {
            if (i == s.size() - 1 || s[i + 1] == '1')
            {
                ans += ones;
            }
        }
    }
    return ans;
}

int largestRectangleArea(vector<int> &h)
{
int res = 0; 

    for (int i = 0; i < h.size(); i++)
    {
            
            int height = h[i] ; 
            int width  = 1; 
        int j = i - 1;
        while (j >= 0 && h[j] >= height)
        {
            width++;
            j--;
        }

        j = i + 1;
        while (j < h.size() && h[j] >= height)
        {
            width++; 
            j++; 
        }
        res = max(res, height * width) ; 
    }
    
return res; 
}

vector<int> moveZero(vector<int> a)
{
    int n = a.size();

    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            temp.push_back(a[i]);
        }
    }
    int zero = n - temp.size();
    for (int i = 0; i < zero; i++)
    {
        temp.push_back(0);
    }
    return temp;
}

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxi = 0;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
            maxi = max(cnt, maxi);
        }
        else
        {
            cnt = 0;
        }
    }
    return maxi;
}

int singleNumber(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans ^= arr[i];
    }
    return ans;
}

int xorOperation(int n, int start)
{
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int nums = start + 2 * i;
        ans ^= nums;
    }
    return ans;
}

string fractionToDecimal(int numerator, int denominator)
{
    double ans = 1.0 * numerator / denominator;

    // use stringstream to control formatting
    ostringstream out;
    out << fixed << setprecision(2) << ans; // 2 decimal places
    return out.str();
}

int largestRectangleAreawithForce(vector<int> &arr) {
int st  = 0;
int largest = 0; 
int end = arr.size() -1 ; 
while (st < end) { 
    int w = end - st; 
    int h = max(arr[st] , arr[end] ) ;
    int curr = w * h; 
    largest = max(largest, curr) ;
    arr[st] < arr[end] ? st++ : end--;  
}
return largest; 
}


//  int largestRectangleArea(vector<int>& arr) {
//        int largest =0; 
//        int st = 0; 
//        int end  = arr.size() -1;
//        while (st < end) { 
//        int w = end -st; 
//        int h = max(arr[st], arr[end]) ; 
//        int currArea = w * h ; 

//        largest = max(largest, currArea) ; 
//        arr[st] < arr[end]  ? st++ :  end--; 
//        }
//        return largest; 

//     } 
int main()
{

    vector<int>  h = {2,4}
 ; 
 cout << largestRectangleArea(h) << endl; 



    vector<int>  heights = {2,4}
 ; 
 cout << largestRectangleAreawithForce(heights) << endl; 
    //     int  num = 1;
    //     int deno = 2;
    //  string  res =  fractionToDecimal(num, deno) ;
    //  for (auto i : res) {
    //     cout << i <<  "" ;
    //  }
    //  cout << endl;

    //     int n5 =  4;
    //     int start =3;
    //     cout << xorOperation(n5 , start) <<endl;
    //     vector<int> b = {2,3,2} ;
    //     cout <<singleNumber(b) << endl;
    //         int n = 29 ;
    //    if( primeNumber(n)){
    //     cout << "prime number" << endl;
    //    }
    //    else{
    //     cout << "it's not a prime number" << endl;
    //    }

    // string str = "racecar" ;
    // cout << palindrome(str) << endl;

    //     string s = "hello";
    //     cout << ReverseString(s) << endl;

    //     string s1 = "hello";
    //     cout << ReverseString(s1) << endl;

    //     vector<int> arr = {2, 5, 1, 7, 3};
    //     cout << maximumNumber(arr) << endl;

    //     vector<int> nums= {0, 1, 0, 3, 12};

    //   vector<int> ans = MoveZero(nums);
    //     for (auto &it : ans) {
    //         cout << it << " ";
    //     }
    //     cout << '\n';

    //     vector<int> a = {2, 5, 0, 1,0,  7, 3 , 9, 0, 0, 0, 8};
    //   vector<int> res = moveZero(a);
    //     for (auto &it : res) {
    //         cout << it << " ";
    //     }
    //     cout << '\n';

    // vector<int> num = {1,1,0,1,1,1} ;
    // cout << findMaxConsecutiveOnes(num) << endl;
    return 0;
}