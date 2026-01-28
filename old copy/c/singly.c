#include <stdio.h>
#include <stdlib.h>
// signly linkedlist
struct Node
{
    /* data */
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
void push_front(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

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

void PrintList()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void push_back(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
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
    if (head == NULL)
    {
        printf("list is empty");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);
}

int search(int target)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == target)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void pop_back()
{
    if (head == NULL)
    {
        return;
    }
    struct Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }

    temp->next = NULL;
    free(tail);
    tail = temp;
}



void insertAtMiddle(int val, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (pos < 0)
    {
        printf("list is empty");
        return;
    }
    if (pos == 0)
    {
        push_front(val);
        return;
    }
    struct Node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int gcd(int a, int b)
{

    while (b != 0)
    {
        int r;
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int factorial(int n)
{
    int f;
    if (n == 1)
        return 1;
    if (n == 0)
        return 1;
    for (int i = 2; i <= n; i++)
    {
        f *= i;
    }
    return f;
}
int main()
{
    int x, y;
    printf("Enter a and b: ");

    scanf("%d %d", &x, &y);
    printf("GCD = %d \n", gcd(x, y));

    push_front(1);
    push_front(2);
    push_back(3);
    pop_front();

    insertAtMiddle(5, 1);

    if (search(5))
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }
    PrintList();

    int n = 6;
    printf("%d", factorial(n));
}