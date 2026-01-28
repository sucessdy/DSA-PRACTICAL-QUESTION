#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{

    // defautl -> descending order -> high priority
    priority_queue<int> pq;
    pq.push(10);
    pq.push(2);
    pq.push(3);
    pq.push(8);

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // ascending order -> where we use compareter ... like greater funtor -> function object
    priority_queue<int, vector<int>, greater<int>> p;
    p.push(10);
    p.push(2);
    p.push(3);
    p.push(8);

    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }

    cout << endl;
    return 0;
}