#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

void LeftRotate(vector<int> &arr)
{
    int temp = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[arr.size() - 1] = temp;
}

void LeftrotateOptimal(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    //  vector<int> temp(nums.begin(), nums.begin() + k) ;
    int temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i] = nums[i];
    }
    // shifting
    for (int i = k; i < n; i++)
    {
        nums[i - k] = nums[i];
    }

    // push back temp
    for (int i = n - k; i < n; i++)
    {
        nums[i] = temp[i - (n - k)];
    }
}

void RightrotateOptimal(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n; // handle cases where k > n
    vector<int> temp(n);
    // store the array temp
    for (int i = 0; i < k; i++)
    {
        temp[i] = nums[n - k + i];
    }
    // shifting
    for (int i = n - k - 1; i >= 0; i--)
    {
        nums[i + k] = nums[i];
    }

    for (int i = 0; i < k; i++)
    {
        nums[i] = temp[i];
    }
}

void reverseArray(vector<int> &arr)
{
    int reverse = 0;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseArrayInplace(vector<int> &arr)
{
    int st = 0;
    int end = arr.size() - 1;
    while (st < end)
    {
        swap(arr[st], arr[end]);
        st++;
        end--;
    }
}

string reverseInString(string str)
{
    reverse(str.begin(), str.end());
}

bool isAlphanumeric(char ch) {
    return ((ch >= '0' && ch <= '9') || 
            (ch >= 'a' && ch <= 'z') || 
            (ch >= 'A' && ch <= 'Z'));
}
bool isPalindrome(string 
    s) {
    int st = 0;
    int end = s.size() - 1;

    while (st < end) {
        if (!isAlphanumeric(s[st])) {
            st++;
            continue;
        }
        if (!isAlphanumeric(s[end])) {
            end--;
            continue;
        }

        if (tolower(s[st]) != tolower(s[end])) {
            return false;
        }

        st++;
        end--;
    }
    return true;
}


int main()
{

    string s = "A man, a plan, a canal: Panama";
    bool res = isPalindrome(s);
    cout << (res ? "Palindrome" : "Not Palindrome") << endl;

    //   string str = "hello world this is dsa";

    // str = reverseInString(str);

    // for (char i : str)
    // {
    //     cout << i;
    // }
    // cout << endl;

    // vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    // int st = 2;
    // int end = 5;
    //  for (auto i : arr)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;

    // for (auto i : arr)
    // {
    //     cout << i << ' ';
    // }
    // cout << endl;
    return 0;
}