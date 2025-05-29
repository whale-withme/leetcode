/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组是数组中的一个连续部分。
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0;
        int ans = 0, sum = 0;
        while(i < nums.size()){
            if(sum >= 0){
                sum += nums[i];
                ans = max(ans, sum);
            }
            else{
                sum = nums[i];
                ans = max(ans, sum); 
            }
            i++;
        }

        return ans;
    }
};