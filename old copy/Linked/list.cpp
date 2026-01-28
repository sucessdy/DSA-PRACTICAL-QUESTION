
#include <iostream>
#include <vector>


using namespace std;

class Node {
    private :  
    int data; 
    Node *prev; 
    Node *next ; 
    Node (int val){
        data =val; 
        prev = next = NULL ; 
    }
} ; 
class DoublyLinkedList{
Node *head  ;
Node *tail ; 

DoublyLinkedList() {
    
}
  
} ; 
int main() { 

    return 0; 
}