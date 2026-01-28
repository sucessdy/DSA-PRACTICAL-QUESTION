#include <iostream>
#include <math.h>
#include <algorithm> 
#include <vector>

using namespace std;

int trap(vector<int> &height)
{

    int res = 0 ; 
 
    for (int st = 0; st < height.size(); st++)
    {

       
        for (int end = st + 1 ; end < height.size(); end++)
        {
             int rmax = height[st] ; 
             int lmax = height[end] 
             ;

             for (int i = 0  ; i < height.size() ; i++) {
                
             }
            
int maxleft = *max_element(height.begin(), height.begin() + st + 1);

int maxRight = *max_element(height.begin() + end, height.end());
int area = min(maxleft, maxRight) - height[st];
if (area > 0)
    res += area;
              
               
        }

    }
    return res; 
}

int main()
{
    vector<int> h = {4, 2, 0, 3, 2, 5};
    cout << trap(h) << endl;

    return 0 ; 
}