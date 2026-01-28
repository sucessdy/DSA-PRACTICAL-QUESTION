#include <stdio.h> 

#define  MAX_SIZE 5
int queue[MAX_SIZE] ; 
int front = -1; 
int rear = -1; 

void enqueue (int x) { 
    if (rear  == MAX_SIZE -1 ) { 
        printf("queue overfflow") ;
        return ; 
    }
    front = 0; 
    queue[++rear] = x; 
}
void dequeue(){
    if (front == -1 || front > rear){ 
        printf("underflow"); 
        return; 
    }
   printf("Deleted: %d\n", queue[front++]);

}

void print() { 
    if (front == -1 || front > rear ){ 
        printf("empty") ;
        return;
    }
    for (int i = front ; i <= rear ; i ++){ 
        printf( "%d ",  queue[i]) ; 

        printf("\n");
    }
}

int main (){
     
    enqueue(1);
    enqueue(2);
    enqueue(3); 
    dequeue(); 
    print() ; 
}