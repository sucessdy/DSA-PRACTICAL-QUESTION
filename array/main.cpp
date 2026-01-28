#include <iostream>
#include <cctype>
using namespace std;

bool isAlphanumeric(char ch)
{
    return ((ch >= '0' && ch <= '9') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z'));
}

bool isPalindrome(string s)
{
    int st = 0;
    int end = s.size() - 1;

    while (st < end)
    {
        if (!isAlphanumeric(s[st]))
        {
            st++;
            continue;
        }
        if (!isAlphanumeric(s[end]))
        {
            end--;
            continue;
        }

        if (tolower(s[st]) != tolower(s[end]))
        {
            return false;
        }

        st++;
        end--;
    }
    return true;
}

bool isPalidromeBruteForce(string s)
{
    string str = "";
    for (auto ch : s)
    {
        if (isalnum(ch))
        {
            str += tolower(ch);
        }
    }

    string rev = s;

    reverse(rev.begin(), rev.end());
    return str == rev;
}

string removeOccurrences(string s, string part)
{
   while(s.length() >  0 && s.find(part)  < s.length()){
s.erase(s.find(part) , part.length()) ; 
   }
   return s; 
}
int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";

    string res = removeOccurrences(s, part);
    cout << "Result after removing occurrences: " << res << endl;
    return 0;
}
