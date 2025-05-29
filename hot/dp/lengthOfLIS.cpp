#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1);
        dp[0] = INT_MIN;
        int size = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > dp[size])
                dp[++size] = nums[i];
            else{
                int cnt = size;
                while(cnt > 0 && nums[i] <= dp[cnt])
                    cnt--;
                dp[cnt+1] = nums[i];
            }
        }

        return size;
    }
};