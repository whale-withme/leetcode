#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        /**
         * 跳过了所有的负数和超出数组长度的
         */
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1){
                return i == 0 ? 1 : nums[i-1]+1;
            }
        }
        return nums[nums.size()-1]+1;
    }
};