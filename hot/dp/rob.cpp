#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> f(nums.size()+1);
        f[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0)
                f[i+1] = nums[i];
            else{
                f[i+1] = max(f[i-1]+nums[i], f[i]);
            }
        }

        return f[nums.size()];
    }
};