#include <iostream>
using namespace std;

int digit(int n ) { 
int sum = 0, dig ;  
    while (n != 0) { 
  
  dig = n %10; 
  sum += dig*dig *dig; 
  n/=10; 
}
return sum ; 
}
int main() 
{
int num ; 
cout << "enter a number: " ;

cin >> num ; 

if (num == 0){ 
cout << "invalid";
}
else if (num== digit(num)) {
    cout << "its armstrong number" ; 

}
else { 
    cout << "not valid armstrong number " ; 
}



    cout << "Hello, World!";
    return 0;
}