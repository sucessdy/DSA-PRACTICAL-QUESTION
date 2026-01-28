#include <iostream>
#include <vector>

using namespace std;
bool checkPalindrome(int st, int end, string &s)
{
    if (st > end) return true; 
     if (s[st] == s[end]) {
        return checkPalindrome(st + 1, end-1, s); 
     }
     return false; 
}
int countSubstrings(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i ; j < s.length(); j++)
        {
           
             if (checkPalindrome(i , j, s)
                  ) {
                    cnt++ ; 
                  }

            // if ( i >=0 && j < s.length( ) &&  s[i] == s[j])
            // {  
                 
                
          
               
            // } 
    

           

            
        }
    }
    return cnt; 
}
int main() {
    string s ="fdsklf" ; 

    cout << countSubstrings(s) << endl; 
}