#include <iostream>
#include <stdexcept>
using namespace std;

#define MAX_SIZE 10

class Stack
{
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int val)
    {
        if (isFull())
        {
            throw overflow_error("Stack Overflow");
        }

        arr[++top] = val;
    }

    int pop()
    {
        if (isEmpty())
        {
            throw underflow_error("Underflow Error");
        }
        return arr[top--];
    }
    void display() { 
        if (isEmpty() ){ 
            throw underflow_error("Stack is empty") ;
        }
        else { 
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            throw runtime_error("Runtime Error");
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return (top == MAX_SIZE - 1);
    }
};

int main()
{
    Stack s;
    try
    {
        s.push(1);
        s.push(2);
        s.push(3);
        // s.pop();
        cout << "Top element" << s.peek() << endl;
        s.pop();
        cout << "Top element" << s.peek() << endl;
        cout << "Stack is empty : " << (s.isEmpty() ? "Yes" : "No") << endl;
        /* code */
        cout <<  "Display the whole stack:" << endl;
        s.display();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
