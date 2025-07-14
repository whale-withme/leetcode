#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(!k)  return 0;
        int dot = 1, n = nums.size(), cnt = 0;

       for(int right = 0, left = 0; right < n; right++){
            dot *= nums[right];

            while(dot >= k && left <= right){
                left++;
                dot /= nums[left];
            }

            cnt += right - left +1;
       } 

        return cnt;
    }
};