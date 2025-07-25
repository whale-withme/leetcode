#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = -1, left = 0;
        unordered_map<char, int> map;

        for(int i = 0; i < s.length(); i++){
            if(map.find(s[i]) != map.end()){
               left = max(left, map[s[i]]) + 1; 
            }
            map[s[i]] = i;
            maxLen = max(maxLen, i - left + 1);
        }

        return maxLen;
    }
};

int main(){
    Solution so;
    cout << so.lengthOfLongestSubstring("tmmzuxt");
}