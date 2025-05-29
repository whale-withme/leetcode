/*
两数之和：
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  
的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int left = target - nums[i];

            for(int j = 0; j < len && j != i; j++){
                if( nums[j] == left){
                    ans.push_back(j);
                    ans.push_back(i);
                    return ans;
                }     
            }
        }
        return ans;
    }
};

int main(){
    Solution so;
    vector<int> num = {3, 2, 4};
    
    vector<int> ans = so.twoSum(num, 6);
    std::cout << ans[0] << " " << ans[1] << std::endl;
}