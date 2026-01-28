#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;

    m.insert({"INDIA", 1002});
    m.emplace("china", 1240);
    m.emplace("US", 30);
    m.emplace("Japan", 12);
    m.emplace("Korea", 98);
    m.emplace("Thailand", 8);

    // for (auto x : m)
    //     cout << x.first << " " << x.second
    //          << endl;

    // // accesss
    // cout << m["INDIA"] << endl;
    // cout << m.at("china") << endl;
    // // updating
    // // if exist  then update ->
    // m.insert({"china", 1223});

    // m["INDIA"] = 1233;

    // m.at("china") = 1232;
    // //
    // cout << m["INDIA"] << endl;
    // cout << m.at("china") << endl;

    /// for finding

    // auto it = m.find("korea") ;  
    // if (it != m.end()){
    //     cout << " we find the answer" ; 
    // }
    // else {
    //     cout << "invalid answer" ;
         
    // }

    //
// iterator 
for (auto i : m) { 
    cout << i.first << " not delete" << i.second << endl; 
}

m.erase(m.begin());
for (auto i : m) { 
    cout << i.first << " delete" << i.second << endl; 
}

    return 0;

}