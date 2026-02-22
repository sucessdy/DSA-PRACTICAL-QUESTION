// string =======

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string> 
using namespace std ; 

void rearrangeAdjecntDuplicates(string& s) { 
    if (s.length() == 0) return; 
for (int i = 0; i < s.length() ; i++) { 
    if (s[i] < s[i+1]){
        swap(s[i] , s[i+1]) ; 
    }

    else { 
 
   cout << " " << endl; 
    }
}
}




class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int n = s2.size();
        if(k > n){
            return false;
        }
        int hashs1[26] = {0};
        for(int i = 0; i<k; i++){
            hashs1[s1[i] - 'a']++;
        }
        int hashs2[26] = {0};
        int i = 0, j = i+k-1;
        for(int it = 0 ; it <= j; it++){
            hashs2[s2[it] - 'a']++;
        }
        while(j< n){
            for(int it = i; it<=j; it++){
                if(hashs1[s2[it] - 'a'] != hashs2[s2[it] - 'a']) break;
                else if(it == j && hashs1[s2[it] - 'a'] == hashs2[s2[it] - 'a']){
                    return true;
                }
            }
            hashs2[s2[i] - 'a']--;
            i++;
            j++;
            if(j==n) continue;
            hashs2[s2[j] - 'a']++;
        }
        return false;
    }
};


    bool freqSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if ( freq1[i] != freq2[i]){
                return false; 
            }
        }
        return true; 

    }

    bool checkInclusion(string s1, string s2) {

        int freq[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }
        int freqSize = s1.length();

        for (int i = 0; i < s2.length(); i++) {
            int windowSize = 0;
            int idx = i;
            int windFreq[26] = {0};

            while (windowSize < freqSize && idx < s2.length()) {
                windFreq[s2[idx] - 'a']++;
                windowSize++;
                idx++;
            }

            if (freqSame(freq, windFreq)) {
                return true;
            }
        }
        return false;
    }



int main () {
    string s1 = "ab" ; 

    string s2 = "eidboaoo" ; 
bool res = checkInclusion(s1, s2); 


cout <<( res ? "true" : "false") << endl;  



    return 0; 
}

