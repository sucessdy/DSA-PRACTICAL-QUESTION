#include <stdio.h>


int gcd(int a , int b){

    while(b!= 0) 
    { 
        int r ;
        r= a%b; 
        a=b; 
        b= r; 

    }
    return a; 

}

struct node 
{
    /* data */
    int coef ; 
    int exp ; 
    struct node * next; 

};

struct node*createPloy(int a, int b, int c, int d){
    struct node *n1, *n2, *n3, *n4  ; 
    n1 = (struct node*)malloc(sizeof(struct node)) ;
    n2 = (struct node*)malloc(sizeof(struct node)) ;
    n3 = (struct node*)malloc(sizeof(struct node)) ;
    n4 = (struct node*)malloc(sizeof(struct node)) ;

    n1->coef = a; n1->exp = 3 ;n1->next= n2;
    n2->coef = b ; n2->exp = 2 ; n2->next = n3;
    n3->coef = c ; n3 ->exp = 1; n3->next = n4; 
    n4->coef = d; n4->exp = 0; n4->next = NULL; 
    return n1; 

}

int main() { 
    int x, y;

    printf("Enter two positive integers: ");
    scanf("%d %d", &x, &y);

    printf("GCD = %d\n", gcd(x, y));

    return 0; 
}