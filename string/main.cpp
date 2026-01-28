#include <iostream>
#include <vector>
using namespace std;

bool Palindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

string palindromeSubstring(string s)
{
    string res = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s.length() == 1)
            return string(1, s[0]);
        for (int j = i + 1; j < s.length(); j++)
        {
            if (Palindrome(s, i, j))
            {
                string curr = s.substr(i, j - i + 1);
                if (curr.length() > res.length())
                {
                    res = curr;
                }
            }
            // res = max(res, cnt) ;
        }
    }
    return res;
}
int main()
{
    string s = "ac";
    cout << palindromeSubstring(s) << endl;
    return 0;
}