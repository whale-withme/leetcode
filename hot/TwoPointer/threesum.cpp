/*
三树之和：
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
*/
/**
 * koko：用哈希表还是没解决边界问题，对双指针的理解还不够
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> ans;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); i++) {
                // 去重：如果当前数字和前一个相同，则跳过
                if (i > 0 && nums[i] == nums[i - 1]) continue;
    
                int left = i + 1, right = nums.size() - 1;
                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
    
                    if (sum == 0) { // 找到三元组
                        ans.push_back({nums[i], nums[left], nums[right]});
    
                        // 跳过相同的 left 元素，避免重复答案
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // 跳过相同的 right 元素，避免重复答案
                        while (left < right && nums[right] == nums[right - 1]) right--;
    
                        left++;
                        right--;
                    } 
                    else if (sum < 0) { // 让 sum 增大
                        left++;
                    } 
                    else { // 让 sum 减小
                        right--;
                    }
                }
            }
    
            return ans;
        }
};