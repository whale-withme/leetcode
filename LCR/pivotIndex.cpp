#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, pre = 0, index = -1;

        for(int num: nums)
            sum += num;

        for(int i = 0; i < nums.size(); i++){
            if(pre == sum - nums[i] - pre){
                index = i;
                break;
            }       
            pre += nums[i];
        }
        return index;
    }
};