#include <bits/stdc++.h>
using namespace std;


class Solution {
private:

    unordered_map<char, int> model, window;


public:
    string minWindow(string s, string t) {
        int left = 0, start = 0, minlen = INT_MAX;

        for(char ch : t){
            model[ch]++;
        }

        for(int right = 0; right < s.length(); right++){
            window[s[right]]++;

            while(check()){
                start = right - left + 1 < minlen ? left : start;
                minlen = min(minlen, right - left + 1);
                window[s[left]]--;
                left++;
            }
        }

        return minlen == INT_MAX ? "" : s.substr(start, minlen);
    }

    bool check(){
        for(auto& kv: model){
            if(window.find(kv.first) == window.end() || window[kv.first] < kv.second)
                return false;
        }
        return true;
    }
};