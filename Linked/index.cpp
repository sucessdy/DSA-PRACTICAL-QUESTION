
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }
    void pushfront(int val)
    {

        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next; // updation
        }

        cout << "NULL" << endl;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (tail ==
            NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_front()
    {
        Node *temp = head;

        if (head == NULL)
        {
            cout << "list is empty";
        }
        else
        {

            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back()
    {

        if (head == NULL)
        {
            cout << "list is empty";
            return;
        }
        else
        {
            Node *temp = head;

            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
        }
    }

    // alternative

    void pop_backwithNewAlternative()
    {
        if (!head)
            return;
        if (head == tail)
        {
            delete head;
            head = tail = NULL; // where is single case
        }
        else
        {
            Node *prev = head;
            while (prev->next != tail)
            {
                prev = prev->next;
            }
            delete tail;
            tail = prev;
            tail->next = NULL;
        }
    }
    void insertAtmiddle(int val, int pos)
    {
        Node *newNode = new Node(val);
        if (pos < 0)
        {
            cout << "list is empty";
            return;
        };
        if (pos == 0)
        {
            pushfront(val);
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "inValid answer";
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    bool search(int target)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == target)
            {
                return true;
            }
            temp = temp->next; // updating the value
        }
        return false;
    }

    Node *ReverseList(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node *reverseBetween(Node *head, int left, int right)
    {
        if (!head || left == right )
        {
            
            return head;
        }

        
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        for(int i =0 ; i < left ; i++) {
            prev = prev->next;
        }

        for (int i = 0; i < right -left; i++) {
            
        }
           
 
        return prev;
    }
};

int main()
{

    List ll;
    ll.pushfront(1);
    ll.pushfront(2);
    ll.pushfront(3);
    ll.insertAtmiddle(4, 0);
    ll.push_back(5);
    ll.pop_front();

    // ll.printList();
    // // ll.pop_back() ;
    // // ll.pop_backwithNewAlternative();
    // if (ll.search(5)){
    //     cout << "Present in the LinkedList" ;
    // }
    // else {
    //     cout << "invalid answer" ;
    // }
    cout << endl;
    // ll.search(1) ;
    ll.printList();
    Node *head = new Node(1);
    head->next = new Node(2);

    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Revserse \n";

    Node *newHead = ll.reverseBetween(head, 2, 4);
    Node *temp = newHead;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}