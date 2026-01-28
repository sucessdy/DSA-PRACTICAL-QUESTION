#include <iostream> 
using namespace std; 
void ToolongWord( string s ) { 

    if (s.length() > 10){ 
        cout << s[0] << s.length() -2 << s[s.length() -1] << endl ; 
    }
    else { 

        cout <<  s << endl; 
    }


}


int main (){
    string s = "locaization";
 ToolongWord( s) ; 
return 0; 
}