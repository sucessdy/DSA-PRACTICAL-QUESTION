#include <stdio.h>
#include <stdlib.h>
// circular linked list
struct Node
{

    int data;

    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;
struct Node *tail = NULL;
void insertAtHead(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->next = NULL;
    if (tail == NULL)
    {
        head = tail = newNode;
        tail->next = head; // tail ->next = head or tail->next
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("%d \n", temp->data);
}

void insertAtTail(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = tail = newNode;
        tail->next = head;
    }
    else
    {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}
void deleteAtfront()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        return;
    }
    if (head == tail)
    {
        free(head);
        head = tail = NULL;
    }
    
    head = head->next;
    tail->next = head;
    temp->next = NULL;
    free(temp);
}
int main()
{
    insertAtHead(1);
    insertAtHead(2);
    insertAtHead(3);
    insertAtHead(4);
    insertAtTail(5);
    deleteAtfront();
    display();
    return 0;
}