#include <iostream>
#include <unordered_set>
#include <string> 
using namespace std;
// A. Boy or Girl
string cntDistinct(string str)
{
    unordered_set<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        s.insert(str[i]);
    }
    return s.size() % 2  == 0 ? "CHAT WITH HER!" : "IGNORE HIM!";
}

int main()
{
string str; 
cin >> str; 

cout << cntDistinct(str)  << endl;
    return 0;
}