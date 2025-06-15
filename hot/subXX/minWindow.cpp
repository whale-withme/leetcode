#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    unordered_map<char, int> cnt, fixed;

    string minWindow(string s, string t) {
        int l = 0, r = 0, len = INT_MAX;
        int ans = -1;

        for(auto ch : t)
            fixed[ch]++;
            
        while(r < s.size()){
            cnt[s[r]]++;

            while(check() && l <= r){
                if(r-l+1 < len){
                    len = r - l + 1;
                    ans = l;
                }

                cnt[s[l]]--;
                l++;
            }
            r++;
        }
        return ans == -1 ? "" : s.substr(ans, len);
    }

private:

    bool check(){
        for(auto p : fixed){
            if(cnt[p.first] < p.second)
                return false;
        }
        return true;
    }
};