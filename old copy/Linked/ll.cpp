#include <iostream>
#include <vector>

using namespace std;

class Node { 
public: 
int data ; 
Node * prev ; 
Node * next ; 
Node (int val) { 
    data = val ; 
    prev = next = NULL ;
}
} ; 


class DoublyLinkedList{

    Node *head ; 
    Node *tail ; 
    public: 
DoublyLinkedList() { 
    head = tail = NULL; 
}


} ; 
int main () { 
    return 0; 
}