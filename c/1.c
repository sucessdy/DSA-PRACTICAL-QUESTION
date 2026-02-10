#include <stdio.h>
#include <string.h>
#include <ctype.h>


// factorial 
int RecursionFactorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    return n * RecursionFactorial(n - 1);
}


// int vowel(char c){ 

// }
int main()
{
    // int n;
    // printf("Enter a number : ");
    // scanf("%d", &n);
    // printf("Factorial is:%d ", RecursionFactorial(n)) ; 


    // now, its count the no. of vowels in a given string
    char str[100] ; 
int count = 0; 
int i; 
printf("enter a number : ") ; 
fgets(str, sizeof(str), stdin) ; 
printf("vowel in the string: ") ; 


for (int i = 0 ; str[i] != '\n' ; i++ ) { 
    char ch = str[i] ; 
    if (ch == 'a'  || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A'  || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
        printf("%c", ch) ; 
count++; 
    }

}

printf("\nTotal number of vowels = %d\n", count); 

    return 0;
}