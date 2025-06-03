#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 维护的<low >high 部分都是整理好的（注意边界），中间的待整理，如果从high之后交换回来的还需要再次检查
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size()-1;

        for(int i = 0; i < high;){
            if(nums[i] == 0){
                swap(nums[i], nums[low]);
                low++;
                i++;
            }else if(nums[i] == 1){
                i++;
            }else if(nums[i] == 2){
                swap(nums[i], nums[high]);
                high--;
            }
        }
    }
};