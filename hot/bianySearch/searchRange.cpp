#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if(it != nums.end() && *it == target){
            ans.push_back(it-nums.begin());
            auto next = upper_bound(nums.begin(), nums.end(), target);
            if(next != nums.end()){
                ans.push_back(next-nums.begin()-1);
            }
            else{
                ans.push_back(nums.size()-1);
            }
        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
        }

        return ans;
    }
};