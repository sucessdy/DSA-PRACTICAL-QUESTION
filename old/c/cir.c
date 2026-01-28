#include <stdio.h> 

#define  MAX_SIZE 5
int cq[MAX_SIZE] ; 
int front = -1; 
int rear = -1; 
int empty (){ 
    return front == -1; 

}
int full () {
    return (rear + 1) % MAX_SIZE == front; 
}
 
void enqueue (int x) { 
 if (full()){ 
    printf("Queue Full\n");
  return; 
 }
 if (empty()){ 
    front = 0; 
 }

 rear = (rear  + 1 )%  MAX_SIZE ; 
cq[rear] = x; 

}


void dequeue(){
  if (empty() ) {
    printf("empty"); 
    return ;
  }  
  if (front == rear) {
    front = rear = -1; 
  }else { 
    front = (front + 1) % MAX_SIZE ; 
  } 

}
int peek(){ 
    if (empty()){ 
        printf("empty"); 
        return  -1; 
    }

    return cq[front]; 

}

void display() {
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }
    int i = front;
    while (i != rear) {
        printf("%d ", cq[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", cq[rear]);
}
int main (){
     
    enqueue(1);
    enqueue(2);
    enqueue(3); 
    dequeue(); 

 display(); 
}