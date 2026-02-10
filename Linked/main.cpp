
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

    // int getSizeOfLinkedList(Node *head)
    // {

    //     if (head == NULL)
    //     {
    //         return 0;
    //     }
    //     return 1 + getSizeOfLinkedList(head->next);
    // }

    int sizeOfLinkedList( Node *head)
    {
        int cnt = 0;
        Node *curr = head;
        while (curr != nullptr)
        {
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }

    // Node *middle(Node *head)
    // {
    //     if (head== NULL) {

    //     }
    //     Node *curr = head;
    //     int cnt = 0;
    //     while (curr != NULL)
    //     {
    //         cnt++;
    //         curr = curr->next;
    //     }
    //     curr = head;

    //     for (int i = 0; i < cnt / 2; i++)
    //     {
    //         curr = curr->next;
    //     }

    // }

    Node *middleList(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void printList(Node *head)
    {

        while (head != NULL)
        {
            cout << head->data << "->";
            head = head->next;
        }

        cout << "NULL" << endl;
    }
    bool DetectACyle(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};
int main()
{
    List ll;

    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    cout << "Detect: " << " ";
    ll.DetectACyle(head);
    ll.printList(head);

 Node *res =   ll.middleList(head) ;
 ll.printList(res) ;  
    // ll.getSizeOfLinkedList(head) ;

    // cout << "Count of nodes is " << ll.getSizeOfLinkedList(head);

cout << "cnt : " << ll.sizeOfLinkedList(head) ; 
    return 0;
}