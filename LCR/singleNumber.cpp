#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ans = 0;
       
       for(int i = 0; i < 32; i++){
            int bit = 0;
            for(int num : nums){
                bit += (num >> i) & 0x1;
            }
            ans += (bit % 3) << i;     
       }
       return ans;
    }
};