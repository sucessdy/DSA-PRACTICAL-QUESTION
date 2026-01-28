#include <iostream>
#include <vector>
#include <set>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
size_t n1 = nums1.size();
size_t n2 = nums2.size();
vector<int> nums3;
size_t i = 0;
size_t j = 0;
while (i < n1 && j < n2) {
    if (nums1[i] < nums2[j]) {
        nums3.push_back(nums1[i++]);
    } else {
        nums3.push_back(nums2[j++]);
    }
}

while (i < n1) {
    nums3.push_back(nums1[i++]);
}
while (j < n2) {
    nums3.push_back(nums2[j++]);
}

size_t n = nums3.size();
if (n == 0) return 0.0;
if (n % 2 == 1) {
    return static_cast<double>(nums3[n / 2]);
}
return (static_cast<double>(nums3[n / 2 - 1]) + static_cast<double>(nums3[n / 2])) / 2.0;
}
int main() {
vector<int> a = {1, 3, 4} ; 
vector<int> b = {5 } ;
cout <<  findMedianSortedArrays(a,b)  << endl;

return 0; 
}