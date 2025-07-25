#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        if(m > n)       return false;
        unordered_map<char, int> map, window;
        
        for(int i = 0; i < m; i++){
            map[s1[i]]++;
            window[s2[i]]++;
        }
        if(map == window)
            return true;

        for(int i = 0; i < n-m; i++){
            window[s2[i]]--;
            if(window[s2[i]] == 0)
                window.erase(s2[i]);
            window[s2[i + m]]++;
            if(window == map)
                return true;
        }
        return false;
    }
};