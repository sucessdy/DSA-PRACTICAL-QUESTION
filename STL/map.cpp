// MAP   =======

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

int main()
{
    // map<string, int> m;
    // m["tv"] = 100;
    // m["laptop"] = 50;
    // m["headphone"] = 100;
    // m["Speaker"] = 50;
    // m["watch"] = 29;

    // m["laptop"] = 90;
    // m.erase("laptop");        // delete the laptop from the map
    // m.insert({"frigde", 99}); // object we need to pass
    // m.emplace("router", 9);   // with out object
    // for (auto p : m)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }

    // cout << "count  of lapton  " << m.count("laptop") << endl;

    // if (m.find("tv") != m.end())
    // {
    //     cout << "found \n";
    // }
    // else
    // {
    //     cout << "not found \n";
    // }

    //  multimaps -> we can storre muliple key in a order ..



//     multimap<string, int> m;
//     m.insert({"tv", 90});
//     m.insert({"headphone", 70});
//     m.insert({"watch", 90});
//     m.insert({"laptop", 20});
//     m.insert({"mobile", 60});
//     m.insert({"mac", 30});
//     m.insert({"usb", 43});  m.insert({"tv", 90 }); 


// for ( auto i : m) { 
//     cout << i.first  << " " << i.second << " " << endl ;  
// }

// unordered map -> no duplication , just randome value...

//  unordered_map<string, int> m;
//     m.insert({"tv", 90});
//     m.insert({"headphone", 70});
//     m.insert({"watch", 90});
//     m.insert({"laptop", 20});
//     m.insert({"mobile", 60});
//     m.insert({"mac", 30});
//     m.insert({"usb", 43});  m.insert({"tv", 90 }); 


// for ( auto i : m) { 
//     cout << i.first  << " " << i.second << " " << endl ;  
// }
// set =====  


 set<int> s;
    s.insert(4);
     s.insert(5); s.insert(2); s.insert(1); s.insert(1); s.insert(4);
      s.insert(3);     s.insert(3);
    
     
cout << " lower bound  : " <<  *(s.lower_bound(0) ) << endl ;
for ( auto i : s) { 
    cout <<  i <<  " "  ; 
}
cout << endl ;  

    return 0;
}