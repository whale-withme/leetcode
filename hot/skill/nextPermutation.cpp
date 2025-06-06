#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1)    return ;
        
        int turn = -1, next = -1;
        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                turn = i;
                break;
            }
        }
        if(turn != -1){
            for(int i = nums.size()-1; i > turn; i--){
                if(nums[i] > nums[turn]){
                    next = i;
                    break;
                }
            }
        }
        
        if(turn != -1 && next != -1){
            swap(nums[turn], nums[next]);
            reverse(nums.begin()+turn+1, nums.end());
        }else{
            reverse(nums.begin(), nums.end());
        }
        
    }
};