// LIST   =======  

#include <iostream> 
#include <vector> 
#include <list> 
#include <deque> 

using namespace std ;

int main() {

list <int> l;


l.push_back(1); 
l.push_back(2); 
l.push_back(3);
l.push_front(4) ; 

for (auto i  : l) { 
    cout << i << " ";

}
cout << endl;

/// DEQue = dyanmic array ==we can access the element from there index where
// int the  List = Doubly linked list ... we can't access the randome value or element 



deque <int> d;

d.push_back(1); 
d.push_back(2); 
d.push_back(3);
d.push_front(4) ; 

for (auto i  : d) { 
    cout << i << " ";

}
cout << endl;

    return 0;
}
