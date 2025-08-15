#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        vector<int> dp(nums.size());

        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                dp[i] = nums[i];
                ans = max(ans, dp[i]);
                continue;
            }
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};