#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        if(nums.size() < 3)  return ans;

        for(int i = 0; i < nums.size(); i++){
            if(i && nums[i] == nums[i-1])
                continue;

            int l = i+1, r = nums.size()-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(!sum){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    l++, r--;
                }
                else if(sum < 0)    l++;
                else if(sum > 0)    r--;
            }
        }
        return ans;
    }
};