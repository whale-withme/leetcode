#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() < 2)  return s;
        int len = s.length();
        int maxlen = 1, begin = 0;
        bool dp[len+1][len+1];

        for(int i = 0; i < len; i++)
            dp[i][i] = true;
        
        for(int L = 2; L <= len; L++){
            for(int i = 0; i < len; i++){
                int j = i + L -1;

                if(j >= len)
                    break;
                if(s[i] == s[j]){
                    if(j - i < 3)   dp[i][j] = true;
                    else    dp[i][j] = dp[i+1][j-1];
                }else{
                    dp[i][j] = false;
                }

                if(dp[i][j]){
                    maxlen = max(maxlen, j-i+1);
                    begin = i;
                }    
            }
        }
        return s.substr(begin, maxlen);        
    }
};