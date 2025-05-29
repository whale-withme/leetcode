/*
移动零：
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, j = 0; j < nums.size(); i++, j++){
            if(nums[i] != 0)
                continue;

            j = i;
            while(nums[j] == 0 && j < nums.size()){
                if(j == nums.size() - 1)
                    return ;
                j++;
            }
            swap(nums[i], nums[j]);
        }
    }
};

int main(){
    Solution so;
    vector<int>  nums = {0,1,0,3,12};
    so.moveZeroes(nums);
    for(int& num : nums)
        std::cout << num << " " ;
}