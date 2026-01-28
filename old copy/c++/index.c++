#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class List
{
private:
  

public:
 
    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *prev = nullptr;
        Node *next = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next; 
        }

        return prev;
    }

  void print(Node * head)
    {

        while (head != nullptr)
        {
            cout << head->data << "->";
            head= head->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    List ll;
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "reverse: ";
   Node * reverseList =  ll.reverse(head);
    ll.print(reverseList);

    return 0;
}