#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

int full()
{ 
    
    return ((rear + 1) % MAX_SIZE == front);
}

int empty()
{
    return (front == -1);
}

void enqueue(int data)
{
    if (full())
    {
        printf("Queue overflow\n");
        return;
    }

    if (empty())
        front = 0;

    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;

    printf("Inserted %d\n", data);
}

int dequeue()
{
    if (empty())
    {
        printf("Queue is empty\n");
        return -1;
    }

    int data = queue[front];

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;

    return data;
}

void display()
{
    if (empty())
    {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("Dequeued: %d\n", dequeue());

    display();

    return 0;
}
