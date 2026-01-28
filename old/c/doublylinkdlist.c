#include <stdio.h>
#include <stdlib.h>

struct Node
{

    int data;

    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertAtBeginning(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {

        printf("%d<=> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtEnd(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->next = NULL;

    newNode->prev = NULL;

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void pop_front()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("list is empty");
        return;
    }

    if (head == tail)
    {
        head = tail = NULL;
        free(temp);
        return;
    }

    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    free(temp);
}

void pop_back()
{
    struct Node *temp = tail;

    if (head == NULL)
    {
        printf("list is empty");
        return;
    }
    if (head == tail)
    {
        head = tail = NULL;
        free(temp);
        return;
    }

    tail = tail->prev;
    tail->next = NULL;
    temp->prev = NULL;
    free(temp);
}
int main()
{
    insertAtBeginning(1);
    insertAtBeginning(2);
    insertAtBeginning(3);

    insertAtEnd(4);

    pop_front();
    pop_back();
    display();
    return 0;
}