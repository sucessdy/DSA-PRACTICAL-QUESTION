#include <iostream> 
#include <vector>
#include <stack> 

using namespace std ; 

int main() {
pair<int, pair<char, int>> p = {1, {'a', 4}};

// cout << p.first << endl;
// cout << p.second.first << endl;
// cout << p.second.second << endl;

// vector<pair<int, int>> vec = {{1,2}, {3, 4}, {5, 6}};
// vec.push_back({7, 8});
// vec.emplace_back(9,0); // in place  object create at the time of insertion 
// for (pair<int, int> p : vec )  {
//     cout << p.first << " " << p.second << endl ;

// }


stack<int> s; 
s.push(1);
s.push(2);
s.top() ; 
stack<int> s2; 

while(!s.empty()) {
    cout << s.top() << " "; 
s.pop() ; 

}
cout << endl ; 

s2.swap(s);
cout << "s : size  = "  << s.size() << endl ; 
cout << "s2 : size = " << s2.size() << endl ; 




    return 0 ;
}