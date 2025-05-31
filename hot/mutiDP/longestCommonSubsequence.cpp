#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        int lcs = 0;
        int dp[1010][1010];
        // if(text1[0] == text2[0])    dp[0][0] = 1;
        // else    dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    // lcs = max(lcs, dp[i][j]);
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                lcs = max(lcs, dp[i][j]);
            }
        }
        return lcs;
    }
};

int main(){
    string s1 = "abcde", s2 = "ace";
    Solution so;
    int n = so.longestCommonSubsequence(s1, s2);
}