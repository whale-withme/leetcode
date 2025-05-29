#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // 没有优化二分方法
    int findMin(vector<int>& nums) {

        if(nums.size() == 1)    return nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1])
                return nums[i];
        }
        return nums[0];
    }
};