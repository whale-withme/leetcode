#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, maxnum = 0, target = 0;
        // 计算和
        for(int it : nums){
            sum += it;
            maxnum = max(it, maxnum);
        }
        target = sum/2;

        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        if((sum % 2) || (maxnum > sum/2))
            return false;

        for(int i = 0; i < nums.size(); i++)
            dp[i][0] = true;
        dp[0][nums[0]] = true;
        
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j <= target; j++){
                if(nums[i] > j)
                    dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = dp[i-1][j-nums[i]] || dp[i-1][j];
                }
            }
        }
        return dp[nums.size()-1][target];
    }
};