#include <iostream>
#include <queue>
using namespace std;
// data started = 19 / aug / 2025   
// Queue  is FIFO -> first in first out
// front = head-> data
// push = insert data  at the tail
// pop = delete data at the head

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{

    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = tail = NULL;
    }
    void push(int data)
    { // insert data at the tail
        Node *newNode = new Node(data);

        if (empty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop()
    {
        if (empty()) { cout << "List is empty\n" ;   }
        else { 
            Node *temp = head ; 

            head = head->next ;

         

            delete temp;  
        
        }
    }

    int front()
    { if (empty()) { cout << "List is empty\n" ;
         return -1;
           } 
        return head->data;
    }

    bool empty()
    {
        return head == NULL;
    }
};
int main()
{

    // Queue q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // while(!q.empty() ) {
    //    cout << q.front()  << " "; 
    //     q.pop() ; 
    // }
    // cout << endl; 

    //  WITH STL ========= FROM NOW ON 

    // queue<int> q;
    

    // NOW DEQUE  = double ended queue
    // is where we can perform  double deque = pop -> front , back ... push -> back , front ... front , back  

    deque<int> dq; 
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    dq.push_front(4);
    cout << dq.front() << " " << dq.back() << endl ; 
    dq.pop_back() ;

    cout << dq.front() << " " << dq.back() << endl ; 



    return 0;
}