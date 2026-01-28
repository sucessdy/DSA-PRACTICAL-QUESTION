#include <iostream>
#include <vector>
#include <list> 
using namespace std;
class Stack
{

list<int> ll; 
public:
    void push(int val)
    {
        ll.push_back(val);
    }

    void pop()
    {
        ll.pop_front();
    }

    int top()
    {
        return ll.front() ; // head 
    }
    bool empty()
    {
        return ll.size() == 0;
    }
};
int main()
{
    Stack s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
 
    s.push(1);
    s.push(0);
while ( !s.empty()) { 
    cout << s.top() << "" ; 
    s.pop() ; 
}
cout << endl; 

    return 0;
}