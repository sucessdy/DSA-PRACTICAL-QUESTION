#include <stdio.h>

int main () { 
//     char ch ; 
//     printf("Enter a char : ") ; 
//     scanf("%c" , &ch) ; 
//   printf("ASCII value of %c = %d\n", ch, ch);


// fact of prime number 

int num, i; 
printf("Enter a number: ") ; 
scanf("%d" , &num) ; 
printf("Factors of %d are: ", num) ;

for ( i = 1;  i <= num ;i ++){
    if (num % i==0){
        printf("%d ", i) ; 
    }

}
return 0 ;

}