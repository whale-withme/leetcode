#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> model, window;
        for(int i = 0; i < s.length(); i++){
            model[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }

        if(model == window) ans.push_back(0);

        for(int i = 0; i < p.length() - s.length(); i++){
            window[s[i] - 'a']--;
            if(window[s[i] - 'a'] == 0)
                window.erase(s[i] - 'a');

            window[s[i + p.length()] - 'a']++;
            if(window == model)
                ans.push_back(i+1);
        }
        return ans;
    }
};