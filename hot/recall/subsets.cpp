#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;

        backtrack(nums, result, path, 0);
        return result;
    }

    void backtrack(vector<int> &nums, vector<vector<int>> &result, vector<int> path, int startIndex){
        result.push_back(path);

        for(int i = startIndex; i < nums.size(); i++){
            path.push_back(nums[i]);

            backtrack(nums, result, path, i+1);

            path.pop_back();

        }
    }
};