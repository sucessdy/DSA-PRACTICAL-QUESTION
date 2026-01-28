#include <iostream>
#include <vector>
using namespace std;

// void digits(int n)
// {
//     int count = 0 ;
//     while (n != 0)
//     {
//         int dig = n % 10;
//     count ++  ;
//         n = n / 10;
//     }
//          cout << count << endl;
// }

// sum

void digits(int n)
{  
    int sum = 0;
    while (n != 0) {   
        int dig = n % 10;
        sum += dig; 
        n = n / 10; 
    }  
    cout << sum << endl;
}


 int sumFourDivisors(vector<int>& nums) {
        
    }

bool armStrong(int n)
{
    int copyN = n;
    int sumofCube = 0; 
    while (n != 0)
    {
        int dig = n % 10;
        sumofCube += (dig * dig * dig);
        n = n / 10;
    } 
    return sumofCube == copyN;
}

int gcdEuclid(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)

            a = a % b;
        else
        {
            b = b % a;
        }
    }
    if (a == 0)
        return b;
    return a;
}
int gcdRecursion(int a, int b)
{

    if (b == 0)
        return a;
    return gcdEuclid(b, a % b);
}

int lcm(int a, int b)
{

    int gcd = gcdRecursion(a, b);
    return a * b / gcd;
}

int reverse(int x)
{
    int reverseInt = 0;
    while (x != 0)
    {
        int dig = x % 10;

        if (reverseInt > INT_MAX || reverseInt < INT_MIN)
            return 0;
        reverseInt = reverseInt * 10 + dig;

        x = x / 10; // chota
    }

    return reverseInt;
}

bool palindromeNumber(int x)
{
    if (x < 0)
        return false;
    int revNum = reverse(x);
    return x == revNum;
}


int fib( int n) { 
if ( n == 0) return 0; 
if (n == 1) return 1; 
    return fib ( n -1) + fib(n - 2) ; 
     
}
int main()
{
    int n =  6; 
  cout <<   fib (n) << endl; 
  
     int nnums = 24;
    digits(nnums);

    // int n = 153;

    // if (armStrong(n))
    // {
    //     cout << "it's A ARMSTRONG NUMBER" << endl;
    // }
    // else
    // {

    //     cout << "NOT  A ARMSTRONG NUMBER" << endl;
    // }

    // cout << gcdEuclid(20, 28) << endl; 
    // cout << gcdRecursion(6, 12) << endl; 
    // cout << lcm(20, 24) << endl; 
    // cout << reverse(789) << endl; 

    // cout << palindromeNumber(1009) << endl; 
    return 0;
}