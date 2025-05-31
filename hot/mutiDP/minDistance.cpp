#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        // if(n == 0)  return m;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // 如果出现0个字符的情况
        for(int i = 1; i <= n; i++)  dp[i][0] = i;
        for(int i = 1; i <= m; i++)  dp[0][i] = i;

        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = min(dp[i-1][j]+1, min(dp[i-1][j-1]+1, dp[i][j-1]+1));
                }
            }
        }
        return dp[n][m];
    }
};

int main(){
    string w1 = "horse", w2 = "ros";
    Solution so;
    int ans = so.minDistance(w1, w2);
}