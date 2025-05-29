#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1);
        unordered_set<string> set;
        for(string tmp : wordDict)
            set.insert(tmp);
        dp[0] = true;

        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                string tmp = s.substr(j, i-j);

                for(string str: set){
                    if(str == tmp && dp[j] == true)
                        dp[i] = true;
                }
            }
        }
        return dp[s.length()];
    }
};