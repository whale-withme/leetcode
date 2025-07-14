#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int sum = 0, n = nums.size();
        int left, right;

        for(left = 0, right = 0; right < n; right++){
            sum += nums[right];

            while(sum >= target){
                minLen = min(minLen, right-left+1);
                sum -= nums[left];
                left++;
            }
        }

        while(sum > target && left < right){
            minLen = min(minLen, right-left+1);
            left++;
            sum -= nums[left];
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};