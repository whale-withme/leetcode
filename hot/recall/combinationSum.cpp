#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(candidates, target, result, path, 0);
        return result;
    }

    void backtrack(vector<int>& candidate, int target, vector<vector<int>>& result, vector<int> path, int start){
        if(target == 0){
            result.push_back(path);
            return ;
        }else if(target < 0)
            return ;

        for(int i = start; i < candidate.size(); i++){
            int num = candidate[i];
            path.push_back(num);
            // target -= num;
            backtrack(candidate, target-num, result, path, i);
            path.pop_back();
        }
    }
};