#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int half = n/2, ans = 0;
        unordered_map<int, int> map;

        for(int num: nums){
            map[num]++;
            if(map[num] > half){
                ans = num;
                break;
            }  
        }
        return ans;
    }
};