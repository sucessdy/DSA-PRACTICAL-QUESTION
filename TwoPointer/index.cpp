#include <iostream>
#include <vector>
using namespace std;

// int maxArea(vector<int> &height)
// {
//     int n = height.size();
//     int maxWater = 0;
//     for (int i = 0; i <  n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             int w = j - i;
//             int h = min(height[i], height[j]);
//             int area = w * h;
//             maxWater = max(maxWater , area);
//         }
//     }
//     return maxWater;
// }

int maxArea(vector<int> &height)
{
    int n = height.size();
    int maxWater = height[0];
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            int h = min(height[i], height[j]);

            int w = j - i;

            int trap = w * h;
            maxWater = max(maxWater, trap);
        }
    }
    return maxWater;
}

int maxAreaOptimal(vector<int> height)
{

    int maxWater = 0;

    int st = 0;
    int end = height.size() - 1;
    while (st < end)
    {
        int w = end - st;
        int h = min(height[st], height[end]);
        int currArea = w * h;
        maxWater = max(maxWater, currArea);
        height[st] < height[end] ? st++ : end--;
    }
    return maxWater;
}
int maxWaterContainer(vector<int> &height)
{

    int maxWater = 0;

    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            int w = j - i;
            int h = min(height[i], height[j]);
            int currArea = w * h;
            maxWater = max(maxWater, currArea);
        }
    }
    return maxWater;
}

int tappingRainWater(vector<int> &height)
{
  int res = 0;
  for (int i = 0; i < height.size() ; i++) {
    int left = height[i] ; 
    for (int j  = 0; j < i ; j++ ) { 
        left = max(left, height[j]) ;

    }

    int right = height[i] ; 
    for (int j = i+ 1; j <  height.size( ) ; j++) { 
        right = max(right, height[j]) ;
    }

    res += min(left, right ) - height[i] ; 

  }

  return res; 
} 

// PrefixSum 
int TappingRainWaterwithBetter ( vector<int> & height) {
    int n = height.size() ;
int res =0; 
    vector<int>  lmax(n , 0) ;
    vector<int>  rmax(n , 0) ;
    lmax[0] = height[0 ];
    rmax[n-1] = height[n-1] ;

    for (int  i = 1; i < height.size() ;i ++) {
        lmax[i] = max(lmax[i-1] , height[i]) ; 

    }
    for (int i = n -2 ; i >= 0; i --) { 
        rmax[i] = max(rmax[i + 1] , height[i]) ; 
    }
 for (int i = 0; i< n ;i++) {
    res+=( min(lmax[i], rmax[i] ) -height[i]) ; 
 }

 return res; 
}
int main()
{ 
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << TappingRainWaterwithBetter(height) << endl;
    return 0;
}