#include <iostream>
#include <vector>

using namespace std;
class Stack
{
    vector<int> v;

public:
    void push(int val)
    {
        v.push_back(val);
    }

    void pop()
    {
        v.pop_back();
    }

    int top()
    {
        return v[v.size() - 1];
    }
    bool empty()
    {
        return v.size() == 0;
    }
};
int main()
{
    Stack s;
    s.push(90);
    s.push(80);
    s.push(70);
    s.push(60);
    s.pop();
    s.push(50);
    s.push(40);
    s.empty();
    
    return 0;
}