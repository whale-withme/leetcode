#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 左右前缀后缀相乘，计算
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> pre, ans;
        vector<int> back(size, 0);

        for(int i = 0; i < size; i++){
            if(i == 0) pre.push_back(nums[0]);
            else{
                pre.push_back(pre[i-1] * nums[i]);
            }
        }

        for(int i = size-1; i >= 0; i--){
            if(i == size-1) back[i] = nums[i];
            else{
                back[i] = back[i+1] * nums[i];
            }
        }

        for(int i = 0; i < size; i++){
            if(i == 0)  ans.push_back(back[i+1]);
            else if(i == size-1) ans.push_back(pre[i-1]);
            else ans.push_back(pre[i-1] * back[i+1]);
        }
        return ans;
    }
};