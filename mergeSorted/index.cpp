#include <iostream>
#include <vector>
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

class SinglyLinkedList
{
    Node *head;
    Node *tail;

public:
    SinglyLinkedList()
    {
        head = tail = NULL;
    }

    // Node *middleList(Node *head)
    // {
    //     Node *fast = head;
    //     Node *slow = head;
    //     while (fast && fast->next && fast->next->next)
    //     {
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }
    //     return slow;
    // }

    // Node *SortedList(Node *head)
    // {
    //     if (!head || !head->next)
    //     {
    //         return head;
    //     }
    //     Node *mid = middleList(head);
    //     Node *right = mid->next;
    //     mid->next = NULL;

    //     Node *left = SortedList(head);
    //     right = SortedList(right);

    //     return mergeTwo(left, right);
    // };

    Node *mergeTwo(Node *l1, Node *l2)
    {
        Node dummy(-1);
        Node *curr = &dummy;
        while (l1 != nullptr && l2 != nullptr)
        {

            if (l1->data < l2->data)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
                ;
            }
            curr = curr->next;
        }

        curr->next = l1 ? l1 : l2;
        return dummy.next;
    }

    Node *merge(int i, int j, vector<Node *> &head)
    {

        if (i == j)
            return head[i];
        int mid = i + (j - i) / 2;
        Node *head1 = merge(i, mid, head);
        Node *head2 = merge(mid + 1, j, head);
        cout << "Merging range: " << i << " to " << j << endl;
        Node *h = mergeTwo(head1, head2);

        return h;
    }

    Node *mergeKLists(vector<Node *> &head)
    {
        if (head.size() == 0)
            return nullptr;

        return merge(0, head.size() - 1, head);
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
};
int main()
{
    SinglyLinkedList sl;

    vector<Node *> arr(3);

    // List 1: 1 -> 4 -> 5
    arr[0] = new Node(1);
    arr[0]->next = new Node(4);
    arr[0]->next->next = new Node(5);

    // List 2: 1 -> 3 -> 4
    arr[1] = new Node(1);
    arr[1]->next = new Node(3);
    arr[1]->next->next = new Node(4);

    // List 3: 2 -> 6
    arr[2] = new Node(2);
    arr[2]->next = new Node(6);

    Node *head = sl.mergeKLists(arr);

    sl.printList(head);
    return 0;
}
