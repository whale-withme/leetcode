#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        return recurJump(nums, nums.size()-1);
    }

    bool recurJump(vector<int> &arr, int index){
        if(index == 0)
            return true;
        
        for(int i = index-1; i >= 0; i--){
            if(arr[i] >= index - i)
                return recurJump(arr, i);
        }
        return false;
    }
};