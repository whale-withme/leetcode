#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < 2 * n - 1; i++){
            int l = i / 2, r = l + i % 2;
            while(l >= 0 && r < n && s[l] == s[r]){
                ans++;
                l--;
                r++;
            }
        }
        return ans; 
    }
};