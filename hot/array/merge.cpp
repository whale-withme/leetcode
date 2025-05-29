#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    static bool cmp(vector<int> &m, vector<int> &n){
        return m[0] < n[0]; //不要写等号
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        
        for(int i = 0; i < intervals.size(); i++){
            int first = intervals[i][0], second = intervals[i][1];
            bool flag = true;
            
            if(ans.size() == 0 || ans.back()[1] < first)
                ans.push_back({first, second});
            else{
                ans.back()[1] = max(second, ans.back()[1]);
            }
        }

        return ans;
    }
};