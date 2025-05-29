/*

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> minpath(nums.size(), INT_MAX);
        minpath[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            int path = nums[i];
            
            for(int j = i+1; j <= i+nums[i] && j < nums.size(); j++){
                minpath[j] = min(minpath[j], minpath[i]+1);
            }
        }
        return minpath[nums.size()-1];
    }
};