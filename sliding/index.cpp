#include <iostream>
#include <vector>
using namespace std;

 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
    for (int i = 0; i <= (int)nums.size() - k; i++) { 
        int maxval = nums[i];
        for (int j = i; j < i + k; j++) { 
            maxval = max(maxval, nums[j]); 
        }
        result.push_back(maxval);
    }
    return result; 
    }


int main () { 

vector<int> ans  = {1,3,-1,-3,5,3,6,7}; 
vector<int>result = maxSlidingWindow(ans, 3) ; 
for (auto i : result) {
    cout << i << " ";  

}
cout <<endl; 

    return 0; 
}