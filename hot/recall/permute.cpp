#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<bool> used(n, false);
        vector<int> path;   // 不要初始化大小

        backtrack(nums, path, used, result);

        return result;
    }

    void backtrack(vector<int> &nums, vector<int> &path, vector<bool> &used, vector<vector<int>> &result){
        if(path.size() == nums.size()){
            result.push_back(path);
            return ;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;

            path.push_back(nums[i]);
            used[i] = true;

            backtrack(nums, path, used, result);

            path.pop_back();
            used[i] = false;
        }
    }

};