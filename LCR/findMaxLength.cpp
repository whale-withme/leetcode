#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map;
        int maxlen = 0, sum = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)
                nums[i] = -1;
        }

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == 0)
                maxlen = max(maxlen, i + 1);
            if(map.find(sum) != map.end()){
                maxlen = max(maxlen, i - map[sum]);
            }else{
                map[sum] = i;
            }
        }

        return maxlen;
    }
};

int main(){
    Solution so;
    vector<int> nums = {0,1,0};
    cout << so.findMaxLength(nums);
}