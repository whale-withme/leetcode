/*
给定两个数组 nums1 和 nums2 ，返回 它们的 
交集。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
*/

// 关注怎么去重
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        unordered_map<int, int> map;
        vector<int> ans;

        for(int i = 0; i < len1; i++)
            map[nums1[i]] = 0;

        for(int i = 0; i < len2; i++){
            if(map.find(nums2[i]) != map.end())
                map[nums2[i]] = 1;
        }

        for(const auto it: map){
            if(it.second == 1)
                ans.emplace_back(it.first);
        }
        return ans;
    }
};